//Faça um programa que verifique se um número é primo

#include<stdio.h>
int main(){
	int num, div = 0, divcont = 0;

	printf("Insira um inteiro: ");
	scanf("%d", &num);

	for(div = 1; div <= num; div++){
		if(num % div == 0)
			divcont++;
	}
	if(divcont == 2)
		printf("Primo");
	else
		printf("Nao e primo");

	return 0;
}
