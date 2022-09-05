/*Crie um programa que tenha uma função ler3Letras. Essa função deve ler três letras do usuário
e retornar as três letras. A função main deve imprimir essas três letras.*/

#include<stdio.h>

char ler3Letras(char letra){
    scanf(" %c", &letra);
    return letra;
}
int main(){
    char x, y, z;
    
    printf("Insira 3 letras:\n");
    x = ler3Letras(x);
    y = ler3Letras(y);
    z = ler3Letras(z);

    printf("\nLetras digitadas: %c, %c, %c", x, y, z);

	return 0;
}
