/************************************************
LAED1 - Trabalho Pratico 2
Aluno: Bruno Nascimento Damacena
Matricula: 201622040139
Descricao do programa: Gerador de entrada do problema
Data: 10/11/2017
************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(0));
    char nomeDoArquivo[100];
    char ordem[25];
    FILE *arq;
    int tipo,complex;
    printf("Digite a ordem de complexidade do problema. Opcoes disponiveis:\n\nN = 10;\nN = 100;\nN = 1000;\nN = 10000;\nN = 100000;\nN = 1000000.\n\nN = ");
    scanf("%d",&complex);
    while(complex!=10 && complex!=100 && complex!=1000 && complex!=10000 && complex!=100000 && complex!=1000000){
        printf("Opcao invalida!\n");
        printf("Por favor, digite novamente a ordem de complexidade desejada ao problema. Opcoes disponiveis:\n\nN = 10;\nN = 100;\nN = 1000;\nN = 10000;\nN = 100000;\nN = 1000000.\n\nN = ");
        scanf("%d",&complex);
    }
    sprintf(ordem,"ordem%d.txt",complex);

    printf("Por favor, digite o tipo de entrada. Opcoes disponiveis:\n\nDigite 1 para entrada aleatoria\nDigite 2 para entrada quase ordenada\nDigite 3 para entrada ordenada\nDigite 4 para entrada inversamente ordenada.\n\n");
    scanf("%d",&tipo);
    while(tipo<1 && tipo>4){
        printf("Opcao invalida!\n");
        printf("Por favor, digite novamente o tipo de entrada. Opcoes disponiveis:\n\nDigite 1 para entrada aleatoria\nDigite 2 para entrada quase ordenada\nDigite 3 para entrada ordenada\nDigite 4 para entrada inversamente ordenada.\n\n");
        scanf("%d",&tipo);
    }
    
    if(tipo == 1){
        sprintf(nomeDoArquivo,"database/aleatorios/%s",ordem);
        arq = fopen(nomeDoArquivo,"wt");
        if(arq == NULL){
            printf("Erro ao criar arquivo!\n");
            return 0;
        }
        int i;
        for(i=0;i<complex-1;i++) fprintf(arq,"%d\n",rand()%complex+1);
        fprintf(arq,"%d",rand()%complex+1);
        fclose(arq);
        
    }
    else if(tipo == 2){
        sprintf(nomeDoArquivo,"database/quaseOrdenados/%s",ordem);
        arq = fopen(nomeDoArquivo,"wt");
        if(arq == NULL){
            printf("Erro ao criar arquivo!\n");
            return 0;
        }
        int i;
        for(i=0;i<complex-1;i++){            
            if(i==complex-12 || i==complex-7 || i==complex-2) fprintf(arq,"%d\n",i+rand()%9+2);
            else fprintf(arq,"%d\n",i+1);
        }
        fprintf(arq,"%d",i+1);
        fclose(arq);
    }
    else if(tipo == 3){
        sprintf(nomeDoArquivo,"database/ordenados/%s",ordem);
        arq = fopen(nomeDoArquivo,"wt");
        if(arq == NULL){
            printf("Erro ao criar arquivo!\n");
            return 0;
        }
        int i;
        for(i=0;i<complex-1;i++) fprintf(arq,"%d\n",i+1);
        fprintf(arq,"%d",i+1);
        fclose(arq);
    }
    else if(tipo == 4){
        sprintf(nomeDoArquivo,"database/inversamenteOrdenados/%s",ordem);
        arq = fopen(nomeDoArquivo,"wt");
        if(arq == NULL){
            printf("Erro ao criar arquivo!\n");
            return 0;
        }
        for(;complex>1;complex--) fprintf(arq,"%d\n",complex);
        fprintf(arq,"1");
        
        fclose(arq);
    }
    printf("Arquivo gerado com sucesso! Cheque-o em %s\nPressione qualquer tecla para sair...\n",nomeDoArquivo);
    getchar();
    getchar();
}