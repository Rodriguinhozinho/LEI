# Relatório de Configuração: Rede Vendas e Contabilidade
**Simulação:** Cisco Packet Tracer

## 1. Topologia e Endereçamento Lógico
Esta rede foi desenhada para interligar dois departamentos distintos através de um roteador central, permitindo a comunicação entre sub-redes diferentes.

| Dispositivo | IP Address | Subnet Mask | Default Gateway |
| :--- | :--- | :--- | :--- |
| **PC Vendas** | 192.168.10.1 | 255.255.255.0 | 192.168.10.254 |
| **PC Contabilidade** | 172.16.0.1 | 255.255.0.0 | 172.16.255.254 |
| **Router (Interface Vendas)**| 192.168.10.254 | 255.255.255.0 | N/A |
| **Router (Interface Contab.)**| 172.16.255.254 | 255.255.0.0 | N/A |

---

## 2. Perguntas e Respostas de Aprendizagem

### Na configuração do roteador, eu dou o IP e a máscara do outro PC?
**Não.** No roteador, configuramos o IP que servirá de **Gateway** para aquela rede específica. Cada porta do roteador deve ter um IP que pertença à mesma família dos PCs ligados a ela, mas deve ser um endereço único para a porta do roteador.

### Se as redes são diferentes, não podiam estar no mesmo Switch?
Fisicamente sim, mas logicamente estariam isoladas. Usamos dois switches para separar os **Domínios de Broadcast**. Isso garante que o tráfego local de Vendas (como buscas por impressoras) não chegue à rede da Contabilidade, mantendo a performance e a organização.

### Como apenas tenho dois PCs, não poderia ligar diretamente ao Roteador?
**Sim, funcionaria.** No entanto, usamos switches por uma questão de **escalabilidade**. Na vida real, um departamento terá vários PCs; o switch permite expandir o número de dispositivos usando apenas uma porta do roteador.

---

## 3. A Lógica da Analogia (Fluxo de Negócio)
Esta rede simula o fluxo de dados real de uma empresa:

> **A Analogia:** O **PC de Vendas** regista a quantidade de itens vendidos. Para que o negócio seja concluído, essa informação viaja até ao **PC da Contabilidade** para processar o dinheiro recebido. O **Roteador** funciona como o "estafeta" ou a "ponte" entre as salas: ele recebe os dados de uma rede e entrega-os na outra. O **Switch** funciona como o corredor que concentra todas as secretárias de um departamento antes da porta de saída (Gateway).

---

## 4. Resolução de Problemas (Troubleshooting)

* **Triângulos Vermelhos no Roteador:** Indicam que a porta está "Down". Resolvido com o comando `no shutdown` na interface.
* **Erro "% Invalid input detected at '^' marker":** Ocorre ao digitar comandos fora do modo de configuração correto. É preciso estar no modo `(config-if)#` para atribuir IPs.
* **Luz Laranja no Switch:** É o estado de aprendizagem do protocolo STP. Pode ser acelerado usando o botão **"Fast Forward Time"** no canto inferior esquerdo do simulador.

---

## 5. Comandos CLI do Roteador (Resumo)
```bash
# Configuração da Interface de Vendas (Exemplo g0/0)
Router> enable
Router# configure terminal
Router(config)# interface g0/0
Router(config-if)# ip address 192.168.10.254 255.255.255.0
Router(config-if)# no shutdown

# Configuração da Interface de Contabilidade (Exemplo g0/1)
Router(config-if)# interface g0/1
Router(config-if)# ip address 172.16.255.254 255.255.0.0
Router(config-if)# no shutdown
