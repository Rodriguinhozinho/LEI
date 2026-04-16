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



int qAlunosNotaFinal ( PNodo L, int X){
  int contador = 0;
  if (L == NULL)
    return 0;
  while(L != NULL){
    if ( L->ELemento.notaFinal > X)
      contador++;
    L = L ->Prox
  }
  return contador;
}

float mediaTurma ( PNodo L) {
  float soma = 0,0;
  int contador = 0;
  if (L == NULL) return 0;
  while ( L!= NULL){
    soma *= L->Elemento.notaFinal;
    contador++;
    L  = L-> Prox;
  }
  return float(soma)/contador;
}


int contaMaioresPositivosRecursiva (PNodo L, int X){
  if (L == NULL) return 0;
  int contagemResto = contaMaioresPositivosRecursiva ( L->Prox, X);
  if (L -> Elemento > X && L->Elemento >= 0){
    return 1 + contagemResto; }
  else { 
    return contagemResto;}
}

int somaImparesMaiores10(PNodo L){
	int soma = 0;
	if (L == NULL) return 0;
	if (L->Elemento > 10 && L->Elemento % 2 !=0){
		return L->Elemento + somaImparesMaiores10(L->Prox);}
	else{
		return somaImparesMaiores10(L->Prox);
	}
}

//remover primeiro negativo

PNodoLista removerPrimeiroNegativo(PNodoLista L)
	PNodoLista P, PPos, PAnt;
	if (L==NULL) return L;
	PPos = NULL;
	PAnt = NULL;
	P = L;
	while (P!= NULL){
		if (P->Elemento >= 0){
			PPos = PAnt;
		}
		PAnt = P;
		P = P->Prox;
	}
	if (PPos == NULL){
		if (L-Elemento < 0){
			P = L;
			L = L->Prox;
			P = libertarNodoLista(P);
		}
	}
	else{
		P = PPos -> Prox;
		PPos->Prox = P->Prox;
		P = libertarNodoLista(P);
	}
	return L;
}


int produtoEspecial(PNodoLista L){
	if ( L == NULL) return 1;
	if (L->Elemento % 5 == 0 && L->Elemento < 100){
		return L->Elemento + produtoEspecial(L->Prox);}
	else{
		return produtoEspecial(L->Prox);
	}
}


