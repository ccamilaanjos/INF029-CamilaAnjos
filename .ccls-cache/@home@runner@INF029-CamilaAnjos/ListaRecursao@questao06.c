/* Crie um programa em C, que contenha uma função recursiva que receba dois
inteiros positivos k e n e calcule k^n. Utilize apenas multiplicações.
O programa principal deve solicitar ao usuário os valores de k e n e imprimir
o resultado da chamada da função. */

#include<stdio.h>

int potenciacao(int k, int n);

int main(){
	int k = 0, n = 0;

	while(k < 1){
		printf("Digite um valor k inteiro e positivo: ");
		scanf("%d", &k);
		if(k < 1)
			printf("Valor invalido\n");
	}
	
	while(n < 1){
		printf("Digite um valor n inteiro e positivo: ");
		scanf("%d", &n);
		if(n < 1)
			printf("Valor invalido\n");
	}

	printf("%d elevado a %d e igual a %d", k, n, potenciacao(k, n));

	return 0;
}

int potenciacao(int k, int n){
	if(n == 1){
	    return k;
	}
	else{
	    return k * potenciacao(k, n - 1);
	}
}