/************************************************
LAED1 - Trabalho Pratico 1
Aluno: Bruno Nascimento Damacena
Matricula: 201622040139
Descricao do programa: Gerador de arquivo de entrada do Problema da Mochila
Data: 14/09/2017
************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
  srand(time(0));
  FILE *arquivo;
  arquivo=fopen("entrada.txt","wt");
  if (arquivo == NULL){
   printf("Erro ao criar arquivo!\n");
   return -1;
  }
  int peso,num,condp,condv;
  printf("Digite a capacidade maxima da mochila:\n");
  scanf("%d",&peso);
  printf("Digite o numero de itens disponiveis:\n");
  scanf("%d",&num);
  fprintf(arquivo,"%d\n%d",peso,num);
  num+=num;
  condp=peso/2;
  printf("Ate quanto voce quer que o valor dos itens variem?\n");
  scanf("%d",&condv);
  int posicoes[num];
  int cont,i;
  for(i=0,cont=0;i<num;i++,cont++){
    if(cont%2==0){
        fprintf(arquivo,"\n");
        posicoes[i]=rand()%condp+1;
        fprintf(arquivo,"%d ",posicoes[i]);
    }
    else{
        posicoes[i]=rand()%condv+1;
        fprintf(arquivo,"%d ",posicoes[i]);
    }
  }
  fclose(arquivo);
  printf("Arquivo gerado!\n");
  return 0;
}
