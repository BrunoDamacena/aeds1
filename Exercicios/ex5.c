#include<stdio.h>

long long int potencia(int num, int exp){
  if(exp==0)
    return 1;
  if(exp>1){
    exp--;
    num=num*potencia(num,exp);
  }

  return (long long int) num;
}

int main(){
  int num, exp;
  printf("Digite a base e o expoente inteiros: ");
  scanf("%d %d",&num, &exp);
  printf("Resultado: %lld\n",potencia(num,exp));
  return 0;
}
