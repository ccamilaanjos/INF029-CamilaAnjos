/*Crie um programa que tenha uma função ler4Numeros.Essa função deve ler quatro números do usuário e retornar os quatro números. A função main deve imprimir esses quatro números.Utilize struct para fazer o retorno.*/

#include <stdio.h>
#define len 4

struct Values{
	int number;
};

void ler4numeros(struct Values numbers[]){
	for(int i = 0; i < len; i++)
		scanf("%d", &numbers[i].number);
}

int main(){
	struct Values num[len];

	printf("Insira %d numeros:\n", len);
	ler4numeros(num);

	printf("\nNumeros digitados: ");
	for(int i = 0; i < len; i++)
		printf("%d  ", num[i].number);

	return 0;
}
