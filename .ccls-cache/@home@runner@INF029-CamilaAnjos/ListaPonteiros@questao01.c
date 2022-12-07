/*Crie um programa que defina variáveis do tipo int, char, string [10 posições], float, double. Deve
ser definido também uma variável ponteiro para cada um dos tipos acima. Faça leituras (scanf) e
escrita (printf) das variáveis primitivas e depois faça o mesmo utilizando ponteiros. */

#include<stdio.h>

int main(){
	int inteiro;
	char caractere;
	char string[10];
	float flutuante;
	double real;

    printf("Int: "); scanf("%d", &inteiro);
	printf("Char: "); scanf(" %c", &caractere);
	printf("String: "); scanf("%s", string);
	printf("Float: "); scanf("%f", &flutuante);
	printf("Double: "); scanf("%lf", &real);

	printf("\nInt: %d\n", inteiro);
	printf("Char: %c\n", caractere);
	printf("String: %s\n", string);
	printf("Float: %.3f\n", flutuante);
	printf("Double: %.3lf\n", real);

	int *pInt = &inteiro;
	char *pChar = &caractere;
	char *pStr = string;
	float *pFloat = &flutuante;
	double *pDou = &real;

    printf("---------------------\n");
	printf("Int: "); scanf("%d", pInt);
	printf("Char: "); scanf(" %c", pChar);
	printf("String: "); scanf("%s", pStr);
	printf("Float: "); scanf("%f", pFloat);
	printf("Double: "); scanf("%lf", pDou);

	printf("\nInt: %d\n", inteiro);
	printf("Char: %c\n", caractere);
	printf("String: %s\n", string);
	printf("Float: %.3f\n", flutuante);
	printf("Double: %.3lf\n", real);
	
	printf("\nInt: %d\n", *pInt);
	printf("Char: %c\n", *pChar);
	printf("String: %s\n", pStr);
	printf("Float: %.3f\n", *pFloat);
	printf("Double: %.3lf\n", *pDou);
}