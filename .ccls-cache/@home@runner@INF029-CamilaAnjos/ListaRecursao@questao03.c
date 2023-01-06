// Faça uma função recursiva que permita inverter um número inteiro N. Ex: 123 - 321

#include<stdio.h>
#include<math.h>

int inverter(int num, int dig, int aux);
int contaDigitos(int num);

int main(){
	int num, dig;

	printf("Digite um numero inteiro: ");
	scanf("%d", &num);

    dig = contaDigitos(num);
    
	printf("\nO numero inverso de %d e %d", num, inverter(num, dig, 0));

	return 0;
}

int contaDigitos(int num){
    int dig = 0;
    
    while(num > 0){
        num = num / 10;
        dig++;
    }
    
    return dig;
}

int inverter(int num, int dig, int aux){
	if(dig == 0){
	    return aux;
	}
	else{
    	aux = aux + ((num % 10) * pow(10, dig - 1));
    	
	    return inverter(num / 10, dig - 1, aux);
	}
} 