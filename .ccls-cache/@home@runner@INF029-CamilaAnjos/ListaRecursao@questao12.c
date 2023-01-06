// Faça uma função recursiva que receba um número inteiro positivo N e imprima
// todos os números naturais de 0 até N em ordem decrescente.

#include<stdio.h>

void imprimirDecresc(int N, int num);

int main(){
	int N = 0;
	
	while(N < 1){
		printf("Digite um numero N inteiro e positivo: ");
		scanf("%d", &N);
		if(N < 1)
			printf("Valor invalido\n");
	}

	imprimirDecresc(N, 0);
	
	return 0;
}

void imprimirDecresc(int N, int num){
	if(N >= num){
		printf("%d  ", N);
		imprimirDecresc(N - 1, num);
	}
}