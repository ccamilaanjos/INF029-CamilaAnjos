//Faça um programa que leia 10 números do usuário e informe quais deles são primos.
//Além disso, mostre a soma de todos os números primos existentes.

#include<stdio.h>
int main(){
	int num[10];
	int i, div, divcont, soma = 0;

	printf("Insira 10 numeros:\n");
	for(i = 0; i < 10; i++)
		scanf("%d", &num[i]);

	for(i = 0; i < 10; i++){
		divcont = 0;
		for(div = 1; div <= num[i]; div++){
			if(num[i] % div == 0)
				divcont++;
		}
		if(divcont == 2){
			printf("\n%d e primo", num[i]);
			soma = soma + num[i];
		}
	}

	printf("\n\nSoma dos numeros primos: %d", soma);

	return 0;
}
