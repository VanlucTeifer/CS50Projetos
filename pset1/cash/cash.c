#include <stdio.h>
#include <cs50.h>
#include <math.h>

float troco(float centavos);

int main(){
    float centavos = 0.0;
    int trocado = 0;

    do{
    centavos = get_float("Digite o valor das compras: ");

    if(centavos <= 0.0) printf("Valor não pode ser numeros negativos!\n");
    }while(centavos <= 0.0);

    trocado = troco(centavos);
    printf("%d\n", trocado);
}

float troco(float centavos){
  float moeda;
  int cents = 0,t25 = 0.0, t10 = 0.0, t5 = 0.0, t1 = 0.0;

  cents = round(centavos * 100);

  t25 = cents / 25.0;
  cents = cents - (t25*25);
  printf("Troco25 = %d\n", t25);

  t10 = cents / 10.0;
  cents = cents - (t10*10);
  printf("Troco10 = %d\n", t10);

  t5 = cents / 5.0;
  cents = cents - (t5*5);
  printf("Troco5 = %d\n", t5);

  t1 = cents / 1.0;
  cents = cents - (t1*1);
  printf("Troco1 = %d\n", t1);

  moeda = t25 + t10 + t5 + t1;
  return moeda;
}