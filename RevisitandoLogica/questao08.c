//Faça um programa que calcula o fatorial de um número

#include<stdio.h>
int main(){
	int num, i, fatorial;

	printf("Insira um inteiro: ");
	scanf("%d", &num);

	fatorial = num;
	for(i = 2; i < num; i++)
		fatorial = fatorial * i;

	printf("%d! = %d", num, fatorial);

	return 0;
}
