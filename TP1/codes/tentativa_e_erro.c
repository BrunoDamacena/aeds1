/************************************************
LAED1 - Trabalho Pratico 1
Aluno: Bruno Nascimento Damacena
Matricula: 201622040139
Descricao do programa: Algoritmo de tentativa e erro para solucao do Problema da Mochila
Data: 14/09/2017
************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

typedef struct item{
  int peso,valor,pos;
}Item;

typedef struct solucao{
  Item item;
  int cond; //esta ou nao dentro da mochila (0 ou 1)
}Solucao;

/*
O metodo abaixo existe para somar 1 a um vetor de binarios (s.cond). Um vetor que comeca com todos os elementos 0,
vai ser somado 1 ate que todos os elementos sejam 1. Dessa forma, eu consigo percorrer todas as combinacoes de itens
estando dentro ou fora da mochila
*/

void soma_bin(Solucao s[], int tam){
  int i;
  for (i=0;i<tam;i++){
    if(i==0) s[i].cond++;
    if(s[i].cond == 2){
      s[i].cond=0;
      s[i+1].cond++;
    }
  }
}

int forcabruta(Solucao parcial[], Solucao geral[], int tam, int num){ //metodo para calcular a solucao geral do problema
  int i, tam_local, valor_local, valor_geral=0; //variavel de iteracao, de peso dos itens adicionados, valor dos itens adicionados e melhor valor (solucao global)
  int condicao_de_parada=0,condicao_de_estouro; //variaveis de condicao de parada do lastro e estouro da mochila (ultrapassou a capacidade maxima)
  while(!condicao_de_parada){ //enquanto nao parou
    condicao_de_estouro = 0; //seta as variaveis locais para 0
    valor_local = 0;
    tam_local = 0;
    for(i=0;i<num;i++){ //percorre o vetor
      if(parcial[i].cond){ //se ele esta dentro da mochila, gera uma solucao parcial
        tam_local+=parcial[i].item.peso;
        valor_local+=parcial[i].item.valor;
      }
      if(tam_local > tam){ //se estourou, informa a variavel de controle de estouro, e para de preencher a mochila
        condicao_de_estouro = 1;
        break;
      }
    }
    if(valor_local>valor_geral && !condicao_de_estouro){ //se vale mais que a anterior e nao estourou a capacidade
      for(i=0;i<num;i++){ //geral assume a parcial
        geral[i].cond=parcial[i].cond;
      }
      valor_geral = valor_local;
    }
    for(i=0;i<num;i++){ //se todos os elementos da condicao sao 1, significa que passou por todas as possibilidades
      if(parcial[i].cond==1) condicao_de_parada = 1; //logo, ativa a condicao de parada
      else{ //se encontrar um zero, desativa a condicao de parada e para de procurar
        condicao_de_parada=0;
        break;
      }
    }
    if(!condicao_de_parada) soma_bin(parcial,tam); //se nao acabou, passa pra proxima combinacao de itens
  }
  return valor_geral; //retorna o valor da solucao geral
}

clock_t mochila(int tam, int num, Item v[]){
  int i,valor_total,peso_total;
  Solucao parcial[num];
  Solucao geral[num];
  for(i=0;i<num;i++){ //preenche as solucoes com os itens disponiveis
    parcial[i].item.peso=v[i].peso;
    parcial[i].item.valor=v[i].valor;
    parcial[i].item.pos=v[i].pos;
    geral[i].item.peso=v[i].peso;
    geral[i].item.valor=v[i].valor;
    geral[i].item.pos=v[i].pos;
    parcial[i].cond=0;
    geral[i].cond=0;
  }
  clock_t tinicial, tfinal;
  FILE *out;
  out = fopen("saida_tentativa_e_erro.txt","wt"); //abre o arquivo
  if (out == NULL){
   printf("Erro ao criar arquivo!\n");
   return -1;
  }
  tinicial=clock();
  fprintf(out,"Capacidade da mochila: %d\nItens inseridos:\n",tam);
  peso_total=0;
  valor_total = forcabruta(parcial,geral,tam,num); //calcula a melhor solucao
  for(i=0;i<num;i++){ //imprime no arquivo
    if(geral[i].cond){
      peso_total+=v[i].peso;
      fprintf(out,"\nItem %d de peso %d e valor %d",v[i].pos,v[i].peso,v[i].valor);
    }
  }
  fprintf(out,"\n\nPeso total: %d\nValor total: %d\n",peso_total,valor_total);
  tfinal=clock();
  fclose(out);
  return(tfinal-tinicial); //retorna o tempo de execucao
}

int main(){
  int i;
  clock_t tempo;
  FILE *in;
  in = fopen("entrada.txt","rt"); //le o arquivo entrada
  if(in==NULL){
     printf("Erro ao carregar arquivo!\n");
     return -1;
  }
  int tamanho_mochila, num_itens; //preenche as variaveis com as informacoes do arquivo entrada
  fscanf(in,"%d %d",&tamanho_mochila,&num_itens);
  Item item[num_itens];
  for(i=0;i<num_itens;i++){ //alem de ler o peso e o valor de cada item, atribui uma posicao ao mesmo
    fscanf(in,"%d %d",&item[i].peso,&item[i].valor);
    item[i].pos = i+1;
  }
  fclose(in);
  tempo=mochila(tamanho_mochila,num_itens,item); //calcula a melhor solucao
  printf("Tempo de execucao para o algoritmo tentativa e erro: %g ms.\n",tempo*1000.0/CLOCKS_PER_SEC); //exibe o tempo de execucao em tela
  return 0;
}
