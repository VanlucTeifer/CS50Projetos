#include <stdio.h>
#include <cs50.h>

void mundo1();

int main(){
    int numero = 0; /*Cria uma variável do tipo inteiro*/
    while(numero < 1 || numero > 8){ /*Verifica se o numero digitado pelo usuário é maior igual a 1 ou menor igual a 8*/
        numero = get_int("Digite um número entre 1 e 8: "); /*Pede para que o usuário digite um numero entre 1 e 8*/
        if(numero < 1 || numero > 8) printf("O número deve ser entre 1 e 8\n"); /*Se o número não estiver nessa faixa, imprime mensagem de erro*/
    }
    mundo1(numero); /*chamada da função*/
}

void mundo1(int numero){ /*Criação da função*/
    int i, j;
    for(i = 1; i <= numero; i++){ /*laço de repetição de linhas*/

        for(j = numero - i; j >= 1; j--) /*laço de repetição que adiciona espaços para fazer a piramide*/
            printf(" ");

        for(j = 1; j <= i; j++) /*laço de repetição que adiciona os blocos*/
            printf("#");

        printf("  "); /*Imprime os espaços entre as duas piramides*/

        for(j = numero + 1; j <= numero+i; j++){ /* Imprime o outro lado da piramide*/
            printf("#");
        }

        printf("\n");
    }
}