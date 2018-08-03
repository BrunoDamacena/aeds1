#include<stdio.h>

int Digitos(int N){
  int cont=1; //inicializa o contador como 1
  if(N>=10)
    cont=cont+Digitos(N/10); //contador vai ser ele mesmo mais o contador da funcao para N/10
  return cont; //retorna o contador

}

int main(){
  int pao;
  printf("Digite um numero inteiro: ");
  scanf("%d",&pao);
  printf("Resultado: %d\n",Digitos(pao));
  return 0;
}
