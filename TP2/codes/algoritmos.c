/************************************************
LAED1 - Trabalho Pratico 2
Aluno: Bruno Nascimento Damacena
Matricula: 201622040139
Descricao do programa: Arquivo .c com os algoritmos utilizados
Data: 10/11/2017
************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "algoritmos.h"


/* Inicio dos algoritmos de ordenacao menos eficientes */
/* BUBBLESORT */
void BubbleSort(TipoItem *A, TipoIndice n){
  TipoIndice i,j; //indices para percorrer o vetor
  int contador; //contador que armazena o numero de trocas feitas
  for(j=0;j<n-1;j++){ //percorre todo o vetor e zera o contador
    contador=0;
    for(i=1;i<n-j;i++){ //percorre comparando com o arquivo selecionado
      if(A[i].Chave > A[i+1].Chave){ //se for maior, troca
        TipoItem aux = A[i];
        A[i] = A[i+1];
        A[i+1] = aux;
        contador++; //acrescenta no contador de trocas
      }
    }
    if(contador==0) return; //se nao houve trocas, o vetor ja esta ordenado, entao encerra o algoritmo
  }
}

/* INSERTIONSORT */
void InsertionSort(TipoItem *A, TipoIndice n){
  TipoIndice i, j;
  TipoItem x; //inicializa o item a ser trocado
  for (i = 2; i <= n; i++){ //percorre o vetor
    x = A[i];  j = i - 1;
    A[0] = x;  //escolhe o elemento sentinela
    while (x.Chave < A[j].Chave){ //se houver um menor, troca
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = x; //altera o elemento a ser trocado
  }
}

/* SELECTIONSORT */
void SelectionSort(TipoItem *A, TipoIndice n){
  TipoIndice i, j, Min; //inicializa indices para percorrer o vetor e para representar o menor elemento
  TipoItem x; //inicializa o item a ser trocado
  for (i = 1; i <= n - 1; i++){ //percorre o vetor
    Min = i; //assume que o primeiro e o menor elemento
    for (j = i + 1; j <= n; j++){//percorre o resto do vetor
      if (A[j].Chave < A[Min].Chave) Min = j; //se houver um menor que ele, atualiza o menor
    }
    /* Troca o encontrado em sua posicao correta */
    x = A[Min];
    A[Min] = A[i];
    A[i] = x;
  }
}
/* Fim dos algoritmos de ordenacao menos eficientes */

/* Inicio dos algoritmos de ordenacao eficientes */
/* QUICKSORT */
void Particao(TipoIndice Esq, TipoIndice Dir, TipoIndice *i, TipoIndice *j, TipoItem *A){
  TipoItem x, w;
  *i = Esq;  *j = Dir;
  x = A[(*i + *j) / 2]; //obtem o pivo x
  do{ 
    while(x.Chave > A[*i].Chave) (*i)++; //acha a posicao antes do pivo que tem a chave maior que o pivo
    while(x.Chave < A[*j].Chave) (*j)--; //acha a posicao depois do pivo que tem a chave menor que o pivo
    if (*i <= *j){ //se i e j nao se cruzaram, troca A[*i] com A[*j]
      w = A[*i];
      A[*i] = A[*j];
      A[*j] = w;
      (*i)++;
      (*j)--;
    }
  }while (*i <= *j); //continua enquanto eles nao se cruzaram
}

void OrdenaQuick(TipoIndice Esq, TipoIndice Dir, TipoItem *A){
  TipoIndice i, j; //indices para percorrer o vetor de ambos os lados ate o item pivo
  Particao(Esq, Dir, &i, &j, A); //particiona
  /* Chama o algoritmo para vetores menores ate todo o vetor ser ordenado*/
  if (Esq < j) OrdenaQuick(Esq, j, A);
  if (i < Dir) OrdenaQuick(i, Dir, A);
}

void QuickSort(TipoItem *A, TipoIndice n){
  OrdenaQuick(1, n, A); //inicializa o quicksort para todo o vetor
}

/* HEAPSORT */
void Refaz(TipoIndice Esq, TipoIndice Dir, TipoItem *A){
  TipoIndice i = Esq;
  int j;
  TipoItem x;
  j = i * 2;
  x = A[i];
  while (j <= Dir){
    if (j < Dir){
      if (A[j].Chave < A[j+1].Chave)
      j++;
    }
    if (x.Chave >= A[j].Chave) break;
    A[i] = A[j];
    i = j;  j = i * 2;
  }
  A[i] = x;
}

void Constroi(TipoItem *A, TipoIndice n){
  TipoIndice Esq;
  Esq = n / 2 + 1;
  while (Esq > 1)
    { Esq--;
      Refaz(Esq, n, A);
    }
}

void HeapSort(TipoItem *A, TipoIndice n){
  TipoIndice Esq, Dir;
  TipoItem x;
  Constroi(A, n); //constroi o heap
  Esq = 1;  Dir = n;
  while (Dir > 1){ //refaz o vetor, ordenando-o
      x = A[1];  A[1] = A[Dir];  A[Dir] = x;  Dir--;
      Refaz(Esq, Dir, A);
    }
}

/* MERGESORT */
void Merge(TipoItem *A, TipoIndice i, TipoIndice m, TipoIndice j){
  //inicializa o vetor auxiliar e os indices de iteracao
  TipoVetor B;
  TipoIndice x;
  TipoIndice k = i;
  TipoIndice l = m+1;
  
  for(x=i;x<=j;x++) B[x] = A[x]; //valor inicial no vetor auxiliar até a posicao j
  x = i;
  while(k<=m && l<=j){
    if(B[k].Chave <= B[l].Chave) A[x++] = B[k++];
    else A[x++] = B[l++];
  }

  while (k<=m) A[x++] = B[k++];

  while (l<=j) A[x++] = B[l++];

}
void OrdenaMerge(TipoItem *A, TipoIndice comeco, TipoIndice fim){
  TipoIndice meio; //inicializa a variavel do meio
  if (comeco < fim){ //enquanto o vetor tiver mais de um elemento
    meio = (comeco + fim - 1) / 2; //acha o meio, ordena as duas metades e junta
    OrdenaMerge(A, comeco, meio);
    OrdenaMerge(A, meio + 1, fim);
    Merge(A,  comeco,  meio, fim);
  }
}

void MergeSort(TipoItem *A, TipoIndice n){
  OrdenaMerge(A,1,n);
}


/* Fim dos algoritmos de ordenacao eficientes */

/* Inicio dos algoritmos de manipulacao de vetor */

void Copia(TipoItem *Fonte, TipoItem *Destino, TipoIndice n){
  for(i = 1; i <= n; i++) Destino[i] = Fonte[i]; //copia todas as chaves de um vetor para o outro
}

void Imprime(TipoItem *V, TipoIndice n){
  for(i = 1; i <= n; i++) printf("%d ", V[i].Chave);  printf("\n"); //imprime o vetor na tela
}

int Testa(TipoItem *V, TipoIndice n){
  for(i = 2; i <= n; i++){
    if(V[i].Chave < V[i-1].Chave){ //se um elemento for maior que o proximo, retorna 0 (nao ordenado)
      return 0;
    }
  }
  return 1; //caso contrario, retorna 1 (ordenado)
}
/* Fim dos algoritmos de manipulacao de vetor */

/* Inicio dos algoritmos de manipulacao de entrada */

FILE* abreArquivo(int tipo, int tam){
  /* Inicializa as variaveis */
  FILE *arq;
  char diretorio[100];
  char tipoDeEntrada[20];
  /* Gera o nome do arquivo de entrada */
  sprintf(tipoDeEntrada,"ordem%d.txt",tam);
  if(tipo == 1) sprintf(diretorio,"database/aleatorios/");
  else if(tipo == 2) sprintf(diretorio,"database/quaseOrdenados/");
  else if(tipo == 3) sprintf(diretorio,"database/ordenados/");
  else if(tipo == 4) sprintf(diretorio,"database/inversamenteOrdenados/");
  sprintf(diretorio,"%s%s",diretorio,tipoDeEntrada);
  /* Retorna o arquivo */
  arq = fopen(diretorio,"rt");
  return arq;
}
/* Fim dos algoritmos de manipulacao de entrada */