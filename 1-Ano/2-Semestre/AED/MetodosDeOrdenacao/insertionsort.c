#include <stdio.h>

 //INSERTION SORT (Ordenação por Inserção)
 //Como funciona: Percorre o array e, para cada elemento, move-o para trás até encontrar sua posição correta entre os elementos já ordenados
 //Complexidade O(n^2) - menos trocas que o bubble
// Função de ordenação
void insertionSort(int arr[], int n) {
    int i, chave, j;
    
    // Começamos do segundo elemento (índice 1)
    for (i = 1; i < n; i++) {
        chave = arr[i]; // O elemento atual que queremos posicionar
        j = i - 1;

           //Enquanto 'j' for um índice válido e o elemento na posição 'j' for maior que a 'chave', empurramos o elemento para a frente
        while (j >= 0 && arr[j] > chave) {
            arr[j + 1] = arr[j]; // Deslocamento
            j = j - 1;
        }
        
        //colocamos a chave na posição correta.
        arr[j + 1] = chave;
        
        // so para ver o array a cada inserção 
        printf("Passo %d: ", i);
        for(int k=0; k<n; k++) printf("%d ", arr[k]);
        printf("\n");
    }
}

// Função auxiliar para imprimir o array final
void imprimirArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Exemplo com array desordenado
    int dados[] = {12, 11, 13, 5, 6};
    int n = sizeof(dados) / sizeof(dados[0]);

    printf("Array Original: ");
    imprimirArray(dados, n);
    insertionSort(dados, n);
    printf("Array Ordenado: ");
    imprimirArray(dados, n);

    return 0;
}
//a chave no inicio é o segundo elemento e ele vai olhar para o de tras e ver se é maior se sim troca - o e a chave passa a ser o proximo elemento 
// ou seja a chave que é o elemento de comparaçao vai passar a ser o elemento da direita a cada rodada do for começando inicialemente sendo o segundo elemento
