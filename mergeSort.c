/*
Merge Sort:

- Ideia básica: Dividir pra conquistar
- Divide, recursivamente, o conjunto de dados até que cada subconjunto possua 1 elemento
- Combina 2 subconjuntos de forma a obter 1 conjunto maior e ordenado
- Esse processo se repete até que exista apenas 1 conjunto

  -> PERFORMANCE:
    - Melhor Caso: O(N log N)
    - Pior Caso: O(N log N)
    - Estável: Não altera a ordedm de dados iguais
    - Desvantagens: recursivo e usa um vetor auxiliar durante a ordenação

Referencia: SILVA, André Backes. Linguagem C: Completa e Descomplicada. São Paulo: Editora XYZ, 2023.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define TAM_VETOR 10
void mergeSort(int *V , int inicio , int fim);
void merge (int *V, int inicio, int meio, int fim);

int main(){

    int conjuntoDesordenado[TAM_VETOR] = {10,2,3,7,18,-2,49,22,12,1};
    int i;

    printf("Vetor desordenado:\n");
    for ( i = 0; i < TAM_VETOR; i++){
        printf("%d: %d\n",i,conjuntoDesordenado[i]);
    }
    printf("\n");
    mergeSort(conjuntoDesordenado,0,TAM_VETOR);

    printf("Vetor ordenado:\n");
    for ( i = 0; i < TAM_VETOR; i++){
        printf("%d: %d\n",i,conjuntoDesordenado[i]);
    }
    
    return 0;
}

void mergeSort(int *V , int inicio , int fim){
		int meio;
        if (inicio < fim){
            meio = floor((inicio + fim) / 2);
            mergeSort(V, inicio, meio);
            mergeSort(V, meio+1, fim);
            merge(V,inicio,meio,fim);
        }
}

void merge (int *V, int inicio, int meio, int fim){
    int* temp, p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0;
    tamanho = fim - inicio + 1;
    p1 = inicio;
    p2 = meio + 1;
    temp = (int*) malloc (tamanho * sizeof(int));
    if(temp != NULL){
        for(i = 0; i < tamanho; i++){
            if(!fim1 && !fim2){
                if(V[p1] < V[p2])
                    temp[i] = V[p1++];
                else
                    temp[i] = V[p2++];
                if(p1 > meio) fim1 = 1;
                if(p2 > fim) fim2 = 1;        
            }else{
                if(!fim1)
                    temp[i] = V[p1++];
                else
                    temp[i] = V[p2++];    
            }
        }
        for(j = 0, k = inicio ; j < tamanho ; j++ , k++)
            V[k] = temp[j];
        
    }
    free(temp);
}