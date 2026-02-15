/** 
 * @file functions-PL403.h
 * @brief Tem as declarações de todas as funções usadas para manipular os vetores e matrizes.
 * @details Este cabeçalho define a constante TAM (tamanho do vetor/matriz) e declara o cabeçalho de
 * todas as funções de operação usadas no programa.
 */
#define TAM 14

/**
 * @brief Ordena o vetor por ordem crescente com método Bubble Sort.
 */
void ordenarvetor(int vetor[]);
/**
 * @brief Imprime uma matriz de tamanho TAM x TAM.
 */
void printmatriz(int matriz[TAM][TAM]);
/**
 * @brief Calcula a matriz de produto do vetor original pelo vetor ordenado.
 */
void matrizproduto(int vetor[], int matrizresultante[TAM][TAM]);
/**
 * @brief Cria e ordena o vetor simétrico dos elementos.
 */
void simetricovetor(int vetor[]);

/**
 * @brief Soma os elementos da primeira metade do vetor com a segunda.
 */
void somavetor(int vetor[]);

/**
 * @brief Mostra os elementos que estão em posições múltiplas de 3.
 */
void multiplovetor(int vetor[]);

/**
 * @brief Mostra um elemento aleatório do vetor.
 */
void aleatoriovetor(int vetor[]);

/**
 * @brief Cria uma matriz TAMxTAM com permutações do vetor.
 */
void matrizvetor(int vetor[]);

/** 
 * @brief Calcula a raiz quadrada de cada elemento do vetor.
 */
void raizvetor(int vetor[]);

/**
 * @brief Mostra o menu de ajuda do programa.
 */
void ajuda();

/**
 * @brief Mistura metade do vetor original com um novo vetor introduzido pelo utilizador.
 */
void misturavetor(int vetor[]);

/**
 * @brief Calcula o Máximo Divisor Comum (MDC) de dois elementos consecutivos do vetor.
 */
void mdcvetor(int vetor[]);

/**
 * @brief Cria uma matriz que resulta do produto do vetor original com o vetor ordenado.
 */
void matriz2vetor(int vetor[]);

/**
 * @brief Cria a matriz transposta da matriz resultante do produto do vetor original com o vetor ordenado.
 */
void transpostavetor(int vetor[]);

