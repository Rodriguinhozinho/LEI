
/* ------------------------------------------------------- */
/* ---- protótipos/headers das funções da biblioteca ----- */
/* ------------------------------------------------------- */

// operação apenas para controlo
//   - não faz parte da EAD Pilha
//   - mostra a Pilha do topo para o fundo
void mostrarPilha (PNodoPilha);
int mostrarN(PNodoPilha *, DadosPilha*, int N);



/* ------------------------------------------------------- */
/* -------------- implementação das funções -------------- */
/* ------------------------------------------------------- */

// operação apenas para controlo
//   - não faz parte da EAD Pilha
//   - mostra a Pilha do topo para o fundo
void mostrarPilha (PNodoPilha S)
{
  PNodoPilha P = S;
  while (P != NULL){
    mostrarElementoPilha(P->Elemento);
    P = P->Ant;
  }
}


int mostrarN(PNodoPilha* S, DadosPilha* X, int N)
{
  if(pilhaVazia(*S))
    return -1; // Pilha vazia
  PNodoPilha S2 = criarPilha();
  int i = 1;
  while (i < N && !pilhaVazia(*S)){
    S2 = push(topo(*S), S2);
    *S = pop(*S);
    i++;
  }
  int resultado = 0;
  if (!pilhaVazia(*S)){
    *X = topo(*S);
    resultado = 1;
  }
  while (!pilhaVazia(S2)){
    *S = push(topo(S2), *S);
    S2 = pop(S2);
  }
  return resultado;
}
