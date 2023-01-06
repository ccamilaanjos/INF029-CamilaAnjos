// Faça uma função recursiva que permita somar os elementos de um vetor de inteiros.

#include<stdio.h>
#define MAX 6

int somarVetor(int *vet, int i);

int main(){
	int vetor[MAX] = {1, 4, 6, 3, 10, 5};

	printf("A soma dos valores e igual a %d", somarVetor(vetor, 0));

	return 0;
}

int somarVetor(int *vet, int i){
	
	if(i == MAX){
		return 0;
	}
	else{
		return vet[i] + somarVetor(vet, i + 1);
	}
}