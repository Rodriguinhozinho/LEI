typedef struct{
    int numCC;
    int dataNasc[3];
    float altura;
    int genero;
} DadosLista;

PNodoLista gerarListaAleatoria ( DadosLista X, int N){
    PNodoLista L = NULL;
    DadosLista X;
    for (int i = 0; i<N ; i++){
        X.numCC = gerarNumeroInteiro(100000,200000);
        X.dataNasc[0] = gerarNumeroInteiro(1,31);
        X.dataNasc[1] = gerarNumeroInteiro(1,12); 
        X.dataNasc[2] = gerarNumeroInteiro(1930,2010);
        X.altura = gerarNumeroReal(1.20,2.20);
        X.genero = gerarNumeroInteiro(0,1);
        L = inserirListaInicio(X, L);
    }
    return L;
}

int main(){
    PNodoLista L = NULL;
    DadosLista X;
    int TAM;
    TAM = gerarNumeroInteiro(0,15);
    L = gerarListaAleatoria(X, TAM);
    printf("Lista gerada Inicio - Fim:\n");
    mostrarListaCabeca(L);
    printf("Lista gerada Fim - Inicio:\n");
    mostrarListaCauda(L);
    return 0;
}

int AlturaMaior(PNodoLista X, float alt ){
    PNodoLista L = NULL;
    int cont = 0;
    while(L!=NULL){
        if(L->Elemento.altura > alt){
            cont++;
        }
        L=L->Prox;
    }
    return cont;
}

int quantidadeNascidosAno(PNodoLista L, int ano){
    int cont = 0;
    PNodoLista L;
    while (L!=NULL)
    {
        if(L->Elemento.dataNasc[2] == ano){
            cont++;
        }
        L=L->Prox;
    }
    return cont;   
}

PNodoLista eliminarNelementos (PNodoLista L, int N){
    while (N>0 && L!=NULL){
        PNodoLista aux = L;
        L= L->Prox;
        free (aux);
        N--;
    }
    return L;
}

void separargenero (PNodoLista L){
    PNodoLista M = NULL;
    PNodoLista F = NULL;
    while(L != NULL){
        if(L->Elemento.genero == 0){
            M = inserirListaInicio(L->Elemento, M);
        }
        else{
            F = inserirListaInicio(L->Elemento, F);
        }
        L = L->Prox;
    }
    printf("Lista Masculina:\n");
    mostrarListaCabeca(M);
    printf("Lista Feminina:\n");
    mostrarListaCabeca(F);
}



int MaisVelho(PNodoLista L){
    PNodoLista L= NULL;
    DadosLista Velho = L->Elemento;
    while(L != NULL){
        if(L->Elemento.dataNasc[2] > Velho.dataNasc[2]){
            Velho = L->Elemento;
            else if(L->Elemento.dataNasc[2] == Velho.dataNasc[2]){
                if(L->Elemento.dataNasc[1] > Velho.dataNasc[1]){
                    Velho = L->Elemento;
                }
                else if(L->Elemento.dataNasc[1] == Velho.dataNasc[1]){
                    if(L->Elemento.dataNasc[0] > Velho.dataNasc[0]){
                        Velho = L->Elemento;
                    }
                }
            }
        }
        L = L->Prox;
    }
    return Velho.numCC;
}

int mediaAlturaGenero (PNodoLista L, int genero){
    PNodoLista L = NULL;
    float soma = 0;
    int cont = 0;
    while(L != NULL){
        if(L->Elemento.genero == genero){
            soma += L->Elemento.altura;
            cont++;
        }
        L = L->Prox;
    }
    return soma/cont;
}

percentagemGenero (PNodoLista L, int genero){
    PNodoLista L = NULL;
    int contGenero = 0;
    int contTotal = 0;
    while(L != NULL){
        if(L->Elemento.genero == genero){
            contGenero++;
        }
        contTotal++;
        L = L->Prox;
    }
    return (float)contGenero/contTotal * 100;
}
