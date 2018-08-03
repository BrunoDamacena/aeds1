#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#define qtdbaldes 11

typedef char TipoChave[100];
typedef struct {
  TipoChave Nome;
  int Nota;
} TipoItem;
typedef struct TipoCelula *TipoApontador;
typedef struct TipoCelula {
  TipoItem Item;
  TipoApontador Prox;
} TipoCelula;
typedef struct {
  TipoApontador Fundo, Topo;
  int Tamanho;
} TipoPilha;

void FPVazia(TipoPilha *Pilha)
{ Pilha->Topo = (TipoApontador) malloc(sizeof(TipoCelula));
  Pilha->Fundo = Pilha->Topo;
  Pilha->Topo->Prox = NULL;
  Pilha->Tamanho = 0;
} 

int Vazia(TipoPilha Pilha)
{ return (Pilha.Topo == Pilha.Fundo); } 

void Empilha(TipoItem x, TipoPilha *Pilha)
{ TipoApontador Aux;
  Aux = (TipoApontador) malloc(sizeof(TipoCelula));
  Pilha->Topo->Item = x;
  Aux->Prox = Pilha->Topo;
  Pilha->Topo = Aux;
  Pilha->Tamanho++;
} 

void Desempilha(TipoPilha *Pilha, TipoItem *Item)
{ TipoApontador q;
  if (Vazia(*Pilha)) { printf("Erro: lista vazia\n"); return; }
  q = Pilha->Topo;
  Pilha->Topo = q->Prox;
  *Item = q->Prox->Item;
  free(q);  Pilha->Tamanho--;
} 

int Tamanho(TipoPilha Pilha)
{ return (Pilha.Tamanho); } 

int main(int argc, char *argv[]){
    FILE *arq;
    int tamanho,i;
    char nome_do_arquivo[100];
    printf("Digite o nome do arquivo: ");
    scanf("%s",nome_do_arquivo);
    arq=fopen(nome_do_arquivo,"rb");
    if(arq==NULL){
        printf("Arquivo nao existe!\n");
        return 0;
    }

    putchar('\n');

    fseek (arq , 0 , SEEK_END);
    tamanho = ftell (arq)/sizeof(TipoItem);
    rewind (arq);
    TipoItem aluno;
    TipoPilha alunos;
    FPVazia(&alunos);
    for(i=0;i<tamanho;i++){
      fread(&aluno,sizeof(TipoItem),1,arq);
      Empilha(aluno,&alunos);
    }
    fclose(arq);

    TipoPilha baldes[qtdbaldes];
    for(i=0; i<qtdbaldes;i++){
      FPVazia(&baldes[i]);
    }

    while(!Vazia(alunos)){
      Desempilha(&alunos,&aluno);
      int nota=aluno.Nota;
      Empilha(aluno,&baldes[nota]);      
    }

    for(i=0;i<11;i++){
      while(!Vazia(baldes[i])){
        Desempilha(&baldes[i],&aluno);
        printf("%s\n%d\n",aluno.Nome,aluno.Nota);
      }
    }
    
    return 0;
}
