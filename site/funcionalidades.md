# Funcionalidades Principais do Projeto
@page funcionalidades

## Funcionalidades

Funcionalidades do programa:


### Manipulação de Vetores

O programa oferece várias operações com o vetor principal.

#### 1.1. Ordenação e Simétrico

* **Ordenar Vetores:** A função @ref ordenarvetor() ordena os elementos do vetor em **ordem crescente** utilizando o método *Bubble Sort*. Esta função é usada internamente por várias outras operações.
* **Vetor Simétrico:** A função @ref simetricovetor() calcula e exibe o **vetor simétrico** (inverso dos sinais) do vetor original, garantindo que o resultado é apresentado de forma ordenada.

#### 1.2. Operações de Soma e Múltiplos

* **Soma por Metades:** A função @ref somavetor() soma os elementos da **primeira metade** do vetor com os correspondentes da **segunda metade**.
* **Múltiplos de 3:** A função @ref multiplovetor() mostra apenas os elementos que se encontram em **posições múltiplas de 3**.
* **Elemento Aleatório:** A função @ref aleatoriovetor() retorna um **elemento aleatório** do vetor, usando uma semente (`seed`) baseada no tempo real para garantir que o número devolvido seja diferente em cada execução.

#### 1.3. Outras operações

* **Raiz Quadrada:** A função @ref raizvetor() calcula a **raiz quadrada** de cada elemento, ignorando valores negativos, que são marcados como inválidos.
* **Mistura de Vetores:** A função @ref misturavetor() cria um novo vetor, misturando a **primeira metade do vetor original** com a **segunda metade de um novo vetor** introduzido pelo utilizador (com verificação de entrada valor entre -3 e 27).
* **Máximo Divisor Comum (MDC):** A função @ref mdcvetor() calcula o **MDC entre dois valores consecutivos** do vetor. Valores negativos são trocados para o seu valor absoluto para o fazer o cálculo.


### 2.Geração e Transposição de Matrizes

O programa tem funções dedicadas a criar e manipulação de matrizes de tamanho $TAM \times TAM$.

#### 2.1. Matrizes

* **Matriz com Permutações:** A função @ref matrizvetor() cria uma matriz com permutações do vetor original.
* **Matriz de Produto:** A função @ref matrizproduto() é uma função auxiliar que gera uma matriz onde cada elemento $[x][y]$ é o **produto do elemento $x$ do vetor original com o elemento $y$ do vetor ordenado**.
* **Impressão da Matriz Produto:** A função @ref matriz2vetor() utiliza a função auxiliar para calcular a matriz e a função @ref printmatriz() para exibir o resultado.
 
#### 2.2. Transposição
 
* **Matriz Transposta:** A função @ref transpostavetor() recorre á @ref matrizproduto() e calcula a **matriz transposta** dessa matriz.


### 3. Ajuda do Programa

A função @ref ajuda() exibe um **menu de ajuda** com todas as opções e o funcionamento.

