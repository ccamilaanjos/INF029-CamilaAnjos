// Crie uma função recursiva que receba um número inteiro positivo N e calcule o
// somatório dos números de 1 a N.

#include<stdio.h>

int soma(int num, int i);

int main(){
	int num = 0;
	
	while(num < 1){
		printf("Digite um valor N inteiro e positivo: ");
		scanf("%d", &num);
		if(num < 1)
			printf("Valor invalido\n");
	}

	printf("A soma dos numeros de 1 a %d e igual a %d", num, soma(num, 1));

	return 0;
}

int soma(int num, int i){
	
	if(i > num){
		return 0;
	}
	else{
		return i + soma(num, i + 1);
	}
}