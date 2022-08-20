//Faça um programa que leia a idade de uma pessoa e informe de ela é de maior ou de menor.
//O programa deve repetir essa ação até que uma idade negativa seja informada

#include<stdio.h>
int main(){
	int age;

	while(age >= 0){
		printf("\nIdade: ");
		scanf("%d", &age);
		if(age >= 18)
			printf("Maior de idade");
		else if(age < 0)
			break;
		else
			printf("Menor de idade");
	}
    return 0;
}