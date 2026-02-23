void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;

    // Move o limite do sub-array não ordenado
    for (i = 0; i < n - 1; i++) {
        min_idx = i; // Assume que o atual é o menor

        // Procura o menor elemento no restante do array
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        // Troca o menor encontrado com o primeiro elemento da rodada
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}
//O algoritmo começa no primeiro índice e percorre toda a lista à frente para encontrar qual é o menor número absoluto,quando encontra esse campeao, ele troca o de lugar com o elemento da posição atual, o algoritmo avança para a segunda posição e repete a busca no restante da lista. Diferente do Bubble Sort (que troca sempre), o Selection faz no máximo 1 troca por volta.Complexidade: $O(n^2)$ sempre , ideal para: Sistemas onde "escrever" dados é muito mais caro que "ler" dados (ex: memórias Flash antigas)
