// Evoluir o programa anterior para ler também o nome das pessoas e imprimir o nome e a idade de todos que forem maior que a média.

#include<stdio.h>
int main(){
	int total;
	float sum = 0, avg;

	printf("Quantidade de idades: ");
	scanf("%d", &total);

	int age[total], i;
	char name[total][15];

	printf("\n");
	for(i = 0; i < total; i++){
		printf("\nPrimeiro nome da pessoa %d...: ", i+1);
		scanf("%s", &name[i]);
		printf("Idade.......................: ");
		scanf("%d", &age[i]);
		sum = sum + age[i];
	}
	avg = sum / total;

	printf("\nMedia: %.2f\n", avg);
	printf("\nPessoas com idade maior que a media:\n");
	for(i = 0; i < total; i++){
		if (age[i] > avg){
			printf("%s - ", name[i]);
			printf("%d\n", age[i]);
		}
	}

	return 0;
}
