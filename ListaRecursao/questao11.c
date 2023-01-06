// Faça uma função recursiva que receba um número inteiro positivo N e imprima
// todos os números naturais de 0 até N em ordem crescente.

#include<stdio.h>

void imprimirCresc(int N, int num);

int main(){
	int N = 0;
	
	while(N < 1){
		printf("Digite um numero N inteiro e positivo: ");
		scanf("%d", &N);
		if(N < 1)
			printf("Valor invalido\n");
	}

	imprimirCresc(N, 0);
	
	return 0;
}

void imprimirCresc(int N, int num){
	if(num <= N){
		printf("%d  ", num);
		imprimirCresc(N, num + 1);
	}
}