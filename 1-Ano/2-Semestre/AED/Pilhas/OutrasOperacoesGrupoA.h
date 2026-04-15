
/* ------------------------------------------------------- */
/* ---- protÛtipos/headers das funÁıes da biblioteca ----- */
/* ------------------------------------------------------- */

// operaÁ„o apenas para controlo
//   - n„o faz parte da EAD Pilha
//   - mostra a Pilha do topo para o fundo
void mostrarPilha (PNodoPilha);
int mostrarN(PNodoPilha *, DadosPilha*, int N);



/* ------------------------------------------------------- */
/* -------------- implementaÁ„o das funÁıes -------------- */
/* ------------------------------------------------------- */

// operaÁ„o apenas para controlo
//   - n„o faz parte da EAD Pilha
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

//ex 5
DadosPilha mostrarElementoN(PNodoPilha S, int N)
{
  PNodoPilha Aux= criarPilha();
  DadosPilha X; 
  int i = 1;
  for (i; i<N; i++){
    Aux = push(topo(S), Aux);
    S = pop(S);
  }
  X = topo(S);
  while (!pilhaVazia(Aux)){
    S = push(topo(Aux), S);
    Aux = pop(Aux);
  }
  return X;
}
//ex 7
DadosPilha fundoPilha (PNodoPilha S, int N){
  PNodoPilha Aux = criarPilha();
  DadosPilha X;
  while (!pilhaVazia(S)){
    X = topo(S);
    Aux = push(X, Aux);
    S = pop(S);
  }
  while (!pilhaVazia(Aux)){
    S = push(topo(Aux), S);
    Aux = pop(Aux);
  }
  return X;
}
//ex 8
DadosPilha terceiroElementoFundo (PNodoPilha S, int N){
  PNodoPilha Aux = criarPilha();
  DadosPilha X;
  for (int i = 1; i < N - 2; i++){
    Aux = push(topo(S), Aux);
    S = pop(S);
  }
  X = topo(S);
  while (!pilhaVazia(Aux)){
    S = push(topo(Aux), S);
    Aux = pop(Aux);
  }
  return X;
}

// ex 10
void organizarPilhaNota(PNodoPilha *S){
  PNodoPilha Apr = criarPilha();
  PNodoPilha Rep = criarPilha();
  while (!pilhaVazia(*S)){
    DadosPilha X = topo (*S);
    if (X.notaFinal > 10)
      Apr = push(X, Apr);
    else
      Rep = push(X, Rep);
    *S = pop(*S);
  }
  while (!pilhaVazia(Rep)){
    *S = push(topo(Rep), *S);
    Rep = pop(Rep);
  }
  while (!pilhaVazia(Apr)){
    *S = push(topo(Apr), *S);
    Apr = pop(Apr);
  }
}

// inverter
PNodoPilha inverterPilha(PNodoPilha S){
if (pilhaVazia(S)) {
        return S; 
    }
    DadosPilha temp = topo(S);
    S = pop(S);
    S = inverterPilhaRecursiva(S);
    S = inserirNoFundo(S, temp);
    return S;
}

int inverterPilhaRestri√ß√£o (PNodoPilha *S){
  if(pilhaVazia(*S)) return *S;
  PNodoPilha AUX = criarPilha();
  PNodoPilha INV = criarPilha();
  int neg = 0;
  INFOPilha valor;
  while(!pilhaVazia(*S)){
    valor = topo(*S);
    if ( valor < 0) neg = 1;
    AUX = push (valor , AUX);
    *S = pop(*S);
  }
  if (neg ==1){
    while(!pilhaVazia(AUX){
      INV = push((topo(AUX), INV);
      AUX = pop(AUX);
   }
   while(!pilhaVazia(INV)){
      *S = push(topo(INV), *S);
      INV = pop(INV);
   }
  else{
    while(!pilhaVazia(AUX)){
      *S = push((topo(AUX), *S);
      AUX = pop(AUX);
    }
  }
  return neg;
}



