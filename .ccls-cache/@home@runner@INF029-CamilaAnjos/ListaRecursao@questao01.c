// Faça uma função recursiva que calcule e retorne o fatorial de um número inteiro N.

#include<stdio.h>

int fatorial(int num);

int main(){
	int n;
	
	printf("Digite um numero inteiro: ");
	scanf("%d", &n);

	printf("%d! e igual a %d\n", n, fatorial(n));

	return 0;
}

int fatorial(int num){
	if(num == 1 || num == 0){
		return 1;
	}
	else
		return num * fatorial(num - 1);
}