/* Faça um programa que tenha uma função ordena que recebe um vetor de inteiros e ordene os
valores. A função main deve ler do usuário os valores (ex. 5 valores), chamar a função ordena, e
depois imprimir os valores ordenados. */

#include <stdio.h>
#define N 5

void ordena();

int main(){
    int vetInt[N];
    int i;
    
    for(i = 0; i < N; i++){
        scanf("%d", &vetInt[i]);
    }
    
    ordena(vetInt);
    
    printf("\nNumeros ordenados:\n");
    for(i = 0; i < N; i++){
        printf("%d  ", vetInt[i]);
    }

    return 0;
}

void ordena(int *vetor){
    int i, j;
    int aux;

	// Insertion Sort
    for(i = 1; i < N; i++){
        aux = vetor[i];
        for(j = i; (aux < vetor[j - 1]) && (j > 0); j--){
            vetor[j] = vetor[j - 1];
        }
        vetor[j] = aux;
    }
}
