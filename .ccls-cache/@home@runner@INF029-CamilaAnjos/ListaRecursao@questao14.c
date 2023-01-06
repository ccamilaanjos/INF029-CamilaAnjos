// Faça uma função recursiva que receba um número inteiro positivo par N e imprima
// todos os números pares de 0 até N em ordem decrescente.

#include<stdio.h>

void imprimirDecresc(int N, int num);

int main(){
	int N = 0;
	
	while(N < 1 || N % 2 != 0){
		printf("Digite um numero N par e positivo: ");
		scanf("%d", &N);
		if(N < 1 || N % 2 != 0)
			printf("Valor invalido\n");
	}

	imprimirDecresc(N, 0);
	
	return 0;
}

void imprimirDecresc(int N, int num){
	if(N >= num){
		printf("%d  ", N);
		imprimirDecresc(N - 2, num);
	}
}