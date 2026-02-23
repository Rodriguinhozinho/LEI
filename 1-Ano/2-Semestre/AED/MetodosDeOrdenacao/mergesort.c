// Função auxiliar para juntar as duas metades de forma ordenada
void merge(int arr[], int esq, int meio, int dir) {
    int i, j, k;
    int n1 = meio - esq + 1;
    int n2 = dir - meio;

    int L[n1], R[n2]; // Arrays temporários

    for (i = 0; i < n1; i++) L[i] = arr[esq + i];
    for (j = 0; j < n2; j++) R[j] = arr[meio + 1 + j];

    i = 0; j = 0; k = esq;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) { arr[k] = L[i]; i++; }
        else { arr[k] = R[j]; j++; }
        k++;
    }
    while (i < n1) { arr[k] = L[i]; i++; k++; }
    while (j < n2) { arr[k] = R[j]; j++; k++; }
}

void mergeSort(int arr[], int esq, int dir) {
    if (esq < dir) {
        int meio = esq + (dir - esq) / 2;
        mergeSort(arr, esq, meio);     // Divide a esquerda
        mergeSort(arr, meio + 1, dir); // Divide a direita
        merge(arr, esq, meio, dir);    // Junta tudo ordenado
    }
}
//O algoritmo parte o array ao meio e depois parte as metades ao meio, e assim por diante, até que cada número esteja sozinho (um array de 1 elemento está tecnicamente ordenado) depois o algoritmo começa a juntar os pares. Entre dois números, ele vê quem é menor e coloca os em ordem num array temporario depois Ele vai subindo o nível, juntando grupos de 2 em 2, depois 4 em 4, sempre comparando as frentes de cada grupo e "intercalando" os valores.Complexidade: $O(n \log n)$ (muito rápido).Ele gasta memória extra para criar os arrays temporários durante a fusão, mas garante a mesma velocidade mesmo que o array esteja totalmente invertido.
