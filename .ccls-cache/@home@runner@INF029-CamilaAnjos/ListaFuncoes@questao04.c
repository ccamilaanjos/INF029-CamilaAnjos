/*Crie um programa que tenha uma função ler3Numeros. Essa função deve ler três números do
usuário e retornar os três números. A função main deve imprimir esses três números. Utilize vetor
para fazer o retorno*/

#include <stdio.h>
#define len 3

void ler3Numeros(int values[]){
	for(int i = 0; i < len; i++)
		scanf("%d", &values[i]);
}

int main(){
	int nums[len];

	printf("Insira %d numeros:\n", len);
	ler3Numeros(nums);
	
	printf("\nNumeros digitados: ");
	for(int i = 0; i < len; i++)
		printf("%d  ", nums[i]);

	return 0;
}
