#include <stdio.h>
#include <cs50.h>

int main(){
    int inicial = 0, final = 0, nasc = 0, morte = 0, anos = 0;

    do{
        inicial = get_int("Start size: ");
    }while(inicial < 9);

    do{
        final = get_int("End size: ");
    }while(final < inicial);

    while(inicial < final){
        nasc = inicial / 3;
        morte = inicial / 4;
        inicial = inicial + nasc - morte;
        anos++;
    }
    printf("Years: %d\n", anos);
}