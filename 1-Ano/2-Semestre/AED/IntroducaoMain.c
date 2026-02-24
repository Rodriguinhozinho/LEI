
#include <stdio.h>
#include <stdlib.h>

#include "Aleatorio.h"
#include "Introducao.h"

int main()
{
	int N, B, K=10;
	ALUNO *A;
	A = criarArray(&N);
        mostrarArray(A, N);
        free(A);
	B=quantNotasMaiorIgualK(A, N, K);
	printf("Número de notas maiores que %d = %d \n", K, B);
}
