//Faça um programa que leia dois valores informados pelo usuário e inverta os valores nas variáveis lidas

#include<stdio.h>
int main(){
  int v1, v2, aux;

	printf("Valor 1: ");
  scanf("%d", &v1);
  printf("Valor 2: ");
  scanf("%d", &v2);

	aux = v1;
  v1 = v2;
  v2 = aux;
	
	printf("\nValor 1: %d\nValor 2: %d", v1, v2);
  return 0;
}