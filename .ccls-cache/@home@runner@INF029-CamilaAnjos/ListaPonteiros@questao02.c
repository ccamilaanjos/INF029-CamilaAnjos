/* Faça um programa que tenha uma função troca que recebe dois parâmetros inteiros e troque o
valor das variáveis um pelo outro. A função main deve ler do usuário os dois valores, chamar a
função troca, e depois imprimir os valores trocados. */

#include<stdio.h>

void troca(int *a, int *b);

int main(){
    int a;
    int b;
    printf("Numero A: "); scanf("%d", &a);
    printf("Numero B: "); scanf("%d", &b);
    
    troca(&a, &b);
    
    printf("\n\nNumero A = %d\n", a);
    printf("Numero B = %d\n", b);

	return 0;
}

void troca(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}