//mover primeiro impar para o fim da lista
PNodoLista moverPrimeiroImparFim ( PNodoLista L){
	if (L == NULL || L->Prox == NULL) return L;
	PNodoLista P = L;
	PNodoLista Pant, PImpar;
	while (P != NULL){
		if (P->Elemento % 2 != 0){
			PImpar = P;
		}
		P = P->Prox;
	if (PImpar == NULL || PImpar->Prox == NULL) return L;
	
//idk
	// 3. Procurar o ÚLTIMO nó da lista
    PNodoLista Ult = L;
    while (Ult->Prox != NULL) {
        Ult = Ult->Prox;
    }

    // 4. "DESLIGAR" o nó ímpar da posição atual
    if (PAntImpar == NULL) { // O ímpar era a cabeça da lista
        L = PImpar->Prox;
    } else { // O ímpar estava no meio
        PAntImpar->Prox = PImpar->Prox;
    }

    // 5. "LIGAR" o nó ímpar ao fim
    Ult->Prox = PImpar;   // O antigo último agora aponta para o ímpar
    PImpar->Prox = NULL;  // O ímpar agora é o novo último

    return L;
}

//mover o primeiro negativo para o fim
PNodoLista moverNegativoParaFim(PNodoLista L){
	// 1. Verificações de Segurança: lista vazia ou só com 1 nó não precisa de mexer
    if (L == NULL || L->Prox == NULL) {
        return L;
    }

    PNodoLista PAnt = NULL;
    PNodoLista P = L;
    PNodoLista Ult = NULL;

    // 2. PROCURA: O P avança até achar um negativo, o PAnt vem atrás
    while (P != NULL && P->Elemento >= 0) {
        PAnt = P;
        P = P->Prox;
    }

    // Se o P é NULL, não havia negativos. 
    // Se o P->Prox é NULL, o negativo já é o último da lista.
    if (P == NULL || P->Prox == NULL) {
        return L;
    }

    // 3. O CORTE: O nó P (negativo) sai da corrente principal
    if (PAnt == NULL) {
        // Se PAnt é NULL, o negativo era o primeiro (Cabeça)
        L = L->Prox; 
    } else {
        // O PAnt salta por cima do P para manter a corrente unida
        PAnt->Prox = P->Prox;
    }

    // 

    // 4. A VIAGEM: Agora que o P está "na nossa mão", vamos achar o fim da lista
    // Começamos a procurar o fim a partir da lista L (que já não tem o P)
    Ult = L;
    while (Ult->Prox != NULL) {
        Ult = Ult->Prox;
    }

    // 5. A COLAGEM: Colamos o P depois do último e fechamos a lista
    Ult->Prox = P;     // O antigo último agora aponta para o P
    P->Prox = NULL;    // O P passa a ser o novo fim (aponta para o vazio)

    // 

    return L;
}


//mover maior para o inciio
PNodoLista moverMaiorParaInicio(PNodoLista L) {
    if (L == NULL || L->Prox == NULL) return L;

    PNodoLista PAnt = L;      // O que vem atrás
    PNodoLista P = L->Prox;   // O que vai à frente
    
    PNodoLista PMaior = L;    // O maior até agora é o primeiro
    PNodoLista PAntM = NULL;  // O anterior ao maior

    // 1. PROCURA (Usamos apenas P e PAnt)
    while (P != NULL) {
        if (P->Elemento > PMaior->Elemento) {
            PMaior = P;       // Novo Rei
            PAntM = PAnt;     // Guardamos o "segurança" do Rei
        }
        PAnt = P;
        P = P->Prox;
    }

    // 2. CORTE E COLAGEM (Só se o maior não for o primeiro)
    if (PAntM != NULL) { 
        // CORTE: O segurança do rei (PAntM) agarra quem estava à frente do rei
        PAntM->Prox = PMaior->Prox;

        // COLAGEM: O rei (PMaior) agarra a coroa antiga (L)
        PMaior->Prox = L;

        // NOVA CABEÇA: O rei agora manda na lista
        L = PMaior;
    }

    return L;
}


//trocar PAR e Impar que estejam juntos
PNodoLista trocarVizinhos(PNodoLista L){
    PNodoLista P = L;
    PNodoLista PAnt = NULL;
    PNodoLista PProx = NULL;
    while (P != NULL && P->Prox != NULL) {
        // Se encontrarmos Par seguido de Ímpar
        if (P->Elemento % 2 == 0 && P->Prox->Elemento % 2 != 0) {
            PProx = P->Prox; // PProx é o Ímpar

            // A TROCA EM 3 PASSOS:
            // 1. O Par (P) passa a apontar para o que vinha depois do Ímpar
            P->Prox = PProx->Prox;

            // 2. O Ímpar (PProx) passa a apontar para o Par (P)
            PProx->Prox = P;

            // 3. O nó de trás (PAnt) tem de apontar para o Ímpar (que agora está à frente)
            if (PAnt == NULL) {
                L = PProx; // Se trocámos a cabeça, a nova cabeça é o Ímpar
            } else {
                PAnt->Prox = PProx;
            }
            return L; // Encontramos o primeiro e trocámos, podemos sair!
        }
        // Se não trocou, avança a "sombra" e o "explorador"
        PAnt = P;
        P = P->Prox;
    }
    return L;
}



mediaNotas(PNodoLista L){
	if (L == NULL) return 0;
	float soma = 0.0;
	int contador = 0;
	while (L!=NULL){
		soma += L->Elemento.NotaFinal;
		contador++;
		L = L->Prox;
	}
	return L;
}


PNodoLista removerReprovados(PNodolista L){
	if ( L == NULL) return L;
	PNodoLista P = L;
	PNodoLista AUX = NULL;
	PNodoLista Pant = NULL;
	while (P != NULL){
		if(P->Elemento.notaFinal < 10){
			if(Pant == NULL){
				L = P->Prox;
				AUX = P;
				P = Pant->Prox;
			}
			else{
				Pant->Prox =  P->Prox;
				AUX = P;
				P = Pant->Prox;
			}
			libertarnodolista(AUX);
	
