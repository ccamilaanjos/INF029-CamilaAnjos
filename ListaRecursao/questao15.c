/* A função fatorial duplo é definida como o produto de todos os números naturais
ímpares de 1 até algum número natural ímpar N.
Assim, o fatorial duplo de 5 é
5!! = 1 * 3 * 5 = 15

Faça uma função recursiva que receba um número inteiro positivo impar N e retorne o
fatorial duplo desse número. */

#include<stdio.h>

int fatorialDuplo(int num);

int main(){
	int num = 0;
	
	while(num < 1 || num % 2 == 0){
		printf("Digite um numero N impar e positivo: ");
		scanf("%d", &num);
		if(num < 1 || num % 2 == 0)
			printf("Valor invalido\n");
	}

	printf("\n%d!! = %d\n", num, fatorialDuplo(num));
	
	return 0;
}

int fatorialDuplo(int num){
	if(num == 1){
		return num;
	}
	else{
		return num * fatorialDuplo(num - 2);
	}
}