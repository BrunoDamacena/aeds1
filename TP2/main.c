/************************************************
LAED1 - Trabalho Pratico 2
Aluno: Bruno Nascimento Damacena
Matricula: 201622040139
Descricao do programa: Funcao principal
Data: 10/11/2017
************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "codes/algoritmos.h"

#define tipoMax 4
#define tamanhoMaximo 1000000
#define quant_alg 6

int main(){
    //inicializa as variaveis
    TipoVetor vetorOriginal;
    FILE *entrada;
    FILE *exitlog;
    clock_t tinicial, tfinal;
    clock_t titotal, tftotal;
    double tempototal;
    int iterador, tamanho, tipo;

    //abre o arquivo que ira salvar as estatisticas do programa
    exitlog = fopen("exitlog.txt","wt");
    if(exitlog == NULL){
        printf("Erro: Nao foi possivel criar o arquivo de log. Encerrando programa.\n");
        return -1;
    }
    titotal=clock();
    for(tipo=1;tipo<=tipoMax;tipo++){ //percorre todas as pastas do banco de dados
        if(tipo==1) fprintf(exitlog,"Executando em vetor com as chaves distribuidas de forma aleatoria:\n");
        else if(tipo==2) fprintf(exitlog,"Executando em vetor com as chaves quase ordenadas:\n");
        else if(tipo==3) fprintf(exitlog,"Executando em vetor com as chaves ordenadas:\n");
        else if(tipo==4) fprintf(exitlog,"Executando em vetor com as chaves inversamente ordenadas:\n");
        for(tamanho=10;tamanho<=tamanhoMaximo;tamanho*=10){ //percorre todos os arquivos da pasta
            printf("Executando testes...\n");
            entrada = abreArquivo(tipo,tamanho);
            if(entrada==NULL){ //caso nao consiga abrir o arquivo, encerra o programa
                printf("Erro: Nao foi possivel obter acesso ao banco de dados. Encerrando programa.\n");        
                return -1;
            }
            for(n=0;!feof(entrada);n++) fscanf(entrada,"%d",&vetorOriginal[n+1].Chave); //preenche o vetor com as chaves do arquivo
            fclose(entrada); //fecha o arquivo
            fprintf(exitlog,"\nTempos de execucao para o algoritmo de ordenacao no vetor de tamanho %d.\n\n",n);
            for(iterador=0;iterador<quant_alg;iterador++){
                Copia(vetorOriginal,A,n); //copia o vetor, para nao perder a informacao do vetor original. É menos custoso do que ler do arquivo.
                if(iterador==0){ //primeiro testa o BubbleSort
                    tinicial=clock();
                    BubbleSort(&A[0],n);
                    if(Testa(&A[0],n)){
                        tfinal=clock();
                        fprintf(exitlog,"O vetor foi ordenado com sucesso utilizando o BubbleSort. Tempo de execucao de %ld ms.\n",(tfinal-tinicial)*1000/CLOCKS_PER_SEC);
                        printf("BubbleSort: V\n");
                    }
                    else{
                        fprintf(exitlog,"O vetor nao foi ordenado utilizando o BubbleSort.\n");
                        printf("BubbleSort: X\n");
                    }
                }
                else if(iterador==1){ //depois testa o InsertionSort
                    tinicial=clock();
                    InsertionSort(&A[0],n);
                    if(Testa(&A[0],n)){
                        tfinal=clock();
                        fprintf(exitlog,"O vetor foi ordenado com sucesso utilizando o InsertionSort. Tempo de execucao de %ld ms.\n",(tfinal-tinicial)*1000/CLOCKS_PER_SEC);
                        printf("InsertionSort: V\n");
                    }
                    else{
                        fprintf(exitlog,"O vetor nao foi ordenado utilizando o InsertionSort.\n");
                        printf("InsertionSort: X\n");
                    } 
                }
                else if(iterador==2){ //depois testa o SelectionSort
                    tinicial=clock();
                    SelectionSort(&A[0],n);
                    if(Testa(&A[0],n)){
                        tfinal=clock();
                        fprintf(exitlog,"O vetor foi ordenado com sucesso utilizando o SelectionSort. Tempo de execucao de %ld ms.\n",(tfinal-tinicial)*1000/CLOCKS_PER_SEC);
                        printf("SelectionSort: V\n");
                    }
                    else{
                        fprintf(exitlog,"O vetor nao foi ordenado utilizando o SelectionSort.\n");
                        printf("SelectionSort: X\n");
                    }
                }
                else if(iterador==3){ //depois testa o QuickSort
                    tinicial=clock();
                    QuickSort(&A[0],n);
                    if(Testa(&A[0],n)){
                        tfinal=clock();
                        fprintf(exitlog,"O vetor foi ordenado com sucesso utilizando o QuickSort. Tempo de execucao de %ld ms.\n",(tfinal-tinicial)*1000/CLOCKS_PER_SEC);
                        printf("QuickSort: V\n");
                    }
                    else{
                        fprintf(exitlog,"O vetor nao foi ordenado utilizando o QuickSort.\n");
                        printf("QuickSort: X\n");
                    }
                }
                else if(iterador==4){ //depois testa o HeapSort
                    tinicial=clock();
                    HeapSort(&A[0],n);
                    if(Testa(&A[0],n)){
                        tfinal=clock();
                        fprintf(exitlog,"O vetor foi ordenado com sucesso utilizando o HeapSort. Tempo de execucao de %ld ms.\n",(tfinal-tinicial)*1000/CLOCKS_PER_SEC);
                        printf("HeapSort: V\n");
                    }
                    else{
                        fprintf(exitlog,"O vetor nao foi ordenado utilizando o HeapSort.\n");
                        printf("HeapSort: X\n");
                    }
                }
                else{ //por fim, testa o MergeSort
                    tinicial=clock();
                    MergeSort(&A[0],n);
                    if(Testa(&A[0],n)){
                        tfinal=clock();
                        fprintf(exitlog,"O vetor foi ordenado com sucesso utilizando o MergeSort. Tempo de execucao de %ld ms.\n",(tfinal-tinicial)*1000/CLOCKS_PER_SEC);
                        printf("MergeSort: V\n");
                    }
                    else{
                        fprintf(exitlog,"O vetor nao foi ordenado utilizando o MergeSort.\n");
                        printf("MergeSort: X\n");
                    }
                }
            }
            fprintf(exitlog,"\n");
        }
    }
    tftotal=clock();
    tempototal = (double)(tftotal-titotal)*1000/CLOCKS_PER_SEC;
    tempototal/=60000; //passa o tempo total para minutos e armazena no arquivo
    fprintf(exitlog,"Tempo total de execucao dos testes de %.2f minutos\n",tempototal);
    printf("Todos os testes foram executados!\n");
    fclose(exitlog); //fecha o arquivo de estatisticas
    return 0;
}