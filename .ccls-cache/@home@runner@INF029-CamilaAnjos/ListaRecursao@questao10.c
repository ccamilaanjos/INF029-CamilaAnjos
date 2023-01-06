/* A multiplicação de dois números inteiros pode ser feita através de somas
sucessivas. Proponha um algoritmo recursivo Multip_Rec(n1,n2) que calcule a
multiplicação de dois inteiros. */

#include<stdio.h>

int Multip_Rec(int n1, int n2);
	
int main(){
	int n1, n2;

	printf("Digite um inteiro n1: ");
	scanf("%d", &n1);
	printf("Digite um inteiro n2: ");
	scanf("%d", &n2);

	printf("\n%d vezes %d = %d\n", n1, n2, Multip_Rec(n1, n2));
	
	return 0;
}

int Multip_Rec(int n1, int n2){
	if(n1 == 1){
		return n2;
	}
	else{
		return n2 + Multip_Rec(n1 - 1, n2);
	}
}