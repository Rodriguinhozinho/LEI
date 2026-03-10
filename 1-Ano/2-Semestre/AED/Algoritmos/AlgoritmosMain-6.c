#include <stdio.h>
#include <stdlib.h>
#include "Aleatorio.h"
#include "Algoritmos.h"
int main(){
    int N=30, *A, num, contador=0;
    A = lerArray(N, 10, 30);
    mostrarArray(A, N);
    num = gerarNumeroInteiro(10, 30);
    printf("Número gerado: %d\n", num);
    ordenarSeleccao(A, N);
    printf("\nArray A ordenado (necessario para pesquisaSequencial):\n");
    mostrarArray(A, N);
    int pos = pesquisaSequencial(num, A, N);
    if(pos >= 0)
        printf("Número %d encontrado na posição %d do array A.\n", num, pos);
    else
        printf("Número %d não encontrado no array A.\n", num);
    for (int i = 0; i < N; i++) {
        if(A[i] > num)
            contador++;
    }
    printf("Numero de elementos maiores do que %d: %d\n", num, contador);
    free(A);
    return 0;
}
