// Faça uma função recursiva que calcule e retorne o N-ésimo termo da sequência Fibonacci.
// Alguns números desta sequência são: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89...

#include<stdio.h>

int fibonacci(int termo);

int main(){
	int n;

	printf("Digite o numero do termo: ");
	scanf("%d", &n);

	printf("O %d termo da sequencia de Fibonacci e %d", n, fibonacci(n));

	return 0;
}

int fibonacci(int termo){
	if(termo == 1){
		return 0;
	}
	else if(termo == 2){
		return 1;
	}
	else{
		return fibonacci(termo - 1) + fibonacci(termo - 2);
	}
}