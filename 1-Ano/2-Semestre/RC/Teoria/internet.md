# O que é a Internet? (VISAO NUTS N BOLTS)

A Internet pode ser descrita de duas perspectivas complementares: uma baseada nos componentes físicos e outra nos serviços

---

## 1. Descrição de "Porcas e Parafusos" (Nuts-and-Bolts)
Esta visão descreve a Internet como uma infraestrutura de hardware e software que interliga dispositivos em todo o mundo.

* **Sistemas Finais (End Systems) ou Hosts:** São os dispositivos que "habitam" a borda da rede (PCs, smartphones, servidores, dispositivos IoT). Eles executam aplicações de rede.
* **Enlaces de Comunicação (Communication Links):** Os caminhos físicos por onde os dados viajam. Podem ser:
    * Fios de cobre (DSL, Ethernet).
    * Fibra ótica.
    * Rádio (Wi-Fi, 4G/5G).
    * Satélite.
* **Comutadores de Pacotes (Packet Switches):** Dispositivos que recebem pacotes de dados e os encaminham para o destino. Os principais são os **Routers** (usados no núcleo da rede) e os **Switches**.
* **Rede de Redes:** A Internet não é uma rede única, mas uma interconexão de vários ISPs (Provedores de Serviços de Internet) locais, regionais e globais.



---

## 2. Descrição Baseada em Serviços
Esta visão foca na funcionalidade que a rede oferece às aplicações.

* **Infraestrutura para Aplicações Distribuídas:** A Internet permite que aplicações como a Web, streaming de vídeo, e-mail e jogos funcionem trocando dados entre sistemas finais distantes.
* **Interface de Programação de Aplicações (API):** A rede fornece um "gancho" ou conjunto de regras para que o software num computador diga à Internet para entregar dados a um software noutro computador. 
* **Analogia do Serviço Postal:** Kurose compara a Internet ao correio: você coloca uma carta (dados) num envelope com um endereço (IP) e a infraestrutura garante a entrega.

---

## 3. O que é um Protocolo?
Para Kurose, o protocolo é o coração da comunicação em rede. Sem ele, os dispositivos não saberiam como interpretar os sinais recebidos.

> **Definição Formal:** Um **protocolo** define o **formato** e a **ordem** das mensagens enviadas e recebidas entre entidades de rede, bem como as **ações** tomadas na transmissão ou recebimento de uma mensagem.

### Exemplos de Protocolos:
* **TCP (Transmission Control Protocol):** Garante que os dados cheguem sem erros e na ordem correta (estabelece uma "conexão").
* **IP (Internet Protocol):** Define como os pacotes são endereçados e roteados pela rede.
* **HTTP (HyperText Transfer Protocol):** Define como o seu browser solicita uma página web a um servidor.



---

## 4. A Estrutura da Rede (Network Structure)
Kurose divide o estudo da rede em três partes:
1.  **Borda da Rede (Network Edge):** Onde estão os hosts e as aplicações.
2.  **Rede de Acesso (Access Network):** O meio físico que liga o host ao seu primeiro roteador (ex: o Wi-Fi da sua casa).
3.  **Núcleo da Rede (Network Core):** A malha de roteadores interconectados que formam a espinha dorsal da Internet.

