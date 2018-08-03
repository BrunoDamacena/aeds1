#include<stdio.h>
#include<stdlib.h>

#define tam 100000

typedef struct lista{ //lista onde serao armazenados os numeros da decomposicao
  int numero;
  struct lista *prox;
}Lista;

Lista *adicionaNaLista(Lista *lista, int num){ //funcao para armazenar numero na lista
  Lista *i = lista; //cria uma lista backup para poder percorrer a lista sem perder o primeiro numero
  Lista *nova = (Lista*) malloc(sizeof(Lista)); //cria nova lista
  nova->numero=num;
  nova->prox=NULL;
  if(i==NULL){ //se receber ponteiro vazio, retorna a lista criada
    return nova;
  }
  while(i->prox!=NULL) i=i->prox; //percorre a lista backup até o ultimo elemento
  i->prox=nova; //insere o elemento na lista
  return nova; //retorna a ultima posicao da mesma, para nao precisar percorrer toda a lista sempre que for acrescentar elemento
  //P.S.: na primeira vez que fiz o codigo, eu retornava lista, mas percebi que o tempo de execucao diminuiu bastante quando mudei para a nova, assim eu so percorro a lista ate o fim uma vez
}

void imprimeLista(Lista *lista){
  if(lista==NULL) return; //se nao tiver elemento na lista, nao faz nada
  int num=lista->numero; //variavel para comparacao de numero
  int sum=0; //variavel para comparacao de soma (uso quando quero identificar quando pular linha)
  char string[tam]="Decomposicao:\n"; //string para armazenar o resultado a ser impresso
  int anterior = num; //guarda o numero anterior para comparacao
  int condicao_imprime=1; //variavel que controla se a linha vai ser impressa
  while(lista!=NULL){ //percorre toda a lista
    sprintf(string, "%s%d", string, lista->numero); //armazena o primeiro numero na string
    sum+=lista->numero; //aumenta o valor de soma
    if(lista->numero > anterior) condicao_imprime=0; //se o proximo numero for maior que o anterior, nao pertence ao resultado, logo nao imprime
    anterior = lista->numero; //anterior recebe o numero atual, para preparar para a proxima comparacao
    if(sum==num){ //se o somatorio for igual ao numero
      sprintf(string, "%s\n", string); //pula linha
      if(condicao_imprime) printf("%s",string); //se a condicao de impressao for verdadeira, imprime a string
      sprintf(string,"%c",'\0'); //zera a string
      anterior = num; //guarda o valor anterior
      condicao_imprime = 1; //seta a condicao de impressao
      sum=0; //zera o valor de somatorio
    }
    else sprintf(string,"%s + ",string); //caso contrario, armazena o valor na string
    lista=lista->prox;
  }
}

Lista *decompoe(int num){ //metodo para decompor o numero
  Lista *lista = NULL; //cria uma lista para armazenar os numeros
  int i=num; //iterador recebe o numero
  if(num==0) return NULL; //se for zero, retorna uma lista vazia
  if(num==1) return adicionaNaLista(lista,num); //se for 1, retorna a lista com o 1
  lista=adicionaNaLista(lista,num); //se nao passou nos testes acima, adiciona o numero atual na lista
  Lista *primeiro = lista; //guarda o primeiro elemento da lista, pra nao perder a referencia do mesmo
  while(i>0){ //enquanto o numero da entrada for maior que 0
    Lista *backup = decompoe(num-i); //cria uma lista de possibilidades vinda da decomposicao dos numeros anteriores
    int sum=0; //variavel de somatorio para controle de possibilidades
    while(backup!=NULL){ //enquanto tiver possibilidade
      if(sum == 0) lista = adicionaNaLista(lista,i); //se o somatorio for zero, adiciona o numero atual do primeiro lastro na lista principal
	    lista = adicionaNaLista(lista,backup->numero); //adiciona o numero da lista de possibilidades
	    sum+=backup->numero; //incrementa a soma
	    if(sum==num-i) sum=0; //se chegar ao valor maximo, zera pra testar novamente
	    backup=backup->prox; //passa pro proximo
    }
    i--;
  }
  return primeiro; //retorna a primeira posicao da lista
}

int main(){
  int num;
  Lista *lista = (Lista*)malloc(sizeof(Lista));
  printf("Digite um numero inteiro: ");
  scanf("%d",&num);
  lista=decompoe(num);
  imprimeLista(lista);
  return 0;
}
