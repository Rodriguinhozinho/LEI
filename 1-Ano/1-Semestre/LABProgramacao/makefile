compilador = gcc
executavel = main-PL403.exe
objetos = main-PL403.o functions-PL403.o
saidahtml = html

.PHONY: all clean documentacao executar

all: $(executavel) documentacao

$(executavel) : $(objetos)
	$(compilador) -o $@ $^ -lm

%.o : %.c
	$(compilador) -c $<

documentacao:
	@echo "A gerar documentação.."
	doxygen Doxyfile

executar: $(executavel)
	@echo "Programa: executando!"
	./$(executavel)

clean: limpar limpardocumentacao

limpar:
	rm -f $(objetos)
	rm -f $(executavel)
	@echo "Programa: removendo executável e objetos!"

limpardocumentacao:
	rm -rf $(saidahtml)
	@echo "Programa: removendo documentação!"
