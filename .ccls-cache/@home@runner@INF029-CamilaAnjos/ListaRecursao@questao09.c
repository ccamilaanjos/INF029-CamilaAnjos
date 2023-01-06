// Escreva uma função recursiva que determine quantas vezes um dígito K ocorre
// em um número natural N. Por exemplo, o dígito 2 ocorre 3 vezes em 762021192.

#include<stdio.h>

int contaDigr(int num, int dig, int qtd);

int main(){
	int num;
	int dig;
	printf("Digite um numero inteiro: ");
	scanf("%d", &num);
	printf("Digite o digito de busca: ");
	scanf("%d", &dig);

	printf("O digito %d ocorre %d vez(es) em %d.\n", dig, contarDig(num, dig, 0), num);

	return 0;
}

int contarDig(int num, int dig, int qtd){

	if(num > 0){
		if(num % 10 == dig){
			qtd++;
		}
		return contarDig(num / 10, dig, qtd);
	}
	return qtd;
}