//Faça um programa que leia a idade de duas pessoas e imprima a soma das idades

#include<stdio.h>
int main(){
  int age1, age2;

  printf("Idade da primeira pessoa: ");
  scanf("%d", &age1);
  printf("Idade da segunda pessoa: ");
  scanf("%d", &age2);
   
  printf("Soma = %d", age1 + age2);
	return 0;
}