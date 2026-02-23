# Multiplexagem: Definição e Técnicas

## O que é?
A **Multiplexagem** (ou Multiplexação) é a técnica que permite a transmissão simultânea de vários sinais ou fluxos de dados através de um único meio de comunicação físico (um cabo, uma fibra ótica ou o ar). O objetivo é otimizar a utilização da largura de banda disponível.

* **Multiplexador (MUX):** Dispositivo que combina as várias fontes de entrada num único canal.
* **Desmultiplexador (DEMUX):** Dispositivo que separa os sinais no destino, entregando-os aos seus recetores originais.

---

## Principais Técnicas de Multiplexagem

### 1. FDM (Frequency Division Multiplexing)
* **O que é:** Multiplexagem por Divisão de Frequência.
* **Como funciona:** O canal é dividido em diferentes faixas de frequência. Cada sinal ocupa uma faixa específica (canal) ao mesmo tempo.
* **Exemplo:** Rádio FM, Televisão por cabo.

### 2. TDM (Time Division Multiplexing)
* **O que é:** Multiplexagem por Divisão de Tempo.
* **Como funciona:** O canal é partilhado no tempo. Cada utilizador tem a largura de banda total, mas apenas por um pequeno intervalo de tempo (slot).
* **Exemplo:** Telefonia Digital (E1/T1).

### 3. WDM (Wavelength Division Multiplexing)
* **O que é:** Multiplexagem por Divisão de Comprimento de Onda.
* **Como funciona:** É a versão da FDM aplicada à **fibra ótica**. Utiliza diferentes cores de luz (lasers) para transportar dados diferentes pelo mesmo fio de vidro.
* **Exemplo:** Redes de fibra ótica de longa distância.

### 4. CDM (Code Division Multiplexing)
* **O que é:** Multiplexagem por Divisão de Código.
* **Como funciona:** Cada sinal recebe um código matemático único. Todos os sinais viajam na mesma frequência ao mesmo tempo, mas o recetor consegue isolar o sinal correto usando o código.
* **Exemplo:** Redes móveis 3G.

### 5. Multiplexagem Estatística (STDM)
* **O que é:** Uma evolução do TDM.
* **Como funciona:** Em vez de dar tempo fixo a cada utilizador, o tempo é atribuído dinamicamente apenas a quem tem dados para enviar no momento.
* **Exemplo:** Redes baseadas em pacotes (Internet/Ethernet).
