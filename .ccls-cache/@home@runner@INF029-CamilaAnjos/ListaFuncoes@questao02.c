/*Crie um programa que tenha uma função subtrai e a função main. A função main deve ler três
valores, enviar para a função subtrai. A função subtrai deve realizar a subtração dos três valores
(primeiro menos o segundo menos o terceiro) e retornar o valor. A Função main deve imprimir o
resultado da subtração.*/

#include<stdio.h>

int subtrai(int x, int y, int z){
	int subt;
	subt = x - y - z;

	return subt;
}

int main(){
	int a, b, c;

	printf("Valor 1: ");
	scanf("%d", &a);
	printf("Valor 2: ");
	scanf("%d", &b);
	printf("Valor 3: ");
	scanf("%d", &c);

	int result = subtrai(a, b, c);
	printf("\nSubtracao = %d", result);

	return 0;
}
