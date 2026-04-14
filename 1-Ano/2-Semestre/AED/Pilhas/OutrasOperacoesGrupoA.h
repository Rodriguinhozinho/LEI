
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

int devolverTerceiro(PNodoPilha* S, DadosPilha* X3)
{
  DadosPilha X1, X2;
  X1 = topo(*S);
  while (!pilhaVazia(*S)){
    *X3 = X2;
    X2 = X1;
    X1 = topo(*S);
    *S = pop(*S);
  }
  if ((*X3).numAluno != -1)
    return 1;
  return 0;
}

PNodoPilha trocarFundoTopo (PNodoPilha S)
{
  if (pilhaVazia(S))
    return S;
  DadosPilha A, B;
  PNodoPilha Aux;
  A = topo(S);
  s = pop(S);
  while(!pilhaVazia(S)){
    Aux = push(topo(S), Aux);
    S = pop(S);
  }
  if (!pilhaVazia(Aux)){
    S = push(A , S);
    return S;
  }
  B = topo(Aux);
  Aux = pop(S);
  S = push (A, S);
  while (!pilhaVazia(Aux)){
    S = push(topo(Aux), S);
    Aux = pop(Aux);
  }
  return S;
}
