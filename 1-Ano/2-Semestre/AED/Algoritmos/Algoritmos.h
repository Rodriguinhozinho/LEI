
/* ------------------------------------------------------- */
/* ---------------- BIBLIOTECA ALGORITMOS ---------------- */
/* ------------------------------------------------------- */


/* ------------------------------------------------------- */
/* ---- protótipos/headers das funções da biblioteca ----- */
/* ------------------------------------------------------- */


int *lerArray (int, int, int);

void mostrarArray (int*, int);

// algoritmos de ordenação

void ordenarSeleccao (int*, int);

void ordenarBorbulhagem (int*, int);

void ordenarQuicksort (int*, int, int);

void ordenarFusao (int*, int, int);

// algoritmos de pesquisa

int pesquisaExaustiva (int, int*, int);

int pesquisaSequencial (int, int*, int);

int pesquisaBinaria (int, int*, int);

int pesquisaBinariaR (int, int*, int, int);



/* ------------------------------------------------------ */
/* ------- implementacao dos subprogramas/funcoes ------- */
/* ------------------------------------------------------ */

// operação auxiliar: trocar os valores de duas variáveis
void trocar (int *a, int *b)
{
  int aux;
  aux = *a;
  *a = *b;
  *b = aux;
}

// cria e preenche um array com N inteiros entre inf e sup
int *lerArray (int N, int inf, int sup)
{
  int *A, k;
  A = (int*) malloc(N * sizeof(int));
  for(k = 0; k < N; k++)
  	A[k] = gerarNumeroInteiro(inf, sup);
  return A;
}

void mostrarArray (int *A, int N)
{
  int k;
  for(k = 0; k < N; k++)
    printf("%3d ", A[k]);
  printf("\n");
}

// ordenar um array por ordem crescente
void ordenarSeleccao (int A[], int N)
{
  int k, j, posMenor;
  for(k = 0; k < N-1; k++) {
    posMenor = k;
    for(j = k+1; j < N; j++) {
      if (A[j] < A[posMenor])
        posMenor = j;
    }
    if(posMenor != k)	
      // trocar A[posMenor] com A[k]
      trocar(&A[posMenor], &A[k]);
  }
}

// ordenar um array por ordem crescente
void ordenarBorbulhagem (int A[], int N)
{
  int k, fim, numTrocas;
  fim = N - 1;
  do{
    numTrocas = 0;
    for(k = 0; k < N-1; k++)
      if(A[k] > A[k+1]) {
        trocar(&A[k], &A[k+1]);
        numTrocas++;
      }
    fim = fim - 1;
  }while (numTrocas > 0);
}

// ordenar um array por ordem crescente
int determinarPosicaoPivot (int A[], int inicio, int fim)
{
  int k, pos;
  pos = inicio;		
  // pos é a posição final do pivot (A[inicio]) em A ordenado
  for(k = inicio + 1; k <= fim; k++) {
    if(A[k] < A[inicio]) {
      pos++;
      if(k != pos)
        trocar(&A[k], &A[pos]);
    }
  }
  trocar(&A[inicio], &A[pos]);
  return pos;
}

void ordenarQuicksort (int A[], int inicio, int fim)
{
  int pos;		
  // pos é a posição final do pivot A[inicio] em A ordenado
  if(inicio < fim) {
    pos = determinarPosicaoPivot(A, inicio, fim);  // colocar o pivot ordenado
    ordenarQuicksort(A, inicio, pos-1);		// ordenar a sub-array esquerdo
    ordenarQuicksort(A, pos+1, fim);		// ordenar a sub-array direito
  }
}

// ordenar um array por ordem crescente
void fundir (int A[], int inicio, int meio, int fim)
{
  int esq, dir, k, i, Aux[fim-inicio+1];
  esq = inicio;
  dir = meio + 1;
  k = 0;  // controlo do array Aux
  while(esq <= meio && dir <= fim) 
  {
    if(A[esq] < A[dir]) {
      Aux[k] = A[esq]; 
      esq++;
    }
    else {
      Aux[k] = A[dir]; 
      dir++;
    }
    k++;
  }  // while
  if(esq > meio)
    for(i = dir; i <= fim; i++) {
      Aux[k] = A[i];
      k++;
    }
  else  // dir > fim
    for(i = esq; i <= meio; i++) {
      Aux[k] = A[i];
      k++;
    }
  // array Aux construído e ordenado
  // agora passar os elementos do Aux para o array A
  for(i = 0; i < k; i++)
    A[inicio+i] = Aux[i];
}

void ordenarFusao (int A[], int inicio, int fim)
{
  int meio;
  if(inicio < fim) {
    meio = (inicio + fim) / 2;
    ordenarFusao(A, inicio, meio);
    ordenarFusao(A, meio+1, fim);
    fundir(A, inicio, meio, fim);
  }
}


// pesquisar um elemento num array não ordenado
int pesquisaExaustiva (int E, int A[], int N)
{
  int k, pos;
  pos = -1;
  k = 0;
  while(k < N && pos == -1) {
    if(A[k] == E)
      pos = k;
    else
      k = k + 1;
  }
  // pos = -1 => E não existe em A 
  // pos >= 0 => E está na posição pos de A
  return pos;
}

// pesquisar um elemento num array ordenado por ordem crescente
int pesquisaSequencial (int E, int A[], int N)
{
  int k, pos;
  // pos é a posição de E no array A 
  //  se pos = -1 então E não existe em A		
  pos = -1; 
  k = 0;
  while(k < N && pos == -1) 
  {
    if(A[k] == E)
      pos = k;
    else
      if(A[k] < E)
        k = k + 1;
      else
        pos = -2;
  }
  // pos < 0 => E não existe em A
  // pos >= 0 => E está na posição pos de A
  return pos;
}

// pesquisar um elemento num array ordenado por ordem crescente
int pesquisaBinaria (int E, int A[], int N)
{
  int  inicio, fim, meio, pos;
  inicio = 0; 	
  fim = N - 1;
  pos = -1;
  while(inicio <= fim && pos == -1) {
    meio = (inicio + fim) / 2;
    if(A[meio] == E)
      pos = meio;
    else
      if(A[meio] < E)
        inicio = meio + 1;
      else
        fim = meio - 1;
  }
  return pos;
}

// pesquisar um elemento num array ordenado por ordem crescente
int pesquisaBinariaR (int E, int A[], int inicio, int fim)
{
  int  meio;
  // casos base/terminais
  if (inicio > fim)
    return -1;  // E não está em A
  meio = (inicio + fim) / 2;
  if (A[meio] == E)
    return meio;  // E está na posição meio de A
  // caso geral
  if (A[meio] < E)
    return pesquisaBinariaR(E, A, meio+1, fim);
  else
    return pesquisaBinariaR(E, A, inicio, meio-1);
}

