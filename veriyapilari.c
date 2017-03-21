#include <stdio.h>
#include <stdlib.h>

int j = 0, j2 = 0,k, toplamYol, durum[10001]={0},durum2[10001]={0}, yol[10001],yol2[10001],yedek[100001],eb = 0,n,m,basi=1;

struct komsular{
	int numara;
	struct komsular *next;
};

struct sehir{
	struct komsular *ilk;
};

struct harita{
	int sehirSayisi;
	struct sehir* dizi;
};


struct harita *haritaOlustur(int sehirSayisi){
	struct harita* hrta = malloc(sizeof(struct harita));
	hrta->sehirSayisi = sehirSayisi;
	
	hrta->dizi = malloc((sehirSayisi +1) * sizeof(struct sehir));
	
	int i = 0;
	for(;i<sehirSayisi;i++)
		hrta->dizi[i].ilk = NULL;
	return hrta;
}

struct komsular* yeniKomsu(int numara){
	struct komsular* yeniKomsu = malloc(sizeof(struct komsular));
	yeniKomsu->next = NULL;
	yeniKomsu->numara = numara;
	return yeniKomsu;
}
//kenar eklenir a yada d fark
void kenarEkle(struct harita* hrta, int numara2, int numara){
	struct komsular* yeniSehir = yeniKomsu(numara);
	yeniSehir->next = hrta->dizi[numara2].ilk;
	hrta->dizi[numara2].ilk = yeniSehir;

	yeniSehir = yeniKomsu(numara2);
	yeniSehir->next = hrta->dizi[numara].ilk;
	hrta->dizi[numara].ilk = yeniSehir;
}


void tumYollariBas(struct harita* g,int s, int d)
{
    	durum[s] = 1;
        yol[j++] = s;
        if(s == d){
            toplamYol++;
			if(eb<j)
				eb = j;
			int i = 0;
			printf("%d. yol ",basi++);
            for(; i<j; i++)
                printf("%c ",96 + yol[i]);
            printf("\n");
        }
        else{
            struct komsular *iter = g->dizi[s].ilk;
            while(iter){
                if(!durum[iter->numara] == 1)
                    tumYollariBas(g, iter->numara, d);
                iter = iter->next;
            }
        }
        j--;
        durum[s] = 0;
}

void ebbas(struct harita* g, int s, int d){
		durum2[s] = 1;
        yol2[j2++] = s;
        if(s == d){
            int i = 0;
			if(eb==j2){
				int f =0;
				for(; f<eb; f++)
					printf("%c ",yol2[f] + 96);
				printf("\n");
			}
        }
        else{
            struct komsular *iter = g->dizi[s].ilk;
            while(iter){
                if(!durum2[iter->numara] == 1)
                    ebbas(g, iter->numara, d);
                iter = iter->next;
            }
        }
        j2--;
        durum2[s] = 0;
}

int main(){
	char a,b;
	int i;
    printf("Max sehir sayisini girin: ");
    scanf("%d",&n);
    i=0;
    struct harita* g=haritaOlustur(n+1);
    kenarEkle(g,(int)'a'-96,(int)'b'-96);
    kenarEkle(g,(int)'a'-96,(int)'d'-96);
    kenarEkle(g,(int)'a'-96,(int)'f'-96);
    kenarEkle(g,(int)'a'-96,(int)'h'-96);
    kenarEkle(g,(int)'b'-96,(int)'c'-96);
    kenarEkle(g,(int)'b'-96,(int)'r'-96);
    kenarEkle(g,(int)'b'-96,(int)'j'-96);
    kenarEkle(g,(int)'b'-96,(int)'i'-96);
    kenarEkle(g,(int)'c'-96,(int)'r'-96);
    kenarEkle(g,(int)'c'-96,(int)'q'-96);
    kenarEkle(g,(int)'c'-96,(int)'d'-96);
    kenarEkle(g,(int)'d'-96,(int)'p'-96);
    kenarEkle(g,(int)'d'-96,(int)'q'-96);
    kenarEkle(g,(int)'d'-96,(int)'e'-96);
    kenarEkle(g,(int)'e'-96,(int)'p'-96);
    kenarEkle(g,(int)'e'-96,(int)'n'-96);
    kenarEkle(g,(int)'e'-96,(int)'f'-96);
    kenarEkle(g,(int)'f'-96,(int)'n'-96);
    kenarEkle(g,(int)'f'-96,(int)'m'-96);
    kenarEkle(g,(int)'f'-96,(int)'g'-96);
    kenarEkle(g,(int)'g'-96,(int)'m'-96);
    kenarEkle(g,(int)'g'-96,(int)'l'-96);
    kenarEkle(g,(int)'g'-96,(int)'h'-96);
    kenarEkle(g,(int)'h'-96,(int)'l'-96);
    kenarEkle(g,(int)'h'-96,(int)'k'-96);
    kenarEkle(g,(int)'h'-96,(int)'i'-96);
    kenarEkle(g,(int)'i'-96,(int)'k'-96);
    kenarEkle(g,(int)'i'-96,(int)'j'-96);	
    kenarEkle(g,(int)'s'-96,(int)'f'-96);
    kenarEkle(g,(int)'s'-96,(int)'m'-96);
    kenarEkle(g,(int)'s'-96,(int)'n'-96);
	toplamYol=0;
    

    char x,y;
    printf("lutfen hangi sehirden hangi sehire gidecegini belirt: ");
    scanf("\n%c %c",&x,&y);
    tumYollariBas(g,x - 96,y - 96);
    printf("toplam yol sayisi: %d\n",toplamYol);
    printf("\nen uzun yol(lar)\n");
	ebbas(g,x-96,y-96);
    
    return 0;
}
