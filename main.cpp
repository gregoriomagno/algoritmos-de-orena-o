#include <stdio.h>

#include <stdlib.h>
#include<time.h>
int NAleatorio(int maxi);
void show(int *p,int t);
void bubbleSort(int *p,int tamanho);
void preencher(int *p,int t,int tipo);
void povoar(int *p11,int *p12,int *p13,int *p21,int *p22,int *p23,int *p31,int *p32,int *p33,int *p41,int *p42,int *p43);
void show(int *p11,int *p12,int *p13,int *p21,int *p22,int *p23,int *p31,int *p32,int *p33,int *p41,int *p42,int *p43);
int main(void){
	
	//vetXY : X-tamanho do vetor ; Y - tipo de organizacao dos dados
	//X ( 1- tamanho 10 ; 2 - tamanho 100 ; 3 - tamanho 1000 ; 4 - tamanho 10000)
	// y ( 1 - ordenado ; 2 - desordenado invertido ; 3 - desordenado aleatorio 
	
	//vetores com tamanho 10 
	int vet11[10];
	int vet12[10];
	int vet13[10];
	//vetores com tamanho 100
	int vet21[100];
	int vet22[100];
	int vet23[100];
	//vetores com tamanho 1000
	int vet31[1000];
	int vet32[1000];
	int vet33[1000];

	//vetores com tamanho 1000
	int vet41[10000];
	int vet42[10000];
	int vet43[10000];	
	
	povoar(vet11,vet12,vet13,vet21,vet22,vet23,vet31,vet32,vet33,vet41,vet42,vet43);
	//show(vet11,vet12,vet13,vet21,vet22,vet23,vet31,vet32,vet33,vet41,vet42,vet43);
	
        // --------------------------------------------------------------
        //show(vet12,10);
        bubbleSort(vet21,100);
        show(vet21,100);
        bubbleSort(vet22,100);
        show(vet22,100);
        bubbleSort(vet23,100);
        show(vet23,100);
        return 0;
}
void bubbleSort(int *p,int tamanho){
    int aux;
    int trocas =0;
    for(int x=tamanho;x>0;x--){
        //printf("x = %d \t",x);
        aux=p[0];
        for(int y=1;y<tamanho;y++){
           // printf("x = %d \n",y);
            if(aux>p[y]){
                //printf("troca %d > %d\n",aux,p[y]);
                trocas++;
                p[y-1]=p[y];
                p[y]=aux;
            }
            else{
                //printf("passa %d > ",aux);
                aux=p[y];
                //printf("%d \n",aux);
            }
        }
    }
    printf("N° de trocas %d\n",trocas);
}
//funcao para preencher todos os vetores
void povoar(int *p11,int *p12,int *p13,int *p21,int *p22,int *p23,int *p31,int *p32,int *p33,int *p41,int *p42,int *p43){
	preencher(p11,10,1);
	preencher(p12,10,2);
	preencher(p13,10,3);
	
	preencher(p21,100,1);
	preencher(p22,100,2);
	preencher(p23,100,3);
		
	preencher(p31,1000,1);
	preencher(p32,1000,2);
	preencher(p33,1000,3);
	
	preencher(p41,10000,1);
	preencher(p42,10000,2);
	preencher(p43,10000,3);
	
}
//funcao para mostrar todos os vetores
void show(int *p,int t){
		printf("vetor t = %d: \n(",t);
		for(int y=0;y<t;y++){
			printf("%d  ",p[y]);
		}
		printf(")\n");
}
void show(int *p11,int *p12,int *p13,int *p21,int *p22,int *p23,int *p31,int *p32,int *p33,int *p41,int *p42,int *p43){
	show(p11,10);
	show(p12,10);
	show(p13,10);
	
	show(p21,100);
	show(p22,100);
	show(p23,100);
	
	show(p31,1000);
	show(p32,1000);
	show(p33,1000);
	
	show(p41,10000);
	//show(p42,10000);
	//show(p43,10000);
}
// funcao para gerar numeros aleatorios
int NAleatorio(int maxi){
	int y = rand()%maxi;
	return y;
}
//funcao para preencher o vetor com certo tipo de organizacao dos dados
// tipo ( 1 - ordenado ; 2 - desordenado invertido ; 3 - desordenado aleatorio 
void preencher(int *p,int t,int tipo){
		//srand(time(NULL));
    srand(10);
		for(int x=0;x<t;x++){
			if(tipo == 1){
				p[x]=x+1;
			}
			else if(tipo==2){
				p[x]=t-x;
			}
			else if(tipo ==3){
				
				bool add=true;
				int num = NAleatorio(t*10);
				for(int k=0;k<x;k++){
					if(num ==p[k]){
						
						x--;
						k=x;
						add=false;
					}
				}
				if(add){
					p[x]=num;
				}
				
			}
		}
	
	
}