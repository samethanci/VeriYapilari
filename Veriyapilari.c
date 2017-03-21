#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 324
 
// Graph için her bir düðüme Vertex dedik.
struct Vertex {
  int key;
  char val;
  char color; // W: White, g: Grey, b: Black
  int distance; // Bu dugumun, BFSe gonderilen diger dugume uzakligi.
  int adjSize; // Komsu Sayisi
  struct Vertex* pred; // BFS
  struct AdjList* adjs; // Komsular
};
 
// Dugumun komsularini tutacagiz
struct AdjList {
  struct Vertex* vertex;
};
 
// Graph icindeki dugulmeri tutacagimiz liste
struct VertexList {
  struct Vertex* vertex;
};
 
// Graph yapisi
struct Graph {
  int size;
  struct VertexList* array;
};
 
// Graphe yeni bir dugum eklemek icin..
struct Vertex* addVertex(struct Graph* graph, int key, char val){
  struct Vertex* newNode = (struct Vertex*) malloc(sizeof(struct Vertex));
  newNode->key = key;
  newNode->val = val;
  newNode->color = 'w';
  newNode->distance = 0;
  newNode->adjSize = 0;
  newNode->pred = NULL;
  newNode->adjs = (struct AdjList*) malloc(graph->size * sizeof(struct AdjList));
 
  int i;
  for (i = 0; i < graph->size; ++i)
    newNode->adjs[i].vertex = NULL;
 
  graph->array[key].vertex = newNode;
  return newNode;
}
 
// Dugumler arasi komsuluk iliski olusturmak icin.
void addEdge(struct Graph* graph, int src, int dest){
 
  int i;
  int state = 0;
  // src keyli dugume dest keyli dugumu komsu ekliyoruz
  for(i = 0; i < graph->size; i++){
    if(graph->array[src].vertex->adjs[i].vertex == NULL){
      graph->array[src].vertex->adjs[i].vertex = graph->array[dest].vertex;
      graph->array[src].vertex->adjSize = graph->array[src].vertex->adjSize +1;
      break;
    }else{
      // Daha once komsuluk iliskisi kurulmus ayný elemanlar icin tekrar
      // kurulmamasý gerekiyor.
      if(graph->array[src].vertex->adjs[i].vertex->key == dest){
        state = 1;
        break;
      }
    }
  }
 
  // dest keyli düðüme src keyli dugumu komsu ekliyoruz
  if(state == 0){
    for(i = 0; i < graph->size; i++){
      if(graph->array[dest].vertex->adjs[i].vertex == NULL){
        graph->array[dest].vertex->adjs[i].vertex = graph->array[src].vertex;
        graph->array[dest].vertex->adjSize = graph->array[dest].vertex->adjSize +1;
        break;
      }
    }
    // printf("%c ve %c arasinda kenar olusturuldu \n",
    // graph->array[src].vertex->val, graph->array[dest].vertex->val);
  }else{
    printf("%c ve %c arasinda daha once kenar olusturulmus. O nedenle kenar olusturulmadi. \n",
    graph->array[src].vertex->val, graph->array[dest].vertex->val);
  }
 
}
 
// Graph ilkledigimiz fonksiyon.
struct Graph* createGraph(int size){
  struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
  graph->size = size;
 
  graph->array = (struct VertexList*) malloc(size * sizeof(struct VertexList));
 
   // Arraydeki tum degerleri null yaparak her bir vertex elemanini bos olarak ilkliyoruz.
  int i;
  for (i = 0; i < size; ++i)
    graph->array[i].vertex = NULL;
 
  return graph;
}
 
// Bir dugumun komsularini listeleyen fonksiyon
void listNeighbors(struct Graph* graph, int key){
  int i;
  printf("%c 'den gidilebilecek yerler: \n", graph->array[key].vertex->val);
  for(i = 0; i < graph->size; i++){
    if(graph->array[key].vertex->adjs[i].vertex != NULL){
      printf("%c | ",graph->array[key].vertex->adjs[i].vertex->val);
    }else{
      printf("\n");
      break;
    }
  }
}
 
// Graph icindeki tum dugumleri key, value, renk, uzaklik, onceki dugum gibi
// bilgileri listeleyebilecegimiz yardimci fonksiyon.
void printVertex(struct Graph* graph){
  int v;
  for (v = 0; v < graph->size; ++v) {
    struct Vertex* pCrawl = graph->array[v].vertex;
    if(pCrawl->pred != NULL){
      printf("Key: %d Value: %c Color: %c Distance: %d Pred: %c \n",
        v, pCrawl->val, pCrawl->color, pCrawl->distance, pCrawl->pred->val);
    }else{
      printf("Key: %d Value: %c Color: %c Distance: %d Pred: NULL \n",
        v, pCrawl->val, pCrawl->color, pCrawl->distance);
    }
 
    listNeighbors(graph, pCrawl->key);
  }
}
 
 
/**
  DFS algoritmasi ile tum yollari bulacagiz.
  Tüm yollarý bulmak için recursive bir fonksiyon yazacagiz. Bu fonksiyon
  icinde cikmaz yol oldugunda bir onceki dugumden devam etmesi gerekeceginden
  basitçe bir stack veri yapisina ihtiyac var. Bir diziden turetecegiz.
*/
 
 
int stack[MAXSIZE];
int top = -1;
int pathNo = 1;
int longestWay[2] = {0,0};
 
 
void initStack(){
  int x = 0;
  for(x;x<MAXSIZE;x++)
    stack[x] = -1;
}
 
