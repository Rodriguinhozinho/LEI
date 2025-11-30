compilador = gcc
executavel = main-PL403.exe
objetos = main-PL403.o functions-PL403.o
saidahtml = html
.PHONY: all clean documentos executar

all: executar documentos

$(executavel) : $(objetos)
	$(compilador) -o $@ $^ -lm

%.o : %.c
	$(compilador) -c $<

documentos:
	@echo "A gerar documentação.."
	doxygen Doxyfile

executar: $(executavel)
	@echo "Programa: executando!"
	./$(executavel)

clean: limpar remover_documentos

limpar:
	rm -f $(objetos)
	rm -f $(executavel)
	@echo "Programa: removendo executavél e objetos!"
remover_documentos:
	rm -rf $(saidahtml)
	@echo "Programa: removendo documentação!"





