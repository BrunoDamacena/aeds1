/************************************************
LAED1 - Trabalho Pratico 2
Aluno: Bruno Nascimento Damacena
Matricula: 201622040139
Descricao do programa: Arquivo .h com os algoritmos utilizados
Data: 10/11/2017
************************************************/

#define MAXTAM 1000000

typedef int TipoChave;
typedef struct TipoItem {
  TipoChave Chave;
  /* outros componentes */
} TipoItem;

typedef int TipoIndice;
typedef TipoItem TipoVetor[MAXTAM + 1];
/* MAXTAM+1 por causa da sentinela em Insercao */
TipoVetor A;
TipoIndice i, n;


/* Algoritmos menos eficientes */
void BubbleSort(TipoItem *A, TipoIndice n);
void InsertionSort(TipoItem *A, TipoIndice n);
void SelectionSort(TipoItem *A, TipoIndice n);

/* Algoritmos eficientes */
void QuickSort(TipoItem *A, TipoIndice n);
void HeapSort(TipoItem *A, TipoIndice n);
void MergeSort(TipoItem *A, TipoIndice n);

/* Funcoes auxiliares aos algoritmos de ordenacao */
void OrdenaMerge(TipoItem *A, TipoIndice comeco, TipoIndice n);
void OrdenaQuick(TipoIndice Esq, TipoIndice Dir, TipoItem *A);
void Merge(TipoItem *A, TipoIndice comeco, TipoIndice meio, TipoIndice fim);
void Particao(TipoIndice Esq, TipoIndice Dir, TipoIndice *i, TipoIndice *j, TipoItem *A);
void Refaz(TipoIndice Esq, TipoIndice Dir, TipoItem *A);
void Constroi(TipoItem *A, TipoIndice n);
void Copia(TipoItem *Fonte, TipoItem *Destino, TipoIndice n);
void Imprime(TipoItem *V, TipoIndice n);
int Testa(TipoItem *V, TipoIndice n);

/* Funcoes para gerar o arquivo de entrada */
FILE* abreArquivo();