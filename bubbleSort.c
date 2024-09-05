/*
Bubble Sort:

- Compara pares de elementos adjacentes e os troca de lugar se estiverem na ordem errada.

- Esse processo se repete até que mais nenhuma troca seja necessária ( elementos já ordenados ).

- No final de cada iteração, o maior valor do conjunto atual de itens é jogado pro final, estando assim, ordenado.

  -> PERFORMANCE:
	- Melhor Caso: O(N)
	- Pior caso: O(N^2)
	- Não recomendado para grandes conjutnso de dados


Referencia: SILVA, André Backes. Linguagem C: Completa e Descomplicada. São Paulo: Editora XYZ, 2023.
*/

#include <stdio.h>
#include <stdlib.h>
#include "randomArray.h"
#define ARRAY_SIZE 10000
void bubbleSort(int *v , int N);
void printfVet(int *V  , int N);


int main(){

    int vet[ARRAY_SIZE];
	generateRandomValues(vet,ARRAY_SIZE);

    printf("Vetor desordenado:\n");
	printfVet(vet,ARRAY_SIZE);

    bubbleSort(vet,ARRAY_SIZE);

    printf("Vetor ordenado:\n");
	printfVet(vet,ARRAY_SIZE);
    
    return 0;
}

void bubbleSort(int *V , int N){
		int i, continua, aux, fim = N;
		do{
		    continua = 0;
		    for( i = 0 ; i < fim -1; i++ ){
			if( V[i] > V[i+1] ){
			   aux = V[i];
			   V[i] = V[i+1];
			   V[i+1] = aux;
			   continua = i;
			}	
		    }
            fim--;
		}while(continua != 0);
	}
void printfVet(int *V  , int N){
    int i;
    for(i = 0; i < N; i++)
        printf("%d: %d\n",i, V[i]);
    printf("\n");
}