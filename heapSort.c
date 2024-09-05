//Referencia: SILVA, André Backes. Linguagem C: Completa e Descomplicada. São Paulo: Editora XYZ, 2023.
#define ARRAY_SIZE 10000
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "randomArray.h"

void printfVet(int *V  , int N){
    int i;
    for(i = 0; i < N; i++)
        printf("%d: %d\n",i, V[i]);
    printf("\n");
}

void criaHeap(int *vet, int i, int f){
    int aux = vet[i];
    int j = i * 2 + 1;
    while (j <= f){
        if(j < f){
            if(vet[j] < vet[j + 1]){
                j = j + 1;
            }
        }
        if(aux < vet[j]){
            vet[i] = vet[j];
            i = j;
            j = 2 * i + 1;
        }else{
            j = f + 1;
        }
    }
    vet[i] = aux;
}

void heapSort(int *vet, int N){
    int i, aux;
    for(i=(N - 1)/2; i >= 0; i--){
        criaHeap(vet, i, N-1);
    }
    for (i = N-1; i >= 1; i--){
        aux = vet[0];
        vet [0] = vet [i];
        vet [i] = aux;
        criaHeap(vet, 0, i - 1);
    }
}


int main(){

    int vet[ARRAY_SIZE];
    generateRandomValues(vet,ARRAY_SIZE);

   
    printf("Vetor desordenado:\n");
    printfVet(vet,ARRAY_SIZE);
 

    heapSort(vet,ARRAY_SIZE);


   printf("Vetor Ordenado:\n");
    printfVet(vet,ARRAY_SIZE);

    system("pause");
    return 0;
}

