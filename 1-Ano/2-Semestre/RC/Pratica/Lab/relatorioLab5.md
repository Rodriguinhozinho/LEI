# Relatório de Atividades: Laboratório 5 - Máscaras de Rede e Rotas Estáticas
## 1. Metodologia e Configurações
### 1.1. Endereçamento e Máscaras de Rede
[cite_start]Foram utilizadas diferentes máscaras de sub-rede para otimizar o espaço de endereçamento conforme os requisitos da topologia[cite: 43]:
* [cite_start]**LANs (Redes Locais):** Utilizou-se a máscara /26 (255.255.255.192) e /27 (255.255.255.224)[cite: 43, 73].
* [cite_start]**WANs (Ligações entre Routers):** Utilizou-se a máscara /30 (255.255.255.252), ideal para ligações ponto-a-ponto[cite: 43, 72].

### 1.2. Configuração de Interfaces nos Routers
[cite_start]A configuração envolveu a atribuição de IPs às interfaces LAN e Serial de três routers modelo 2811[cite: 72, 73, 77, 78]:
* [cite_start]**R1:** Interface LAN (192.168.31.1/26) e Interface WAN (192.168.31.65/30)[cite: 73].
* [cite_start]**R2:** Interface LAN (192.168.32.129/26) e Interface WAN (192.168.32.1/30)[cite: 73].
* [cite_start]**R3:** Interface LAN (192.168.30.1/27) e interfaces de ligação aos restantes routers[cite: 73].

## 2. Encaminhamento Estático e Sumarização

### 2.1. Comunicação Bidirecional
[cite_start]Para garantir a conectividade total, foram configuradas rotas de ida e de volta em todos os saltos da rede[cite: 10, 107]. [cite_start]Isto garante que o pacote não só chegue ao destino, mas que o router de destino conheça o caminho de retorno para a origem[cite: 107, 108].

### 2.2. Sumarização de Rotas (Ponto 8.1)
[cite_start]No Router R3, foi calculada uma rota de sumarização para as redes do R1 para reduzir a tabela de encaminhamento[cite: 87, 110, 111]. [cite_start]Através da análise binária das redes, identificaram-se os bits comuns à esquerda para determinar a nova máscara[cite: 112, 114].
* [cite_start]**Resultado do Cálculo:** Rota sumarizada 192.168.31.0 com máscara 255.255.255.128 (/25)[cite: 43, 115, 116].

## 3. Comandos de Encaminhamento Aplicados

| Dispositivo | Comando de Rota Estática | Próximo Salto (Next-Hop) |
| :--- | :--- | :--- |
| **R1** - **R3** | ip route 192.168.30.0 255.255.255.224 192.168.31.66 | Interface do R3 |
| **R1** - **R2** | ip route 192.168.32.128 255.255.255.192 192.168.31.66 | Interface do R3 |
| **R3** - **R1** | ip route 192.168.31.0 255.255.255.128 192.168.31.65 | Interface do R1 |
| **R3** - **R2** | ip route 192.168.32.128 255.255.255.192 192.168.32.1 | Interface do R2 |
| **R2** - **R1** | ip route 192.168.31.0 255.255.255.192 192.168.32.2 | Interface do R3 |
| **R2** - **R3** | ip route 192.168.30.0 255.255.255.224 192.168.32.2 | Interface do R3 |
