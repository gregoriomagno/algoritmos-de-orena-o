#include "vetor.h"
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
int vetor::NAleatorio(int maxi){
    int y = rand()%maxi;
    return y;
}
void vetor::preencher(int* p, int t, int tipo){
 srand(time(NULL));
		for(int x=0;x<t;x++){
			if(tipo == 1){
                            
				*(p+x)=x+1;
			}
			else if(tipo==2){
				*(p+x)=t-x;
                               
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
					*(p+x)=num;
				}
				
			}
		}   
}
vetor::vetor(int t,int tipo){
    int vet[t];
    tamanho=t;
    preencher(v,t,tipo);
    
    
}
vetor::~vetor(){
    
}
void vetor::show(){
    printf("vetor t = %d: \n(",tamanho);
		for(int y=0;y<tamanho;y++){
                    
			printf("%d  ",*(v+y));
		}
		printf(")\n");
}
