// Crie um programa que leia um número n de idades, e imprima a todas idades maior que a média delas

#include<stdio.h>
int main(){
	int total;
	float sum = 0, avg;

	printf("Insira a quantidade de idades: ");
	scanf("%d", &total);

	int age[total], i;

	printf("\n");
	for(i = 0; i < total; i++){
		printf("Idade %d: ", i+1);
		scanf("%d", &age[i]);
		sum = sum + age[i];
	}
	avg = sum / total;

	printf("\nMedia: %.2f\n", avg);
	printf("\nIdades maiores que a media:\n");
	for(i = 0; i < total; i++){
		if (age[i] > avg)
			printf("%d\n", age[i]);
	}

	return 0;
}
