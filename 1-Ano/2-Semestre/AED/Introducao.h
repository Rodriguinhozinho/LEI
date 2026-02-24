

/* ------------------------------------------------------- */
/* ---------------- BIBLIOTECA INTRODUCAO ---------------- */
/* ------------------------------------------------------- */

 
/* ------------------------------------------------------- */
/* ---- protótipos/headers das funções da biblioteca ----- */
/* ------------------------------------------------------- */


typedef struct{
  int numAluno;      // Numero de aluno: {70000, ..., 75000}
  float notasMTP[2];  // Notas dos 2 mini-testes praticos: [0, 2]
  float notasTE[2];  // Notas dos 2 testes escritos: [0, 8]
  int notaFinal;     // Nota final (soma das notasMTP e notasTE): {0, ..., 20}
}ALUNO;
ALUNO *criarArray(int*);
ALUNO *lerArray (int*);
void mostrarArray (ALUNO*, int);

void atualizarArray (ALUNO*, int);

void ficheiroNotasFinais (ALUNO*, int);

int maiorNotaFinal (ALUNO*, int);

int maiorNotaFinal_REC (ALUNO*, int);

void arrayAprovados (ALUNO*, int, ALUNO**, int *);

int quantNotasMaiorIgualK (ALUNO*, int, int);

int arrayNotasFinais (ALUNO*, int, int**);

void somaElementosArrayInt (int*, int, int, int*, int*);


/* ------------------------------------------------------ */
/* ------- implementacao dos subprogramas/funcoes ------- */
/* ------------------------------------------------------ */

// devolve 1 se num ja existe no array A e 0 se nao existe
int existe (int num, ALUNO *A, int tamA)
{
  int k; 
  for(k = 0; k < tamA; k++)
  {
    if(A[k].numAluno == num)
      return 1;
  }
  return 0;
}

ALUNO *criarArray (int *N)
{
	ALUNO *A;
	int i, num;
	*N = gerarNumeroInteiro(1,30);
	A = (ALUNO *) malloc((*N) * sizeof(ALUNO));
 	for (i = 0; i < *N; i++) {
 	       do {
       	 	num = gerarNumeroInteiro(70000, 75000);
        } while (existe(num, A, i));
        		A[i].numAluno = num;
        		A[i].notasMTP[0] = gerarNumeroReal(0.0, 2.0);
        		A[i].notasMTP[1] = gerarNumeroReal(0.0, 2.0);
        		A[i].notasTE[0] = gerarNumeroReal(0.0, 8.0);
        		A[i].notasTE[1] = gerarNumeroReal(0.0, 8.0);
        		float soma = A[i].notasMTP[0] + A[i].notasMTP[1] + A[i].notasTE[0] + A[i].notasTE[1];
        		A[i].notaFinal = (int)(soma + 0.5);
		}
    return A;
}

void mostrarArray (ALUNO *A, int N)
{
    int i;
    printf("\n%-10s | %-15s | %-15s | %-10s\n", "Numero", "Notas MTP", "Notas TE", "Nota Final");
    for (i = 0; i < N; i++)
    {
        printf("%-10d | [%.2f, %.2f] | [%.2f, %.2f] | %-10d\n", A[i].numAluno,
               A[i].notasMTP[0], A[i].notasMTP[1],
               A[i].notasTE[0], A[i].notasTE[1],
               A[i].notaFinal);
    }
}
void atualizarArray (ALUNO *A, int N)
{

}

void ficheiroNotasFinais (ALUNO *A, int N)
{

}

int maiorNotaFinal (ALUNO *A, int N)
{

}

int maiorNotaFinal_REC (ALUNO *A, int N)
{
	if(N==1)
		return A[0].notaFinal;
	if (A[0].notaFinal > A[1].notaFinal)
		A[1].notaFinal = A[0].notaFinal;
		return maiorNotaFinal_REC(A+1 , N-1);
}

void arrayAprovados (ALUNO *A, int N, ALUNO **V, int *NA)
{
	*NA = 0;
	int K, i;
	*V = (ALUNO*) malloc (*NA * sizeof(ALUNO));
	for (i = 0; i< N; i++){
		if(A[i].notaFinal >= 10)
			(*NA)++;
			*V = (ALUNO*)  realloc (*V, (*NA) * sizeof(ALUNO));
			*V[*NA-1]=A[i];
	}
}

int quantNotasMaiorIgualK (ALUNO *A, int N, int K)
{
	if(N == 0)
		return 0;
	int c=0;
	if (A[0].notaFinal >= K)
		c=1;
		return c + quantNotasMaiorIgualK(A+1, N-1, K);
}

int arrayNotasFinais (ALUNO *A, int N, int **V)
{

}

void somaElementosArrayInt (int *V, int N, int K, int *soma, int *quant)
{

}