int isempty() {
  if(top == -1)
    return 1;
  else
    return 0;
}
 
int isfull() {
  if(top == MAXSIZE)
    return 1;
  else
    return 0;
}
 
int peek() {
  return stack[top];
}
 
int pop() {
  int data;
 
  if(!isempty()) {
    data = stack[top];
    stack[top] = -1;
    top = top - 1;
    return data;
  }else {
    printf("Stack bos, veri cekilemez..\n");
  }
}
 
int push(int data) {
  if(!isfull()) {
    top = top + 1;
    stack[top] = data;
  }else {
    printf("Stack Dolu, veri eklenemez.\n");
  }
}
 
// Yolu ekrana yazan fonksiyon. (stack icindeki keylere gore.)
void printWay(struct Graph* graph, int lastKey){
  int i = 0;
  printf("PathNo: %d \t",pathNo);
 
  while(stack[i] != lastKey){
    printf("%c -->",graph->array[stack[i]].vertex->val);
    i++;
  }
  printf(" %c \n",graph->array[lastKey].vertex->val);
  if(i > longestWay[0]){
    longestWay[0] = i;
    longestWay[1] = pathNo;
  }
  pathNo++;
}
 
// DFS algoritmasi.
void findAllPaths(struct Graph* graph, int from, int to){
  int i = 0;
  int j;
  struct Vertex* v = graph->array[from].vertex;
  v->color = 'g';
  push(from);
 
  if(from == to){
    printWay(graph, to);
  }else{
    for(j = 0; j < v->adjSize; j++){
      struct Vertex* w = v->adjs[j].vertex;
      if(w->color == 'w'){
        findAllPaths(graph, w->key, to);
      }
    }
  }
 
  pop();
  v->color = 'w';
}
 
void findAllWay(struct Graph* graph, int from, int to){
  initStack();
  findAllPaths(graph, from, to);
  printf("\nNumber Of path/paths from %c to %c: %d \n",
    graph->array[from].vertex->val, graph->array[to].vertex->val, pathNo - 1);
  printf("One of the longest way is pathno: %d which it has %d node(s).\n",
    longestWay[1], longestWay[0]+1);
 
}
 
int main(){
  // 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17
  // A B C D E F G H I J K  L  M  N  0  P  Q  R
  int sizeOfCities = 18;
  struct Graph* graph = createGraph(sizeOfCities);
 
  // Dugumleri graphta olusturulmasi.
  int i;
  for(i = 0; i < sizeOfCities; i++)
    addVertex(graph, i, i+65);
 
  // Komsuluk iliskilerinin eklenmesi.
  addEdge(graph, 0, 1);   // A-B
  addEdge(graph, 0, 3);   // A-D
  addEdge(graph, 0, 5);   // A-F
  addEdge(graph, 0, 7);   // A-H
  addEdge(graph, 1, 2);   // B-C
  addEdge(graph, 1, 17);  // B-R
  addEdge(graph, 1, 9);   // B-J
  addEdge(graph, 1, 8);   // B-I
  addEdge(graph, 2, 16);  // C-R
  addEdge(graph, 2, 17);  // C-Q
  addEdge(graph, 2, 3);   // C-D
  addEdge(graph, 3, 16);  // D-Q
  addEdge(graph, 3, 15);  // D-P
  addEdge(graph, 3, 4);   // D-E
  addEdge(graph, 4, 15);  // E-P
  addEdge(graph, 4, 13);  // E-N
  addEdge(graph, 4, 5);   // E-F
  addEdge(graph, 5, 13);  // F-N
  addEdge(graph, 5, 12);  // F-M
  addEdge(graph, 5, 6);   // F-G
  addEdge(graph, 6, 12);  // G-M
  addEdge(graph, 6, 11);  // G-L
  addEdge(graph, 6, 7);   // G-H
  addEdge(graph, 7, 11);  // H-L
  addEdge(graph, 7, 10);  // H-K
  addEdge(graph, 7, 8);   // H-I
  addEdge(graph, 8, 10);  // I-K
  addEdge(graph, 8, 9);   // I-J
 
  findAllWay(graph, 6, 12);
 
}
