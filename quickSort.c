//Referencia: SILVA, André Backes. Linguagem C: Completa e Descomplicada. São Paulo: Editora XYZ, 2023.
#include "randomArray.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ARRAY_SIZE 10000

void printfVet(int *V  , int N){
    int i;
    for(i = 0; i < N; i++)
        printf("%d: %d\n",i, V[i]);
    printf("\n");
}


int particiona(int *V, int inicio, int final ){
    int esq, dir, pivo, aux;
    esq = inicio;
    dir = final;
    pivo = V[inicio];
    while(esq < dir){
        while(esq <= final && V[esq] <= pivo)
            esq++;

        while(dir >= 0 && V[dir] > pivo)
            dir--;

        if(esq < dir){
            aux = V[esq];
            V[esq] = V[dir];
            V[dir] = aux;
        }
    }
    V[inicio] = V[dir];
    V[dir] = pivo;
    return dir;
}

void quickSort(int *V, int inicio, int fim) {
    int pivo;
    if(fim > inicio){
        pivo = particiona(V, inicio, fim);
        quickSort(V, inicio, pivo-1);
        quickSort(V, pivo+1, fim);
    }
}

int main(){
    int vet[ARRAY_SIZE];
    
    generateRandomValues(vet,ARRAY_SIZE);

    printf("Vetor desordenado:\n");
    printfVet(vet,ARRAY_SIZE);
   

    quickSort(vet,0,ARRAY_SIZE-1);

    printf("Vetor Ordenado:\n");
    printfVet(vet,ARRAY_SIZE);

    system("pause");
    return 0;
}