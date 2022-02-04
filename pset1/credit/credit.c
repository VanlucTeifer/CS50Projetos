#include <stdio.h>
#include <cs50.h>

int main(void){
    /*Pede ao usuario o numero do cartao de credito*/
    long numeroCartao = get_long("Número cartão de crédito: ");
    int ultimoDigito = 0, soma1 = 0, contador = 1, digitoAtual = 0, legitimo = 0;

    //Faz a contagem dos digitos do cartao
    int contaDigito = 0;
    long cc = numeroCartao, i = 0;

    while (cc > 0){
        cc = cc / 10;
        contaDigito++;
    }
        /*Atribui o numero do cartão na variavel i*/
        i = numeroCartao;
        /*Laço de repetição que faz a primeira soma dos digitos nas posições pares*/
        do{
            digitoAtual = i % 10;
            contador++;
            i /= 10;
            if(contador % 2){
                soma1 = (digitoAtual*2);
                ultimoDigito += soma1 % 10;
                ultimoDigito += soma1 / 10;
            }

        }while(i > 0);
        /*atribui novamente o numero do cartao na variavel i e zera o contador*/
        i = numeroCartao;
        contador = 0;

        /*Laço de repetição que faz a soma segunda soma dos digitos nas posições impares */
        while(i > 0){
            digitoAtual = i % 10;
            contador++;
            i /= 10;
            if(contador % 2){
                ultimoDigito += digitoAtual;
            }

        }
        /*Faz o calculo para verificar se o numero do cartão e valido*/
        legitimo = ultimoDigito;
        legitimo = legitimo % 10;
        
        /*Mais uma vez atribui o numero do cartao na variavel i*/
        i = numeroCartao;
        
        printf("%d\n",legitimo);
        
        /*Laço de repetição que reduz o numero do cartão para os dois primeiros digitos*/
        while(i > 100){
            i /= 10;
        }
        
        /*Laços condicionais que verificam se o cartão e invalido ou pertencente a alguma bandeira*/
        if(((i / 10 == 3) && (i % 10 == 4 || i % 10 == 7)) && contador == 15 && legitimo == 0){
            printf("AMEX\n");
        }else if((i / 10 == 4) && (contador == 13 || contador == 16) && legitimo == 0){
            printf("VISA\n");
        }else if((i / 10 == 5) && (0 < i % 10 && i % 10 < 6) && contador == 16 && legitimo == 0){
            printf("MASTERCARD\n");
        }else{
            printf("INVALID\n");
        }
}