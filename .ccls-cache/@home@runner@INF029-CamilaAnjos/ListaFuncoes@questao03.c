/*Faça um programa que tenha uma função que recebe um número inteiro e retorna o fatorial deste número.
Esta função deve ainda verificar se é possível calcular o fatorial, se não for, ela deve de alguma
forma retornar para a main que deu algum erro. A função main deve solicitar o valor do usuário e
imprimir o fatorial dele, ou se não é possível calcular o fatorial*/

#include<stdio.h>

int calculaFatorial(int n){
	int i, fact;
	if(n >= 0){
		if(n == 0)
			fact = 1;
		else{
			fact = n;
			for(i = 2; i < n; i++)
				fact = fact * i;
		}
	}
	else
		fact = -1;

	return fact;
}

int main(){
	int num;
	printf("Insira um inteiro: ");
	scanf("%d", &num);

	int result = calculaFatorial(num);
	if(result == -1)
		printf("\nNao foi possivel calcular o fatorial.");
	else
		printf("\n%d! = %d", num, result);

	return 0;
}
