# Relatório de Atividades: Laboratório 5 - Máscaras de Rede e Rotas Estáticas
## 1. Metodologia e Configurações
### 1.1. Endereçamento e Máscaras de Rede
Foram utilizadas diferentes máscaras de sub-rede para otimizar o espaço de endereçamento conforme os requisitos da topologia:
* **LANs (Redes Locais):** Utilizou-se a máscara /26 (255.255.255.192) e /27 (255.255.255.224)
* **WANs (Ligações entre Routers):** Utilizou-se a máscara /30 (255.255.255.252), ideal para ligações ponto-a-ponto.

### 1.2. Configuração de Interfaces nos Routers
A configuração envolveu a atribuição de IPs às interfaces LAN e Serial de três routers modelo 2811:
* **R1:** Interface LAN (192.168.31.1/26) e Interface WAN (192.168.31.65/30).
* **R2:** Interface LAN (192.168.32.129/26) e Interface WAN (192.168.32.1/30).
* **R3:** Interface LAN (192.168.30.1/27) e interfaces de ligação aos restantes routers.

## 2. Encaminhamento Estático e Sumarização

### 2.1. Comunicação Bidirecional
Para garantir a conectividade total, foram configuradas rotas de ida e de volta em todos os saltos da rede. Isto garante que o pacote não só chegue ao destino, mas que o router de destino conheça o caminho de retorno para a origem.

### 2.2. Sumarização de Rotas (Ponto 8.1)
No Router R3, foi calculada uma rota de sumarização para as redes do R1 para reduzir a tabela de encaminhamento. Através da análise binária das redes, identificaram-se os bits comuns à esquerda para determinar a nova máscara.
**Resultado do Cálculo:** Rota sumarizada 192.168.31.0 com máscara 255.255.255.128 (/25).

## 3. Comandos de Encaminhamento Aplicados

| Dispositivo | Comando de Rota Estática | Próximo Salto (Next-Hop) |
| :--- | :--- | :--- |
| **R1** - **R3** | ip route 192.168.30.0 255.255.255.224 192.168.31.66 | Interface do R3 |
| **R1** - **R2** | ip route 192.168.32.128 255.255.255.192 192.168.31.66 | Interface do R3 |
| **R3** - **R1** | ip route 192.168.31.0 255.255.255.128 192.168.31.65 | Interface do R1 |
| **R3** - **R2** | ip route 192.168.32.128 255.255.255.192 192.168.32.1 | Interface do R2 |
| **R2** - **R1** | ip route 192.168.31.0 255.255.255.192 192.168.32.2 | Interface do R3 |
| **R2** - **R3** | ip route 192.168.30.0 255.255.255.224 192.168.32.2 | Interface do R3 |
