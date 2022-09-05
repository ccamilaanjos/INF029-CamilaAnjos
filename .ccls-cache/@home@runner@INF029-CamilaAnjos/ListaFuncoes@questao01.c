/*Crie um programa que tenha uma função soma e a função main. A função main deve ler dois
valores, enviar para a função soma. A função soma deve realizar a soma e retornar o valor.
A função main deve imprimir o resultado da soma*/

#include<stdio.h>

int soma(int x, int y){
	int sum;
	sum = x + y;

	return sum;
}

int main(){
	int a, b;
	printf("Valor 1: ");
	scanf("%d", &a);
	printf("Valor 2: ");
	scanf("%d", &b);
	
	int result = soma(a, b);
	printf("\nSoma = %d", result);

	return 0;
}