
## 1. O que são os Octetos?
Um endereço IPv4 é um número de **32 bits**. Para facilitar a leitura, dividimos esses 32 bits em **4 blocos de 8 bits**. Cada bloco de 8 bits é chamado de **Octeto**.

* **1 Octeto** = 8 bits (8 interruptores de `0` ou `1`).
* **Valor Decimal:** Cada octeto pode representar números de **0 a 255**.
* **Exemplo:** No IP `192.168.1.1`, temos quatro octetos: `192`, `168`, `1` e `1`.



---

## 2. A Divisão: Rede vs. Host
A função dos octetos é dividida entre identificar a **Rede** (o grupo/rua) e o **Host** (o dispositivo/casa). As classes clássicas definem onde essa "fronteira" é cortada:

| Classe | Estrutura de Octetos | Foco Principal |
| :--- | :--- | :--- |
| **Classe A** | `[Rede] . [Host] . [Host] . [Host]` | **Muitos Hosts:** Prioriza o número de dispositivos por rede (16M+). |
| **Classe B** | `[Rede] . [Rede] . [Host] . [Host]` | **Equilíbrio:** Redes de médio porte (65k hosts). |
| **Classe C** | `[Rede] . [Rede] . [Rede] . [Host]` | **Muitas Redes:** Prioriza a criação de múltiplas redes pequenas (254 hosts). |

---

## 3. Impacto na Segurança

A distribuição de quantos octetos pertencem à rede e quantos ao host afeta diretamente a resiliência do sistema:

### A. Segmentação e Isolamento (Mais Octetos de Rede)
Quanto mais octetos reservamos para a **Rede** (como na Classe C), mais fácil é aplicar o princípio do **menor privilégio**:
* **Isolamento de Tráfego:** Podes colocar dispositivos vulneráveis (como câmaras IoT) num octeto de rede diferente (`192.168.2.x`) daquele onde estão os teus servidores (`192.168.1.x`).
* **Controlo de Barreiras:** Routers e Firewalls filtram tráfego entre redes. Se todos os computadores estiverem na mesma rede (mesmos octetos de rede), a firewall interna é muitas vezes ignorada e o ataque espalha-se livremente.

### B. Domínios de Broadcast (Mais Octetos de Host)
Redes com muitos octetos para **Host** (como a Classe A) têm "Domínios de Broadcast" gigantes:
* **Vulnerabilidade:** Um único computador infetado pode enviar pacotes maliciosos para milhões de outros dispositivos simultaneamente através de mensagens de *broadcast*.
* **Desempenho:** O excesso de "ruído" na rede facilita ataques de negação de serviço (DoS) e dificulta a monitorização de comportamentos anómalos.

### C. Visibilidade (Reconhecimento)
* Em redes pequenas (**mais octetos de rede**), um atacante consegue fazer um varrimento (scan) completo rapidamente, mas o ataque fica contido apenas àquela "sala" específica.
* A segurança moderna utiliza **VLANs** para forçar a separação dos octetos de rede logicamente, mesmo que os computadores estejam todos ligados ao mesmo equipamento físico.



---

## 4. Resumo de Segurança
> **Regra de Ouro:** Redes menores (mais bits/octetos dedicados à Rede) são inerentemente mais seguras. Elas reduzem o **raio de explosão** de um ataque: se uma rede for invadida, as outras redes (definidas por outros octetos) permanecem protegidas por routers e firewall.s.
