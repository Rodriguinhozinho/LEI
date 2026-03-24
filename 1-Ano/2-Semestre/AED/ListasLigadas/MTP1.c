//Teste turno manhã

typedef struct{
    int numFatura; // entre 1000 e 2000
    int NIF; // numero contribuinte entre 123450 e 123460
    int Dia; // entre 1 e 31´
    int Mes; // entre 1 e 12
    float total; //valor total da fatura entre 5.0 e 500.0
} DadosLista

struct NodoLista   
{
  DadosLista Elemento;
  struct NodoLista *Prox;
}; 
typedef struct NodoLista *PNodoLista; 

SomaTotalMes (PNodoLista L, int M){
    float soma = 0.0
    while (L != NULL){
        if (L->Elemento.Mes == M){
            soma += L->Elemento.total;
        }
        L = L->Prox;
    }
    return soma;
}

int main (){
    PNodoLista L = criarLista(15);
    mostrarLista(L);
    int N;
    if (L != NULL && L->Prox != NULL){
        N = L->Prox->Elemento.Mes;
    }
    printf("Mes do segundo elemento da lista: %d\n", N);
    float soma = SomaTotalMes(L, N);
    printf("Soma total das faturas do mes %d: %.2f\n", N, soma);
    return 0;
}
