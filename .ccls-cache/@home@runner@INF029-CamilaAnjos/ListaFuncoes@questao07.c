/*Crie um programa que tenha uma função ler3Palavras. Essa função deve ler três palavras do
usuário e retornar as três palavras. A função main deve imprimir essas três palavras.*/

#include<stdio.h>
#define len 30

void ler3Palavras(char word[]){
	fgets(word, 30, stdin);
	
	for(int i = 0; word[i] != '\0'; i++){
		if(word[i] == '\n')
			word[i] = '\0';
	}
}

int main(){
	char w1[len], w2[len], w3[len];
	
	printf("Insira 3 palavras:\n");
	ler3Palavras(w1);
	ler3Palavras(w2);
	ler3Palavras(w3);

	printf("\nPalavras digitadas: %s, %s, %s", w1, w2, w3);

	return 0;
}
