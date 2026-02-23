### Estrutura da Trama Ethernet (IEEE 802.3 / Ethernet II)

| Ordem | Campo | Tamanho (Bytes) | Descrição |
| :--- | :--- | :--- | :--- |
| **1º** | Preâmbulo | 7 Bytes | Sincronização de relógio (bits alternados 101010...). |
| **2º** | SFD (Start Frame Delimiter) | 1 Byte | Indica o início real da trama (10101011). |
| **3º** | MAC de Destino | 6 Bytes | Endereço físico do receptor (48 bits). |
| **4º** | MAC de Origem | 6 Bytes | Endereço físico do emissor (48 bits). |
| **5º** | EtherType / Tamanho | 2 Bytes | Identifica o protocolo da camada superior (ex: IPv4). |
| **6º** | Dados (Payload) | 46 - 1500 Bytes | Onde viaja o pacote IP (com preenchimento se < 46). |
| **7º** | FCS (Frame Check Sequence) | 4 Bytes | Verificação de erros via CRC (Cyclic Redundancy Check). |

**Nota:** O tamanho total de uma trama Ethernet padrão varia entre **64 e 1518 bytes** (sem contar o Preâmbulo e o SFD).
