# Modos de Transmissão (Direcionalidade)

Os modos de transmissão definem o sentido do fluxo de dados entre dois dispositivos numa rede.

### 1. Simplex
* **O que é:** Transmissão num único sentido (unidirecional).
* **Como funciona:** Um dispositivo é estritamente o emissor e o outro é estritamente o recetor. Não há canal de retorno.
* **Exemplos:** * Televisão e Rádio (transmissão via ar).
    * Teclado para o Computador.
    * Sensores simples que apenas enviam dados.

### 2. Half-Duplex (Semi-Duplex)
* **O que é:** Transmissão nos dois sentidos, mas **não em simultâneo**.
* **Como funciona:** Ambos podem enviar e receber, mas apenas um de cada vez. Se ambos tentarem enviar ao mesmo tempo, ocorre uma colisão.
* **Exemplos:** * Walkie-talkies (tens de soltar o botão para ouvir).
    * Redes Wi-Fi (o canal é partilhado).
    * Ethernet antigo com Hubs (CSMA/CD).

### 3. Full-Duplex (Duplex Total)
* **O que é:** Transmissão nos dois sentidos **em simultâneo**.
* **Como funciona:** Existem canais separados para envio (TX) e receção (RX). É a forma mais eficiente de comunicação.
* **Exemplos:** * Chamada telefónica (podes falar e ouvir ao mesmo tempo).
    * Redes Ethernet modernas com Switches.
    * Ligações de Internet de Fibra Ótica.
