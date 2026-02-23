#include <stdio.h>

//Bubble sort pior caso de ordenaçao, compara o primeiro elemento com o segundo se o primeiro for maior que o segundo eles trocam de lugar e vai repetindo segundo com o terceiro terceriro com o quarto até ao fim do array
// O(n^2)
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    int trocou; // Flag para otimização

    for (i = 0; i < n - 1; i++) {
        trocou = 0; // Resetamos a flag a cada nova passada

        // O 'n - i - 1' evita comparar elementos que já estão ordenados no final
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Realiza a troca
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                trocou = 1; // Se houve troca, o array ainda não estava pronto
            }
        }

        // Se depois de percorrer o array não houve trocas, ele já está ordenado
        if (trocou == 0) {
            break;
        }
    }
}

int main() {
    int arr[] = {5, 1, 4, 2, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original: ");
    for(int i=0; i<n; i++) printf("%d ", arr[i]);

    bubbleSort(arr, n);

    printf("\nArray ordenado (Bubble Sort): ");
    for(int i=0; i<n; i++) printf("%d ", arr[i]);

    return 0;
}
//com a flag trocou e quando o array esta quase organizado ou ja mesmo organizado o algoritmo torna-se O(n) pois o computador le o array 1 vez e ve que nada trocou
