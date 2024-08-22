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
#define TAM_VETOR 10
void bubbleSort(int *v , int N);

int main(){

    int conjuntoDesordenado[TAM_VETOR] = {10,2,3,7,18,-2,49,22,12,1};
    int i;

    printf("Vetor desordenado:\n");
    for ( i = 0; i < TAM_VETOR; i++){
        printf("%d: %d\n",i,conjuntoDesordenado[i]);
    }
    printf("\n");
    bubbleSort(conjuntoDesordenado,TAM_VETOR);

    printf("Vetor ordenado:\n");
    for ( i = 0; i < TAM_VETOR; i++){
        printf("%d: %d\n",i,conjuntoDesordenado[i]);
    }
    
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