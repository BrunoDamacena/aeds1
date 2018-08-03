#include <stdlib.h>
#include <sys/time.h>
#include <stdio.h>
#define MAX 10

typedef struct TipoCelula *TipoApontador;

typedef int TipoChave;

typedef struct TipoItem {
  TipoChave Chave;
  /* outros componentes */
} TipoItem;

typedef struct TipoCelula {
  TipoItem Item;
  TipoApontador Prox;
} TipoCelula;

typedef struct TipoFila {
  TipoApontador Frente, Tras;
} TipoFila;

void FFVazia(TipoFila *Fila)
{ Fila->Frente = (TipoApontador) malloc(sizeof(TipoCelula));
  Fila->Tras = Fila->Frente;
  Fila->Frente->Prox = NULL;
} 

int Vazia(TipoFila Fila)
{ return (Fila.Frente == Fila.Tras); } 

void Enfileira(TipoItem x, TipoFila *Fila)
{ Fila->Tras->Prox = (TipoApontador) malloc(sizeof(TipoCelula));
  Fila->Tras = Fila->Tras->Prox;
  Fila->Tras->Item = x;
  Fila->Tras->Prox = NULL;
} 

void Desenfileira(TipoFila *Fila, TipoItem *Item)
{ TipoApontador q;
  if (Vazia(*Fila)) { printf("Erro fila esta vazia\n"); return; }
  q = Fila->Frente;
  Fila->Frente = Fila->Frente->Prox;
  *Item = Fila->Frente->Item;
  free(q);
} 

void Imprime(TipoFila Fila)
{ TipoApontador Aux;
  Aux = Fila.Frente->Prox;
  while (Aux != NULL) 
    { printf("%d\n", Aux->Item.Chave);
      Aux = Aux->Prox;
    }
}


int main(int argc, char *argv[]){
    char string[100];
    char c=' ';
    FILE *arquivo;
    TipoFila fila;
    FFVazia(&fila);
    printf("Digite o nome do arquivo: ");
    scanf("%s",string);
    arquivo = fopen(string,"rt");
    if(arquivo==NULL){
        printf("Erro ao carregar arquivo!\n");
        return 0;
    }
    while(c!=EOF){
        c=fgetc(arquivo);
        if(c=='a'){
            TipoItem item;
            TipoChave chave;
            fscanf(arquivo,"%d",&chave);
            item.Chave = chave;
            Enfileira(item,&fila);
        }
        else if(c=='b'){
            TipoItem item;
            Desenfileira(&fila,&item);
        }
        else if(c=='c'){
            printf("\nProcessos na fila:\n");
            Imprime(fila);
        }
    }
    return 0;
}