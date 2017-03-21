#include <stdio.h>
#include <stdlib.h>

struct treeNode{
 int data;
 struct treeNode *leftTreeNode;
 struct treeNode *rightTreeNode;
};
typedef struct treeNode TreeNode;
typedef struct treeNode *TreeNodePointer;

void insertTreeNode( TreeNodePointer *treeNodePointer, int data );

void inorderTravelsal( TreeNodePointer treeNodePointer );
void preorderTravelsal( TreeNodePointer treeNodePointer );
void postorderTravelsal( TreeNodePointer treeNodePointer );

TreeNodePointer deleteNode( TreeNodePointer treeNodePointer, int data );
void deleteTreeNode( TreeNodePointer *treeNodePointer, int data );



int main( void ){
 //Invoking insertTreeNode method
 TreeNodePointer root = NULL;
 insertTreeNode( &root, 55 );
 insertTreeNode( &root, 42 );
 insertTreeNode( &root, 33 );
 insertTreeNode( &root, 69 );
 insertTreeNode( &root, 57 );
 insertTreeNode( &root, 70 );
 insertTreeNode( &root, 75 );
 insertTreeNode( &root, 72 );
 //Invoking insertTreeNode method
 
 //Invoking inorderTravelsal method
 printf( "\nAfter invoking inorderTravelsal method...\n" );
 inorderTravelsal( root );
 printf( "\n" );
 //Invoking inorderTravelsal method

 //Invoking preorderTravelsal method
 printf( "\nAfter invoking preorderTravelsal method...\n" );
 preorderTravelsal( root );
 printf( "\n" );
 //Invoking preorderTravelsal method

 //Invoking postorderTravelsal method
 printf( "\nAfter invoking postorderTravelsal method...\n" );
 postorderTravelsal( root );
 printf( "\n" );
 //Invoking postorderTravelsal method

 //Invoking deleteTreeNode method
 printf( "\nAfter invoking deleteTreeNode method...\n" );
 deleteTreeNode( &root, 70 );
 printf( "\nAfter invoking inorderTravelsal method...\n" );
 inorderTravelsal( root );
 printf( "\n" );
 //Invoking deleteTreeNode method

}

void insertTreeNode( TreeNodePointer *treeNodePointer, int data ){
 if( *treeNodePointer == NULL ){
  *treeNodePointer = ( TreeNodePointer )malloc( sizeof( TreeNode ) );
  if( *treeNodePointer != NULL ){
   ( *treeNodePointer )->data = data;
   ( *treeNodePointer )->leftTreeNode = NULL;
   ( *treeNodePointer )->rightTreeNode = NULL;
  }
  else{
   printf( "There is no memory space for for adding a new record...\n" );
   exit( EXIT_FAILURE );
  }
 }
 else{
  if( data < ( *treeNodePointer )->data ){
   insertTreeNode( &( ( *treeNodePointer )->leftTreeNode ), data );
  }
  else if( data > ( *treeNodePointer )->data ){
   insertTreeNode( &( ( *treeNodePointer )->rightTreeNode ), data );
  }
  else{
   printf( "Duplicate records are not allowed...\n" );
  } 
 }
}

void inorderTravelsal( TreeNodePointer treeNodePointer ){
 if( treeNodePointer != NULL ){
  inorderTravelsal( treeNodePointer->leftTreeNode );
  printf( "%-5d", treeNodePointer->data );
  inorderTravelsal( treeNodePointer->rightTreeNode ); 
 }
}
void preorderTravelsal( TreeNodePointer treeNodePointer ){
 if( treeNodePointer != NULL ){
  printf( "%-5d", treeNodePointer->data );
  preorderTravelsal( treeNodePointer->leftTreeNode );
  preorderTravelsal( treeNodePointer->rightTreeNode );
 }
}
void postorderTravelsal( TreeNodePointer treeNodePointer ){
 if( treeNodePointer != NULL ){
  postorderTravelsal( treeNodePointer->leftTreeNode );
  postorderTravelsal( treeNodePointer->rightTreeNode );
  printf( "%-5d", treeNodePointer->data );
 }
}

TreeNodePointer deleteNode( TreeNodePointer treeNodePointer, int data ){
 if( treeNodePointer == NULL ){
  return treeNodePointer;
 }
 if( data < treeNodePointer->data ){
  treeNodePointer->leftTreeNode = deleteNode( treeNodePointer->leftTreeNode, data );
 }
 else if( data > treeNodePointer->data ){
  treeNodePointer->rightTreeNode = deleteNode( treeNodePointer->rightTreeNode, data );
 }
 else{
  if( treeNodePointer->leftTreeNode == NULL ){
   TreeNodePointer temporaryTreeNodePointer = treeNodePointer->rightTreeNode;
   free( treeNodePointer );
   return temporaryTreeNodePointer;
  }
  else if( treeNodePointer->rightTreeNode == NULL ){
   TreeNodePointer temporaryTreeNodePointer = treeNodePointer->leftTreeNode;
   free( treeNodePointer );
   return temporaryTreeNodePointer;
  }
  else{
   TreeNodePointer temporaryTreeNodePointer = treeNodePointer->rightTreeNode;
   while( temporaryTreeNodePointer->leftTreeNode != NULL ){
    temporaryTreeNodePointer = temporaryTreeNodePointer->leftTreeNode;
   }
   treeNodePointer->data = temporaryTreeNodePointer->data;
   treeNodePointer->rightTreeNode = deleteNode( treeNodePointer->rightTreeNode, temporaryTreeNodePointer->data );
  } 
 }
 return treeNodePointer;
}
void deleteTreeNode( TreeNodePointer *treeNodePointer, int data ){
 if( *treeNodePointer != NULL ){
  TreeNodePointer currentTreeNodePointer = *treeNodePointer;
  while( currentTreeNodePointer != NULL && currentTreeNodePointer->data != data ){
   if( data < currentTreeNodePointer->data ){
    currentTreeNodePointer = currentTreeNodePointer->leftTreeNode;
   }
   else if( data > currentTreeNodePointer->data ){
    currentTreeNodePointer = currentTreeNodePointer->rightTreeNode;
   }
  }
  if( currentTreeNodePointer != NULL ){
   deleteNode( *treeNodePointer, data );
  }
  else{
   printf( "The record with the key %d was not found...\n", data );
  }
 }
}
