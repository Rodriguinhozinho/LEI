#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int Elemento;
    struct nodo *Prox;
} NodoLista, *PNodoLista;

PNodoLista criarNo(int valor) {
    PNodoLista novo = (PNodoLista)malloc(sizeof(NodoLista));
    novo->Elemento = valor;
    novo->Prox = NULL;
    return novo;
}

//IMPLEMENTAÇÃO DAS FUNCOES

//remover se o segundo elemento de um par for menor que o primeiro
PNodoLista limparDescendentes(PNodoLista L){
	PNodoLista P = L;
	PNodoLista remove = NULL;
	PNodoLista Pant = NULL;
	PNodoLista Ppos = P->Prox;
	if (L == NULL || L->Prox ==NULL) return L;
	while (P!= NULL && P->Prox != NULL){
		if (P->Elemento > P->Prox->Elemento){
			remove = P ->Prox;
			P ->Prox = remove ->Prox;
			free (remove);
			}
		else{
			P = P->Prox;}
	}
	return L;
}



//mover o primeiro  impar para o fim
PNodoLista moverPrimeiroImparParaFim(PNodoLista L) {
	if(L == NULL || L->Prox == NULL) return L;
	PNodoLista P = L;
	PNodoLista ULT = L;
	PNodoLista Pant = NULL;
	while ( P!= NULL && P->Elemento % 2 == 0){
		Pant = P;
		P = P->Prox;
	}
	if( P == NULL | P->Prox == NULL) return L
	if (Pant == NULL) L = P ->Prox;
	else Pant->Prox = P-> Prox;
	while (ULT -> Prox != NULL){
		ULT = ULT->Prox;
	}
	ULT->Prox = P;
	P->Prox = NULL;
	return L;
}



int main() {
    PNodoLista minhaLista = criarNo(15);
    minhaLista->Prox = criarNo(10);
    minhaLista->Prox->Prox = criarNo(20);
    minhaLista->Prox->Prox->Prox = criarNo(8);

    printf("Lista original: 15 -> 10 -> 20 -> 8\n");

    minhaLista = limparDescendentes(minhaLista);

    printf("Lista final:    ");
    PNodoLista temp = minhaLista;
    while (temp != NULL) {
        printf("[%d] -> ", temp->Elemento);
        temp = temp->Prox;
    }
    printf("NULL\n");

    return 0;
}


