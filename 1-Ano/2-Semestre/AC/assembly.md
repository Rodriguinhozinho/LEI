| Palavra-Chave | Categoria | Descrição | Exemplo |
|:--- |:--- |:--- |:--- |
| **MOV** | Instrução | Move (copia) dados de um lugar para outro | `mov eax, 10` |
| **ADD / SUB** | Instrução | Soma ou Subtrai valores | `add ebx, eax` |
| **INC / DEC** | Instrução | Incrementa ou Decrementa o valor em 1 | `inc ecx` |
| **CMP** | Instrução | Compara dois valores para definir flags | `cmp eax, 0` |
| **JMP** | Fluxo | Salto incondicional para um label | `jmp loop_start` |
| **JE / JZ** | Fluxo | Salta se for igual / se for zero | `je label_fim` |
| **JNE / JNZ** | Fluxo | Salta se não for igual / não for zero | `jnz loop_start` |
| **CALL / RET** | Fluxo | Chama uma função / Retorna da função | `call minha_func` |
| **PUSH / POP** | Pilha | Coloca ou retira um valor da pilha (Stack) | `push eax` |
| **DB / DW / DD** | Dados | Define bytes, words (16 bits) ou double words (32 bits) | `msg db 'Oi', 0` |
| **FORMAT** | Diretiva | Define o formato do arquivo de saída (PE, ELF, Binary) | `format PE GUI` |
| **SECTION** | Diretiva | Define seções do programa (código, dados, imports) | `section '.data' data` |
| **INCLUDE** | Diretiva | Inclui arquivos externos ou macros | `include 'win32a.inc'` |
| **INVOKE** | Macro | Chama funções da API (Windows) com argumentos | `invoke ExitProcess, 0` |
| **ENTRY** | Diretiva | Define o ponto de início da execução | `entry start` |
