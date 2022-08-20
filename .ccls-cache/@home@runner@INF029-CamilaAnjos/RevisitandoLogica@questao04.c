//Faça um programa que leia dois valores informados pelo usuário e inverta os valores nas variáveis lidas sem utilizar variável auxiliar

#include<stdio.h>
int main(){
  int v1, v2;
  printf("Valor 1: ");
  scanf("%d", &v1);
  printf("Valor 2: ");
  scanf("%d", &v2);

  v1 = v1 + v2;
  v2 = v1 - v2;
  v1 = v1 - v2;
  printf("\nValor 1: %d\nValor 2: %d", v1, v2);
  return 0;
}