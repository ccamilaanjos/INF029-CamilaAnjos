//Faça um programa que leia os dados de nome, idade, sexo e cpf de 5 pessoas.
//Ao final imprima tudo. Utilize vetor e struct.

#include<stdio.h>
#include<string.h>

	typedef struct{
		char nome[70];
		int idade;
		char sexo;
		char cpf[14];
	} Pessoa;

int main(){
	int i, j;
	
	Pessoa dado[5];
	
	for(i = 0; i < 5; i++){
		printf("\nNome.....: ");
		fgets(dado[i].nome, 70, stdin);
		dado[i].nome[strcspn(dado[i].nome, "\n")] = 0;
		fflush(stdin);
		printf("Idade....: ");
		scanf("%d", &dado[i].idade); fflush(stdin);
		printf("Sexo.....: ");
		scanf("%c", &dado[i].sexo); fflush(stdin);
		printf("CPF......: ");
		fgets(dado[i].cpf, 70, stdin);
		dado[i].cpf[strcspn(dado[i].cpf, "\n")] = 0;
		fflush(stdin);
	}

	printf("\n\nRegistros:\n\n");
	for(i = 0; i < 5; i++)
		printf("Nome: %s\n%d anos\nSexo '%c'\nCPF: %s\n\n", dado[i].nome, dado[i].idade, dado[i].sexo, dado[i].cpf);    

	return 0;
}
