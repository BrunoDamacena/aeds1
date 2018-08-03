#include<stdio.h>
#define tamanho_maximo 456569 //segundo pesquisa no site https://www.wolframalpha.com/, o fatorial do numero 99999 tem 456569 algarismos. Logo, o tamanho de vetor maximo para armazenar o valor do maior numero que meu programa podera calcular (99999!) e esse

void imprime_resultado(int resultado[], int tamanho_do_resultado){
	int i;
	printf("Resultado: ");
    for (i=tamanho_do_resultado-1; i>=0; i--){
    	//o fatorial e armazenado no vetor algarismo a algarismo de tras pra frente. Logo o lastro imprime de tras pra frente, por isso se faz necessario a variavel para armazenar a quantidade de algarismos do numero
        printf("%d",resultado[i]);
    }

    putchar('\n');
}

int multiplicador(int numero, int vetor[], int tamanho){ //multiplica a partir do algarismo menos significativo ate o mais significativo passando carry out
    int carry_out=0; //inicializa como 0
    int mult, i;

    for(i=0;i<tamanho;i++){ //lastro que faz a multiplicacao
        mult = vetor[i]*numero+carry_out; //o valor da multiplicacao e o numero atual x numero a ser multiplicado mais o algarismo de carry que veio da operacao passada
        vetor[i] = mult%10; //armazena o algarismo menos significativo no vetor
        carry_out=mult/10; //coloca o algarismo mais significativo na variavel de carry
    }
    while(carry_out != 0){ //enquanto houver carry
        vetor[tamanho] = carry_out%10; //coloca o algarismo menos significativo do carry na ultima posicao do vetor
        carry_out/=10; //vai pro proximo algarismo do carry
        tamanho++; //aumenta o tamanho do numero
    }
    return tamanho; //retorna o novo tamanho do numero
}



void fatorial(int num, int resultado[]){
    int tamanho_do_resultado, fator;
    resultado[0]=1; //inicializa com o menor valor possivel de um fatorial - 1 (0! ou 1!)
    tamanho_do_resultado=1; //inicializa o tamanho do resultado do fatorial, ou seja, o numero de algarismos atual. Como o numero e 1, a quantidade de algarismos e 1
    for(fator=1;fator<=num;fator++){
        tamanho_do_resultado = multiplicador(fator,resultado,tamanho_do_resultado); //faz a multiplicacao, ou seja, calcula o fatorial, armazenando o fatorial em um vetor
    }
    imprime_resultado(resultado,tamanho_do_resultado);
}



int main(){
    int num;
    int resultado[tamanho_maximo];
    printf("Digite um numero inteiro: ");
    scanf("%d",&num);
    fatorial(num,resultado);
    return 0;
}
