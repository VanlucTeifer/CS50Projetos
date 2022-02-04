#include <stdio.h> /*Inclui a biblioteca de entrada e saida*/
#include <cs50.h> /*Inclui a biblioteca do cs50*/



int main(){
    int numero = 0; /*Cria uma variável do tipo inteiro*/
    while(numero < 1 || numero > 8){ /*Verifica se o numero digitado pelo usuário é maior igual a 1 ou menor igual a 8*/
        numero = get_int("Digite um número entre 1 e 8: "); /*Pede para que o usuário digite um numero entre 1 e 8*/
        if(numero < 1 || numero > 8) printf("O número deve ser entre 1 e 8\n"); /*Se o número não estiver nessa faixa, imprime mensagem de erro*/
    }

    for(int i = 1; i <= numero; i++){ /*laço de repetição de linhas*/

        for(int j = numero - i; j >= 1; j--) /*laço de repetição que adiciona espaços para fazer a piramide*/
            printf(" ");

        for(int j = 1; j <= i; j++) /*laço de repetição que adiciona os blocos*/
            printf("#");

        printf("\n");
    }
}