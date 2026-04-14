
#include <stdio.h>
#include <stdlib.h>

#include "Aleatorio.h"
#include "OperacoesBasicasGrupoA.h"
#include "EADPilha.h"
#include "OutrasOperacoesGrupoA.h"

int main()
{
    PNodoPilha S;
    int N = gerarNumeroInteiro(0,15);
    S = criarPilha(N);
    mostrarPilha(S);
    int flag;
    DadosPilha X;
    /*flag = delvolvesec(&S, &X);
    if (flag == 1){
        printf("Segundo elemento:\n");
        mostrarElementoPilha(X);
        printf("Pilha:\n");
        mostrarPilha(S);
    }
    else{
        printf("A pilha não tem elementos suficientes para realizar a operação.\n");
    }*/
    flag = mostrarN(&S, &X, 3);
    if (flag == 1){
        printf("Terceiro elemento:\n");
        mostrarElementoPilha(X);
        printf("Pilha:\n");
        mostrarPilha(S);
    }
}

