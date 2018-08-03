#include<stdio.h>
#include<stdlib.h>

int ** Aloca_matriz(int lin, int col){
  int ** matriz;
  int i;
  matriz = (int **) malloc(lin*sizeof(int*)); //aloca as linhas
  for(i=0;i<lin;i++){
    matriz[i] = (int *) malloc(col*sizeof(int)); //aloca as colunas
  }
  return matriz;
}

void Le_dados (int **matriz, int lin, int col){
  int i,j,valor;
  printf("Entre com os dados:\n");
  for(i=0;i<lin;i++){
    for(j=0;j<col;j++){
      printf("Elemento [%d] [%d]: ",i,j);
      scanf("%d",&valor); //le do teclado
      matriz[i][j]=valor;
    }
  }
}

int ** Multiplica(int **matriz1, int **matriz2, int lin1, int col1, int lin2, int col2){
  int ** result;
  result = Aloca_matriz(lin1,col2);
  int i,j,k,elemento;
  for(i=0;i<lin1;i++){
    for(j=0;j<col2;j++){ //para cada elemento da matriz resultado
      elemento=0;
      for(k=0;k<col1;k++){ //multiplica linha por coluna e soma
        elemento+=matriz1[i][k]*matriz2[k][j];
      }
      result[i][j] = elemento; //atribui o valor
    }
  }
  return result; //retorna a raiz
}

void Imprime_matriz (int **matriz, int lin, int col){
  int i,j;
  for(i=0;i<lin;i++){
    for(j=0;j<col;j++){
      printf("%7d ",matriz[i][j]);
    }
    putchar('\n');
  }
}

int main(){
  int dim1,dim2,dim3,dim4;
  int** matriz1;
  int** matriz2;
  printf("Digite as dimensoes da primeira matriz: ");
  scanf("%d %d",&dim1,&dim2);
  matriz1 = Aloca_matriz(dim1,dim2);
  Le_dados(matriz1,dim1,dim2);
  printf("\nPrimeira Matriz:\n");
  Imprime_matriz(matriz1,dim1,dim2);
  putchar('\n');
  printf("Digite as dimensoes da segunda matriz: ");
  scanf("%d %d",&dim3,&dim4);
  matriz2 = Aloca_matriz(dim3,dim4);
  Le_dados(matriz2,dim3,dim4);
  printf("\nSegunda Matriz:\n");
  Imprime_matriz(matriz2,dim3,dim4);
  putchar('\n');
  if(dim2 != dim3) return -1;
  int ** resultante;
  resultante = Multiplica(matriz1,matriz2,dim1,dim2,dim3,dim4);
  printf("Matriz resultante:\n");
  Imprime_matriz(resultante,dim1,dim4);
  putchar('\n');
  return 0;
}
