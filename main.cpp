#include <stdio.h>

#include <stdlib.h>
#include<time.h>
int NAleatorio(int maxi);
void show(int *p, int t);
void bubbleSort(int *p, int tamanho);
void selectionSort(int *p, int tamanho);
void preencher(int *p, int t, int tipo);
void povoar(int *p11, int *p12, int *p13, int *p21, int *p22, int *p23, int *p31, int *p32, int *p33, int *p41, int *p42, int *p43);
void show(int *p11, int *p12, int *p13, int *p21, int *p22, int *p23, int *p31, int *p32, int *p33, int *p41, int *p42, int *p43);

int main(void) {

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
    preencher(vet41, 10000, 1);
    povoar(vet11, vet12, vet13, vet21, vet22, vet23, vet31, vet32, vet33, vet41, vet42, vet43);
    //show(vet11,vet12,vet13,vet21,vet22,vet23,vet31,vet32,vet33,vet41,vet42,vet43);

    // --------------------------------------------------------------
    int t1 = 10;
    int t2 = 100;
    int t3 = 1000;
    show(vet13, t1);
    //show(vet41, 10000);
    bubbleSort(vet13, t1);
    show(vet13, t1);
    //selectionSort(vet12, t1);
    //show(vet12, t1);
    //selectionSort(vet13, t1);
    //show(vet13, t1);
    return 0;
}

void selectionSort(int *p, int tamanho) {
    int menor, aux;
    int trocas = 0;
    for (int x = 0; x < tamanho - 1; x++) {
        menor = x;
        for (int y = x + 1; y < tamanho; y++) {
            printf("menor = %d ; y=%d \n", p[menor], p[y]);

            if (p[y] < p[menor]) {
                printf("troca %d < %d\n", p[y], p[menor]);


                menor = y;

            }
        }
        //printf("----------- Menor %d \n",menor);
        //if (p[menor] != p[x]) {
        trocas++;
        aux = p[x];
        p[x] = p[menor];
        p[menor] = aux;
        // }
    }
    printf("N° de trocas %d \n", trocas);
}

void bubbleSort(int *p, int tamanho) {
    int aux;
    int maior;
    int trocas = 0;
    int compara = 0;
    for (int x = 0; x < tamanho; x++) {
        //printf("x = %d \t",x);
        maior=x;
        aux;
        for (int y = x+1; y < tamanho; y++) {
            // printf("x = %d \n",y);
            compara++;
            if (p[maior] > p[y]) {
                trocas++;
                aux = p[y];
                p[y]=p[maior];
                p[maior] = aux;
                
                
            } 
          
        }
       
    }
    printf("N° de trocas %d\t comparacoes %d \n", trocas, compara);
}
//funcao para preencher todos os vetores

void povoar(int *p11, int *p12, int *p13, int *p21, int *p22, int *p23, int *p31, int *p32, int *p33, int *p41, int *p42, int *p43) {
    preencher(p11, 10, 1);
    preencher(p12, 10, 2);
    preencher(p13, 10, 3);

    preencher(p21, 100, 1);
    preencher(p22, 100, 2);
    preencher(p23, 100, 3);

    preencher(p31, 1000, 1);
    preencher(p32, 1000, 2);
    preencher(p33, 1000, 3);

    preencher(p41, 10000, 1);
    preencher(p42, 10000, 2);
    preencher(p43, 10000, 3);

}
//funcao para mostrar todos os vetores

void show(int *p, int t) {
    printf("vetor t = %d: \n(", t);
    for (int y = 0; y < t; y++) {
        printf("%d,", p[y]);
    }
    printf(")\n");
}

void show(int *p11, int *p12, int *p13, int *p21, int *p22, int *p23, int *p31, int *p32, int *p33, int *p41, int *p42, int *p43) {
    show(p11, 10);
    show(p12, 10);
    show(p13, 10);

    show(p21, 100);
    show(p22, 100);
    show(p23, 100);

    show(p31, 1000);
    show(p32, 1000);
    show(p33, 1000);

    show(p41, 10000);
    //show(p42,10000);
    //show(p43,10000);
}
// funcao para gerar numeros aleatorios

int NAleatorio(int maxi) {
    int y = rand() % maxi;
    return y;
}
//funcao para preencher o vetor com certo tipo de organizacao dos dados
// tipo ( 1 - ordenado ; 2 - desordenado invertido ; 3 - desordenado aleatorio 

void preencher(int *p, int t, int tipo) {
    //srand(time(NULL));
    srand(10);
    for (int x = 0; x < t; x++) {
        if (tipo == 1) {
            p[x] = x + 1;
        } else if (tipo == 2) {
            p[x] = t - x;
        } else if (tipo == 3) {

            bool add = true;
            int num = NAleatorio(t * 10);
            for (int k = 0; k < x; k++) {
                if (num == p[k]) {

                    x--;
                    k = x;
                    add = false;
                }
            }
            if (add) {
                p[x] = num;
            }

        }
    }


}