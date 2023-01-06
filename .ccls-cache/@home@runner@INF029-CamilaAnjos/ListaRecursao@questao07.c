// Crie um programa em C que receba um vetor de números reais com 100 elementos.
// Escreva uma função recursiva que inverta ordem dos elementos presentes no vetor.

#include<stdio.h>
#define MAX 5

void inverter(float *vet, int i, int f);

int main(){
	// float vetor[MAX] = {1.0, 2.0, 3.0, 4.0, 5.0};
	float vetor[MAX];

	printf("Digite %d numeros:\n", MAX);
	for(int i = 0; i < MAX; i++){
		scanf("%f", &vetor[i]);
	}
	printf("\nForam digitados:\n");
	for(int i = 0; i < MAX; i++){
		printf("%.2f  ", vetor[i]);
	}
	
	inverter(vetor, 0, MAX - 1);
	
	printf("\n\nVetor invertido:\n");
	for(int i = 0; i < MAX; i++){
		printf("%.2f  ", vetor[i]);
	}

	return 0;
}

void inverter(float *vet, int i, int f){
	float aux;

	if(i < f){
		aux = vet[i];
		vet[i] = vet[f];
		vet[f] = aux;
		return inverter(vet, i + 1, f - 1);
	}
}