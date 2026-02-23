void troca(int* a, int* b) {
    int t = *a; *a = *b; *b = t;
}

int partir(int arr[], int baixo, int alto) {
    int pivo = arr[alto]; // Escolhe o último elemento como pivô
    int i = (baixo - 1);

    for (int j = baixo; j < alto; j++) {
        if (arr[j] < pivo) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    troca(&arr[i + 1], &arr[alto]);
    return (i + 1);
}

void quickSort(int arr[], int baixo, int alto) {
    if (baixo < alto) {
        int pi = particionar(arr, baixo, alto);
        quickSort(arr, baixo, pi - 1); // Ordena esquerda
        quickSort(arr, pi + 1, alto);  // Ordena direita
    }
}
//O algoritmo escolhe um número (geralmente o último) para ser o muro,  ele reorganiza o array tudo o que é menor que o pivô vai para a esquerda dele e tudo o que é maior vai para a direita Após esse movimento, o pivô está na sua posição final correta e nunca mais sai dali. O algoritmo agora faz o mesmo processo para o lado esquerdo e para o lado direito do pivô, repetidamente.Complexidade: $O(n \log n)$ em média.
