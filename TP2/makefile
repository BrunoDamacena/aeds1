CC=gcc
OPCOES_COMPILADOR = 
TODOS_ARQUIVOS_PONTOH = codes/algoritmos.h
TODOS_ARQUIVOS_OBJ = main.o codes/algoritmos.o

%.o: ../%.c $(TODOS_ARQUIVOS_PONTOH)
	$(CC) -o $@ -c $< $(OPCOES_COMPILADOR)

all: $(TODOS_ARQUIVOS_OBJ)
	gcc -o Ordenacao.out $^ $(OPCOES_COMPILADOR)

entrada:
	gcc database/gerador_de_entrada.c -o geradorDeEntrada.out
	clear
	./geradorDeEntrada.out
	clear

run: all
	./Ordenacao.out
	gedit exitlog.txt &

clean:
	rm *.o codes/*.o database/*.o *.out