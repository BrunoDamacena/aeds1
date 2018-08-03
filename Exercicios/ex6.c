#include<stdio.h>

int MDC(int num1, int num2){ //baseado na logica do algoritmo de Euclides para MDC (https://pt.wikipedia.org/wiki/Algoritmo_de_Euclides#/media/File:Euclidean_algorithm_252_105_animation_flipped.gif)
  if (num2 == 0)
    return num1;
  else
    return MDC(num2, num1%num2);
}

int main(){
  int num1,num2;
  printf("Digite dois numeros inteiros: ");
  scanf("%d %d",&num1,&num2);
  printf("Resultado: %d\n",MDC(num1,num2));
  return 0;
}
