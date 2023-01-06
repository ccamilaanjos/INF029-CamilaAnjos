/*O superfatorial de um número N é definida pelo produto dos N primeiros fatoriais 
de N. Assim, o superfatorial de 4 é
sf(4) = 1! * 2! * 3! * 4! = 288
Faça uma função recursiva que receba um número inteiro positivo N e retorne o 
superfatorial desse número.
*/

#include<stdio.h>

int fatorial(int num);
int sf(int N);

int main(){
	int N = 0;
	
	while(N < 1){
		printf("Digite um valor n inteiro e positivo: ");
		scanf("%d", &N);
		if(N < 1)
			printf("Valor invalido\n");
	}

	printf("O superfatorial de %d e igual a %d", N, sf(N));
		
	return 0;
}

int fatorial(int num){
	if(num == 1 || num == 0){
		return 1;
	}
	else
		return num * fatorial(num - 1);
}

int sf(int N){
	if(N == 1 || N == 0){
		return 1;
	}
	else{
		return fatorial(N) * sf(N - 1);
	}
}