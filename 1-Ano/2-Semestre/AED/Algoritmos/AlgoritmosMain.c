#include <stdio.h>
#include <stdlib.h>
#include "Aleatorio.h"
#include "Algoritmos.h"

int main() {
    int N = gerarNumeroInteiro(1, 30);
    int *A = lerArray(N, 10, 50);
    
    printf("Array A (N=%d):\n", N);
    mostrarArray(A, N);
    
    int num = gerarNumeroInteiro(10, 50);
    printf("\nNumero gerado: %d\n", num);
    
    int pos = pesquisaExaustiva(num, A, N);
    printf("Indice de %d no array original: %d\n", num, pos);

    ordenarQuicksort(A, 0, N - 1);
    
    printf("\nArray A ordenado:\n");
    mostrarArray(A, N);
    
    pos = pesquisaBinaria(num, A, N);
    printf("Indice de %d no array ordenado: %d\n", num, pos);

    int maior = A[N - 1];
    printf("\nMaior elemento: %d\n", maior);

    int menor = A[0];
    printf("Menor valor: %d\n", menor);

    int qtdMenor = 0;
    while (qtdMenor < N && A[qtdMenor] == menor) {
        qtdMenor++;
    }
    printf("Quantidade de elementos iguais ao menor: %d\n", qtdMenor);

    if (N > 1) {
        int i = N - 2;
        while (i >= 0 && A[i] == maior) {
            i--;
        }
        if (i >= 0) {
            printf("Segundo maior elemento: %d\n", A[i]);
        }
    }

    free(A);
    return 0;
}
