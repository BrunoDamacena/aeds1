#	Makefile para o programa

entrada:
	gcc gerador_de_entrada/gerador_de_entrada.c -o gerador_de_entrada.out
	./gerador_de_entrada.out
	gedit entrada.txt &

tentativa_e_erro:
	gcc codes/tentativa_e_erro.c -o O_Problema_Da_Mochila_TENTATIVA_E_ERRO.out
	./O_Problema_Da_Mochila_TENTATIVA_E_ERRO.out
	gedit saida_tentativa_e_erro.txt &

guloso:
	gcc codes/guloso.c -o O_Problema_Da_Mochila_GULOSO.out
	./O_Problema_Da_Mochila_GULOSO.out
	gedit saida_gulosa.txt &

all:
	gcc codes/tentativa_e_erro.c -o O_Problema_Da_Mochila_TENTATIVA_E_ERRO.out
	gcc codes/guloso.c -o O_Problema_Da_Mochila_GULOSO.out
	./O_Problema_Da_Mochila_GULOSO.out
	./O_Problema_Da_Mochila_TENTATIVA_E_ERRO.out
	gedit saida_gulosa.txt &
	gedit saida_tentativa_e_erro.txt &

clean:
	rm *.out saida_gulosa.txt saida_tentativa_e_erro.txt
