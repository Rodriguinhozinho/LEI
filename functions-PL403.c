/**
 * @file functions-PL403.c
 * @brief Implementação de operações com vetores.
 *
 * @details Este ficheiro contém o corpo das funções que realizam as operações.
 * As funções realizam operações como ordenação, simetria, soma por metades, geração aleatória, etc.
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "functions-PL403.h"
/**
 * @brief Ordena vetores por ordem crescente.
 * @details Esta função utiliza o método **Bubble Sort** para ordenar os valores. É uma função auxiliar que vai ser usada em outras funções.
 */
void ordenarvetor(int vetor[]){
	int i, k, troca;
        for (i=0 ; i<TAM ; i++){
                for(k=0 ; k< TAM-1 ;k++){
                         if (vetor[k]> vetor[k+1]){
                                 troca = vetor[k];
                                 vetor[k] = vetor[k+1];
                                 vetor[k+1]=troca;
                          }
                }
        }
}

/**
 * @brief Imprime uma matriz de tamanho TAM x TAM.
 * @details Esta função é uma função auxiliar para outras funções do programa.
 * @param matriz[TAM][TAM] é a matriz que vai ser impressa.
 */
void printmatriz(int matriz[TAM][TAM]){
    int x, y;
    printf("\nMatriz:\n");
    for (x=0; x<TAM; x++){
        for(y=0; y<TAM; y++){
            printf("%3d ", matriz[x][y]);
        }
    printf("\n");
    }
}
/**
 * @brief Calcula a matriz que resulta do produto do vetor original com o vetor ordenado.
 * @details Função auxiliar que cria uma matriz com o produto de cada elemento do vetor original por cada elemento do vetor ordenado.
 * @param vetor[] é o vetor original.
 * @param matrizresultante[TAM][TAM] é matriz que resulta do produto.
 */
void matrizproduto(int vetor[], int matrizresultante[TAM][TAM]){
        int x, y, ordenado[TAM];
        for (x=0 ; x <TAM; x++){
                ordenado[x] = vetor[x];
        }
        ordenarvetor(ordenado);
        for (x=0; x<TAM; x++){
                for(y=0; y<TAM; y++){
                        matrizresultante[x][y] = vetor[x] * ordenado[y];
                }
        }
}

/**
 * @brief Cria e ordena o vetor simétrico.
 * @details Calcula o vetor simétrico (sinais opostos ao vetor original) e ordena-o com a função @ref ordenarvetor().
 * @param simetrico[] é o vetor simétrico a ser calculado a partir do vetor original.
 */
void simetricovetor(int vetor[]){
        int i, simetrico[TAM];
	for(i=0; i<TAM; i++){
		simetrico[i]=-vetor[i];
	}
	ordenarvetor(simetrico);
	printf("Vetor simétrico ordenado:\n");
	for (i=0 ; i<TAM; i++){
		printf("%d ", simetrico[i]);
	}
}
/**
 * @brief Soma os elementos das duas metades do vetor.
 * @details Soma os elementos da primeira metade do vetor com os elementos correspondentes da segunda metade.
 * @param soma é o resultado da soma de cada par de elementos.
 */
void somavetor(int vetor[]){
        int i, soma;
        for (i=0; i < TAM/2 ; i++){
                soma = vetor[i] + vetor[i+TAM/2];
                printf("%d ", soma);
        }
}
/**
 * @brief Mostra os elementos do vetor que estão em posições múltiplas de 3.
 */
void multiplovetor(int vetor[]){
        int i;
        printf("Valores nas posições multiplas de 3:\n");
        for (i=0; i<TAM ; i++){
                if (i%3==0){
                        printf(" Posição-%d: %d ", i, vetor[i]);
                }
        }
}
/**
 * @brief Mostra um elemento aleatório do vetor.
 * @details Esta função utiliza uma semente("seed") que acompanha o tempo da vida real o que garante que o número devolvido vai ser diferente a cada vez que o programa é executado.
 */
void aleatoriovetor(int vetor[]){
        int i;
	srand(time(NULL)); // acompanha o tempo da vida real para gerar uma "seed" nova a cada vez que o programa é executado
        i = rand() % TAM; //retorna o número aleatorio do vetor pois está limitado pelo %TAM
        printf ("Valor aletório do vetor: %d", vetor[i]);
}
/**
 * @brief Cria uma matriz TAMxTAM com permutações do vetor.
 * @param matriz[TAM][TAM] é a matriz que vai ser impressa a partir de permutações do vetor original.
 */
void matrizvetor(int vetor[]){
        int x, y, matriz[TAM][TAM]; 
        for (x=0; x<TAM ; x++){ 
                for (y= 0; y<TAM; y++){
                        matriz[x][y] = vetor[(y + x)%TAM];
                }
        }
        printmatriz(matriz);
}
/**
 * @brief Calcula a raiz quadrada de cada elemento do vetor.
 * @details Esta função utiliza a biblioteca `<math.h>` e a função `sqrt()`. Valores negativos são ignorados.
 * @param x é o valor da raiz em cada posição.
 */
