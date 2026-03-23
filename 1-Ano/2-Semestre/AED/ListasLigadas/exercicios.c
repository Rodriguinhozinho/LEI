#include <stdio.h>
#include "Aleatorio.h"
#include "EADLista.h"
#include "OperacoesBasicasGrupoA.h"


int  qparAlunoLimite (Pnodo L, int limite){
    int qpar= 0;
    while (L != NULL){
        if(L->Elemento.notaFinal > limite && L->Elemento.numAluno % 2 == 0)
            qpar ++;
        L = L->Prox;
    }
    return qpar;
}

int maiorMTP (PNodo L){
    float maior = -1;
    int num = -1;

    while (L != NULL){
        if(L->Elemento.notasMTP > maior){
            maior = L->Elemento.notasMTP;
            num = L->Elemento.numAluno;
        }
        L = L->Prox;
    
    }
    return num;
}

int mediaNotasFinal (PNodo L){
    int soma = 0, count = 0;
    while (L != NULL){
        if (L->Elemento.NotasTE > 9.5){
            soma += L->Elemento.notaFinal;
            count++;
        }
        L = L->Prox;
    }
    if(count == 0)
        return 0;
    return (float)soma / count;
}

int menorNumAlunoNota (PNodo L, int nota){
    int numAluno = -1;
    while ( L != NULL){
        if(L->Elemento.notaFinal == nota){
            if(numAluno == -1 || L->Elemento.numAluno < numAluno)
                numAluno = L->Elemento.numAluno;
        }´
        L = L->Prox;
    }
    return numAluno;
}


int main(){
    PNodo L = criarListaAleatoria(1,15);
    mostrarLista(L);
    if(L->Prox != NULL){
        printf("Notas dos mini-testes: %d \nNotas dos testes teoricos do segundo elemento da lista: %d\n" , L->Prox->Elemento.notasMTP, L->Prox->Elemento.notasTE);
    }
    int NOTA = L->Elemento.notaFinal;
    printf("Nota final do primeiro elemento da lista: %d\n", NOTA);
    int menornumAluno = menorNumAlunoNota(L, NOTA);
    printf("O numero do aluno com a menor matricula e nota final igual a %d: %d\n", NOTA, menornumAluno);
}
