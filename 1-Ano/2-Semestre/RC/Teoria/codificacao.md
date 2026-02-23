
# Exemplos de Codificação na Camada Física

A codificação na Camada Física transforma bits (0s e 1s) em sinais elétricos, óticos ou eletromagnéticos que podem viajar pelo meio de transmissão.

### 1. Codificação Manchester
* **O que é:** Uma codificação onde cada bit tem pelo menos uma transição no meio do intervalo.
* **Funcionamento:** * O bit `0` é representado por uma transição de alto para baixo.
    * O bit `1` é representado por uma transição de baixo para alto.
* **Aplicação:** Utilizada no padrão **Ethernet 10Base-T** original.

### 2. Codificação NRZ (Non-Return to Zero)
* **O que é:** A forma mais simples de codificação.
* **Funcionamento:** * O nível de tensão é constante durante todo o intervalo do bit.
    * `1` costuma ser tensão alta e `0` tensão baixa (ou zero).
* **Aplicação:** Comunicações série simples (RS-232) e ligações óticas básicas.

### 3. Codificação NRZI (Non-Return to Zero Inverted)
* **O que é:** Uma variação do NRZ onde a transição (ou falta dela) define o bit.
* **Funcionamento:** O sinal muda de estado se o bit for `1` e mantém o estado se for `0`.
* **Aplicação:** Utilizada em dispositivos **USB** e em redes **FDDI**.

### 4. Codificação MLT-3 (Multi-Level Transmit 3)
* **O que é:** Utiliza três níveis de tensão (-1, 0, +1).
* **Funcionamento:** O sinal cicla entre os três níveis apenas quando o bit é `1`. Isso reduz a frequência necessária no cabo.
* **Aplicação:** É o padrão para **Fast Ethernet (100Base-TX)** sobre cabos de par entrançado.

### 5. Codificação 4B/5B e 8B/10B
* **O que é:** Codificação de bloco (mapeamento).
* **Funcionamento:** Um grupo de 4 bits é convertido num grupo de 5 bits antes de ser enviado. Isso garante que nunca existam longas sequências de zeros ou uns seguidos, facilitando a sincronização.
* **Aplicação:** **Fast Ethernet**, **Gigabit Ethernet** e **SATA**.