void raizvetor(int vetor[]){
        int i;
        float x;
        printf("Raiz Quadrada =\n");
        for(i=0; i<TAM; i++){
                if(vetor[i]<0){
                        printf("Valor %d Inválido (negativo)\n", vetor[i]);
                        continue;
                }
                x = sqrt(vetor[i]);
                printf("Valor = %d - Raiz = %.2f\n", vetor[i], x);
        }
}
/**
 * @brief Exibe a página de ajuda do programa.
 */
void ajuda(){ // função que serve apenas para mostrar a pagina de ajuda, está separada do programa main para não poluir tanto o código
printf("\n AJUDA DO PROGRAMA \n");
printf("1 - Ordena o vetor com base no simétrico (inverso dos sinais)\n");
printf("2 - Soma os elementos da primeira metade com os da segunda metade\n");
printf("3 - Mostra apenas as  posições múltiplas de 3 e o seu respetivo valor\n");
printf("4 - Retorna um elemento aleatório do vetor\n");
printf("5 - Cria uma matriz 14x14 com permutações do vetor\n");
printf("6 - Delvove a posição e o respetivo valor caso seja possivel calcular a raiz quadrada (valores negativos serão ignorados)\n");
printf("8 - Leitura de um novo vetor e devolução de um novo vetor que mistura metado primeiro vetor e metade do segundo");
printf("9 - Calculo e retorno do máximo divisor comum de dois números consecutivos do vetor\n");
printf("10 - Construção de uma matriz 14x14 que resultará do produto do vetor introduzido pelo utilizador , original, por esse mesmo vetor porém ordenado\n");
printf("11 - Imprime a matriz transposta da matriz que resulta do produto do vetor original com o vetor original ordenado");
printf("0 - Encerra o programa\n");
}
/**
 * @brief Cria um novo vetor que mistura metades de vetores diferentes.
 * @details Constrói um vetor final com a primeira metade do vetor original e a segunda metade de um novo vetor novo introduzido pelo utilizador.
 * @param vetor[] é o vetor original, vetor2[] é o vetor final (já misturado), vauxiliar[].
 */
void misturavetor(int vetor[]){
        int i, vetor2[TAM], vauxiliar[TAM];
        for (i=0; i<TAM; i++){
                printf("Intruza números inteiros entre -3 e 27 para o novo vetor:\n");
                scanf("%d" ,&vauxiliar[i]);
                if (vauxiliar[i]< -3 || vauxiliar[i]>27){
                        printf("Valor Inválido!");
                        i--;
                }
        }
        for (i=0; i<TAM/2; i++){
                vetor2[i]= vetor[i];
        }
        for(i= TAM/2; i<TAM; i++){
                vetor2[i] =vauxiliar[i];
        }
        printf("Vetor misturado:\n");
        for (i=0 ; i<TAM; i++){
                printf("%d " , vetor2[i]);
        }
}
/**
 * @brief Calcula o Máximo Divisor Comum (MDC) entre dois valores consecutivos.
 * @details Calcula o MDC para cada par de valores consecutivos no vetor. Valores negativos são transformados em valores absolutos.
 * @param menor é o menor valor, mdc é o máximo divisor comum
 */
void mdcvetor(int vetor[]){
        int i, x, y, z, menor, mdc;
        for (i=0; i<TAM -1 ;i++){
                x = vetor[i];
                y= vetor[i+1];
                if (x<0){
                        x = -x;
                }
                if (y<0){
                        y=-y;
                }
                if (x<y){
                        menor = x;
                }
                if (y<x){
                        menor =y;
                }
                for (z = menor ; z >=1 ;z--){
                        if (x% z == 0 && y % z == 0){
                                mdc= z;
                                break;
                        }
                }
        printf("Maximo divisor comum entre %d e %d = %d\n", vetor[i], vetor[i+1], mdc);
        }
}
/**
 * @brief Calcula e imprime a matriz resultante do produto do vetor original com o vetor ordenado.
 * @details Utiliza a função auxiliar @ref calcular_matriz_produto() para criar a matriz e @ref imprimir_matriz() para a exibir.
 */
void matriz2vetor(int vetor[]){
        int matriz2[TAM][TAM];
	matrizproduto(vetor, matriz2);
	printmatriz(matriz2);
}
/**
 * @brief Calcula a matriz transposta da matriz do produto e imprime o resultado.
 * @details Utiliza @ref calcular_matriz_produto() para obter a matriz original, calcula a transposta ([x][y] -> [y][x]) e mostra-a com @ref imprimir_matriz().
 */
void transpostavetor(int vetor[]){
        int x, y, matriz2[TAM][TAM], transposta[TAM][TAM];
        matrizproduto(vetor, matriz2);
	for (x = 0; x<TAM; x++){
		for( y=0; y< TAM;y++){
			transposta[x][y] = matriz2[y][x];
		}
	}
	printmatriz(transposta);
}
