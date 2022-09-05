/*Crie um programa que tenha uma função cadastrarCliente. Essa função deve ler os dados do cliente (nome, dataNascimento,
cpf, sexo) e retornar os dados do cliente. A função main deve imprimir os dados do cliente*/

#include<stdio.h>
#include<string.h>

void cadastrarCliente(char nome[], char cpf[], char dataNascimento[], char sexo[]){
	printf("Nome...............: ");
	fgets(nome, 70, stdin);
	nome[strcspn(nome, "\n")] = 0;
	
	printf("Data de nascimento.: ");
	fgets(dataNascimento, 12, stdin);
	dataNascimento[strcspn(dataNascimento, "\n")] = 0;
	
	printf("CPF................: ");
	fgets(cpf, 16, stdin);
	cpf[strcspn(cpf, "\n")] = 0;
	
	printf("Sexo...............: ");
	fgets(sexo, 3, stdin);
	sexo[strcspn(sexo, "\n")] = 0;
}

int main(){
	char nome[70];
	char dataNascimento[12];
	char cpf[16];
	char sexo[3];

	cadastrarCliente(nome, cpf, dataNascimento, sexo);
	
	printf("\n\n\tCLIENTE CADASTRADO\n");
	printf("\nNome...............: %s", nome);
	printf("\nData de nascimento.: %s", dataNascimento);
	printf("\nCPF................: %s", cpf);
	printf("\nSexo...............: %s", sexo);

	return 0;
}
