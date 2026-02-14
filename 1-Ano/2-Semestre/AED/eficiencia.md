# Rankings de Eficiência (Notação Big-O)

A Notação **Big-O** é a linguagem universal em Algoritmos e Estruturas de Dados (AED) para descrever a eficiência de um algoritmo em termos de tempo de execução ou espaço de memória, focando-se no **pior caso** ($n \to \infty$).



---

## Tabela de Comparação

Do mais eficiente para o menos eficiente:

| Notação | Nome | Performance | Descrição |
| :--- | :--- | :--- | :--- |
| **O(1)** | **Constante** | 🚀 Excelente | O tempo de execução não depende do tamanho dos dados. |
| **O(log n)** | **Logarítmica** | ✅ Muito Boa | O problema é dividido ao meio a cada passo. |
| **O(n)** | **Linear** | ⚖️ Aceitável | O tempo cresce proporcionalmente à entrada. |
| **O(n log n)** | **Linearítmica** | 📉 Moderada | Padrão para algoritmos de ordenação eficientes. |
| **O(n²)** | **Quadrática** | ⚠️ Má | Loops aninhados. Muito lento para n grande. |

---

## Exemplos Práticos

### 1. Constante O(1)
Ocorre quando acedemos diretamente a uma posição de memória.

```c
int get_first_element(int arr[]) {
    return arr[0]; // Operação imediata
}

```

---

# Quick Sort vs. Bubble Sort

Em AED, comparar estes dois é a melhor forma de entender como a estratégia de **"Dividir para Conquistar"** vence a **"Força Bruta"**.

## Comparação de Complexidade

| Algoritmo | Melhor Caso | Caso Médio | Pior Caso | Estratégia |
| --- | --- | --- | --- | --- |
| **Bubble Sort** | O(n) | O(n²) | O(n²) | Comparações adjacentes simples. |
| **Quick Sort** | O(n log n) | O(n log n) | O(n²) | Dividir para Conquistar (Pivô). |

---

## Por que é que o Quick Sort é tão superior?

### 1. O Problema do Bubble Sort O(n²)

O Bubble Sort é "preguiçoso". Ele só move um elemento uma posição de cada vez. Se o menor número estiver no fim, terá de fazer milhares de trocas.

### 2. A Magia do Quick Sort O(n log n)

O Quick Sort usa um **Pivô** para dividir o array em dois.

* Números menores que o pivô à esquerda.
* Números maiores que o pivô à direita.

**A relação com o Logaritmo:** Ao dividir o problema sucessivamente, a "altura" da árvore de decisões é **log n**. Em cada nível, processamos **n** elementos.

---

## Teste de Simulação (100.000 itens)

* **Bubble Sort:** Demoraria aproximadamente **15 a 20 minutos**.
* **Quick Sort:** Demoraria aproximadamente **0.02 segundos**.

---
