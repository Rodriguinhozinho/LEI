#include <stdio.h>
#include <stdlib.h>
#include "Aleatorio.h"
#include "Algoritmos.h"
int main(){
    int *A, N=50;
    A = lerArray(N,10,20);
    mostrarArray(A, N);
    int num = gerarNumeroInteiro(10,20);
    ordenarQuicksort(A, 0, N-1);
    mostrarArray(A, N);
    int pos = pesquisaBinariaR(num, A, 0, N-1);
    if(pos >= 0)
        printf("O numero %d esta na posicao %d do array.\n", num, pos);
    else
        printf("O numero %d nao esta presente no array.\n", num);
    int maiorMenor = -1;
    int menorMaior = -1;
    int qtdIguais = 0;
    if(pos >= 0)
        for ( int i = 0; i<N; i++){
            if (A[i] == num )
                qtdIguais++;
            if (A[i] < num)
               if(maiorMenor == -1 || A[i] > maiorMenor)
                    maiorMenor = A[i];
            if(A[i] > num)
                if(menorMaior == -1 || A[i] < menorMaior)
                    menorMaior = A[i];
        }
    if (maiorMenor != -1)
            printf("Maior elemento de A menor que %d: %d\n", num, maiorMenor);
        else
            printf("Nao existe elemento menor que %d.\n", num);
    if(menorMaior != -1)
            printf("Menor elemento de A maior que %d: %d\n", num, menorMaior);
        else
            printf("Nao existe elemento maior que %d.\n", num);
    free(A);
    return 0;
}
