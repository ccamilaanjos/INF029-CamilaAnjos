//Faça um programa que leia a idade de uma pessoa e informe se ela é de maior ou menor

#include<stdio.h>
int main(){
	int age;

	printf("\nIdade: ");
	scanf("%d", &age);

	if(age >= 18)
		printf("Maior de idade");
	else
		printf("Menor de idade");
	
	return 0;
}
