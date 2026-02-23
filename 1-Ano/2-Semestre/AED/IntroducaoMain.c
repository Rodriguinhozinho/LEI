
#include <stdio.h>
#include <stdlib.h>

#include "Aleatorio.h"
#include "Introducao.h"

int main()
{
	int N;
	ALUNO *turma;
	turma = criarArray(&N);
	if (turma != NULL) {
        mostrarArray(turma, N);
        free(turma);
	}
    return 0;
}
