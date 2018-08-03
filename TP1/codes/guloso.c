/************************************************
LAED1 - Trabalho Pratico 1
Aluno: Bruno Nascimento Damacena
Matricula: 201622040139
Descricao do programa: Algoritmo guloso para solucao do Problema da Mochila
Data: 14/09/2017
************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

typedef struct item{
  int peso,valor,pos;
  double cb; //variavel para armazenar o custo beneficio do item
}Item;

void ordenacb(Item v[], int tam){ //ordena a estrutura de forma decrescente de acordo com o custo beneficio do elemento
  int i,j;
  Item aux;
  for(i=0;i<tam;i++){
    for(j=i+1;j<tam;j++){
      if(v[i].cb < v[j].cb){
        aux=v[i];
        v[i]=v[j];
        v[j]=aux;
      }
      else if (v[i].cb == v[j].cb){
        if(v[i].peso > v[j].peso){
          aux=v[i];
          v[i]=v[j];
          v[j]=aux;
        }
      }
    }
  }
}

void ordenapos(Item v[], int tam){ //ordena a estrutura de forma crescente de acordo com a posicao do elemento
  int i,j;
  Item aux;
  for(i=0;i<tam;i++){
    for(j=i+1;j<tam;j++){
      if(v[i].pos > v[j].pos){
        aux=v[i];
        v[i]=v[j];
        v[j]=aux;
      }
    }
  }
}


clock_t mochila(int tam, int num, Item v[]){ //procedimento que gera o arquivo saida e retorna o tempo de execucao
  int i, tamanho_solucao;
  Item solucao[num];
  clock_t tinicial, tfinal;
  FILE *out;
  int peso_total,valor_total;
  out = fopen("saida_gulosa.txt","wt");
  if (out == NULL){
   printf("Erro ao criar arquivo!\n");
   return -1;
  }
  tinicial=clock();
  ordenacb(v,num); //ordena o vetor de estruturas
  fprintf(out,"Capacidade da mochila: %d\nItens inseridos:\n",tam);
  for(peso_total=0,tamanho_solucao=0,valor_total=0,i=0;i<num;i++){ //percorre o vetor, já ordenado
    if(tam>=v[i].peso){ //se couber na mochila, o adiciona na variável solução
      tam-=v[i].peso;
      peso_total+=v[i].peso;
      valor_total+=v[i].valor;
      solucao[tamanho_solucao].pos = v[i].pos;
      solucao[tamanho_solucao].peso = v[i].peso;
      solucao[tamanho_solucao].valor = v[i].valor;
      tamanho_solucao++;
    }
  }

  ordenapos(solucao,tamanho_solucao); //ordena a solucao de acordo com o item. Nao e necessario, mas melhora o arquivo final gerado
  for(i=0;i<tamanho_solucao;i++){ //insere a solucao no arquivo
    fprintf(out,"\nItem %d de peso %d e valor %d",solucao[i].pos,solucao[i].peso,solucao[i].valor);
  }
  fprintf(out,"\n\nPeso total: %d\nValor total: %d\n",peso_total,valor_total);
  tfinal=clock();
  fclose(out);
  return (tfinal-tinicial); //retorna o tempo de execucao
}

int main(){
  int i;
  clock_t tempo;
  FILE *in;
  in = fopen("entrada.txt","rt"); //abre o arquivo de entrada
  if(in==NULL){
     printf("Erro ao carregar arquivo!\n");
     return -1;
  }
  int tamanho_mochila, num_itens;
  fscanf(in,"%d %d",&tamanho_mochila,&num_itens); //le o tamanho da mochila e o numero de itens
  Item item[num_itens];
  for(i=0;i<num_itens;i++){ //le o peso e o valor, calcula o custo beneficio e atribui uma posicao a cada item
    fscanf(in,"%d %d",&item[i].peso,&item[i].valor);
    item[i].cb=(float)item[i].valor/item[i].peso;
    item[i].pos = i+1;
  }
  fclose(in);
  tempo=mochila(tamanho_mochila,num_itens,item); //calcula o caso guloso
  printf("Tempo de execucao para o algoritmo guloso: %g ms.\n",tempo*1000.0/CLOCKS_PER_SEC); //exibe o tempo
  return 0;
}
