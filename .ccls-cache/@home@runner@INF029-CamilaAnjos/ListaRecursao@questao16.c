/* O fatorial quádruplo de um número N é dado por
((2n)!) / n!
Faça uma função recursiva que receba um número inteiro positivo N e retorne o 
fatorial quádruplo desse número */

#include<stdio.h>

int fatorial(int n);

int main(){
	int n = 0;
	int fatQuad;
	
	while(n < 1){
		printf("Digite um valor n inteiro e positivo: ");
		scanf("%d", &n);
		if(n < 1)
			printf("Valor invalido\n");
	}

	fatQuad = fatorial(2 * n) / fatorial(n);
	printf("O fatorial quadruplo de %d e igual a %d\n", n, fatQuad);

	return 0;
}

int fatorial(int n){
	if(n == 1 || n == 0){
		return 1;
	}
	else{
		return n * fatorial(n - 1);
	}
}