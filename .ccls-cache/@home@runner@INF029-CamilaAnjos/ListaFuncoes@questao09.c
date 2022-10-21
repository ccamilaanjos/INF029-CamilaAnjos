/*Evolua o programa que tem a função cadastrarCliente, para fazer as validações dos dados. Cada
validação deve ser feita em uma função diferente, conforme lista abaixo. A função cadastrarCliente
deve chamar cada uma dessas funções. A função main deve imprimir se o cadastro foi realizado
com sucesso ou se houve erro, informando onde foi o erro:
• função validarNome: recebe o nome digitado, e valida se nome tem até 20 caracteres;
• função validarSexo: recebe o sexo digitado, e valida é um sexo válido (opções: m e M para
masculino; f e F para feminino, o e O para outro).
• função validarCPF: recebe o cpf digitado, e valida é um cpf válido;
• função validarNascimento: recebe a data digitada, e valida é uma data válida.*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define anoAtual 2022

int cadastrarCliente(int erros[]);
int validarNome(char nome[], int erros[]);
int validarSexo(char sexo[], int erros[]);
int validarCPF(char dataNasc[], int erros[]);
int validarNascimento(char dataNasc[], int erros[]);

int cadastrarCliente(int erros[]){
    char nome[100];
    char sexo[3];
    char cpf[16];
    char dataNasc[12];
    
    erros[0] = validarNome(nome, erros);
    erros[1] = validarSexo(sexo, erros);
    erros[2] = validarCPF(cpf, erros);
    erros[3] = validarNascimento(dataNasc, erros);

	return 0;
}

int validarNome(char nome[], int erros[]){
    int i;
    erros[0] = 0;
    
    // Lendo nome
    printf("\nNome\n[ate 20 caracteres]\n>> ");
	fgets(nome, 100, stdin);
	nome[strcspn(nome, "\n")] = 0;
	
	//Contando caracteres
	if(strlen(nome) > 20)
	    erros[0] = -1;

    return erros[0];
}

int validarSexo(char sexo[], int erros[]){
    erros[1] = 0;
    
    // Lendo sexo
    printf("\nSexo\n[F] Feminino\n[M] Masculino\n[O] Outro\n>> ");
    fgets(sexo, 3, stdin);
    sexo[strcspn(sexo, "\n")] = 0;
    
    if(sexo[0] != 'f' && sexo[0] != 'F' && sexo[0] != 'm' && sexo[0] != 'M' &&
        sexo[0] != 'o' && sexo[0] != 'O')
        erros[1] = -1;

    return erros[1];
}

int validarCPF(char cpf[], int erros[]){
    char aux[16];
    char dig[10];
    char verif1[3];
    char verif2[3];
    int i, j = 0;
    erros[2] = 0;

    do{
        j = 0;
        // Lendo cpf
        printf("\nCPF\n[xxx.xxx.xxx-xx]\n>> ");
        fgets(aux, 16, stdin);
        
        // Copiando apenas numeros para o vetor cpf
        for(i = 0; aux[i] != '\0'; i++){
            if(aux[i] >= 48 && aux[i] <= 57){
                cpf[j] = aux[i];
                j++;
            }
        }
        cpf[j] = '\0';

        if(j < 11)
            printf("Erro. CPF possui menos digitos que o esperado.\n");

    } while(j < 11);
    
    // Separando 9 primeiros digitos dos digitos verificadores
    for(i = 0, j = 0; i < 11; i++){
        while(i < 9){
            dig[j] = cpf[i];
            i++;
            j++;
        }
        if(i == 9)
            verif1[0] = cpf[i];
        else if(i == 10)
            verif2[0] = cpf[i];
    }

    dig[j] = '\0'; verif1[1] = '\0'; verif2[1] = '\0';

    int digitos;
    int vetDig[11];
    int soma;
    int vf1, vf2;
    int resto;

    // Convertendo digitos para um numero inteiro
    digitos = atoi(dig);

    // Convertendo digitos verificadores para numeros inteiros
    vf1 = atoi(verif1);
    vf2 = atoi(verif2);

    // Decompondo o numero em um vetor digito a digito
    vetDig[0] = ((digitos % 1000000000) / 100000000);
    vetDig[1] = ((digitos % 100000000) / 10000000);
    vetDig[2] = ((digitos % 10000000) / 1000000);
    vetDig[3] = ((digitos % 1000000) / 100000);
    vetDig[4] = ((digitos % 100000) / 10000);
    vetDig[5] = ((digitos % 10000) / 1000);
    vetDig[6] = ((digitos % 1000) / 100);
    vetDig[7] = (digitos % 100) / 10;
    vetDig[8] = digitos % 10;
    

    // Somando os nove digitos
    soma = 0;
    for(i = 0; i < 9; i++)
        soma = soma + (vetDig[i] * (i+1));

    // Verificando o primeiro digito
    resto = soma % 11;
    if(resto == 10)
        resto = 0;
    if(resto == vf1){
        // printf("\nPrimeio digito verificador correto");
        vetDig[9] = resto;
    }
    else
        erros[2] = -1;

    // Somando os dez digitos
    soma = 0;
    for(i = 0; i < 10; i++)
        soma = soma + (vetDig[i] * i);
    
    // Verificando o segundo digito
    resto = soma % 11;
    if(resto == 10)
        resto = 0;
    if(resto == vf2){
        // printf("\nSegundo digito verificador correto");
        vetDig[10] = resto;
    }
    else
        erros[2] = -1;

    return erros[2];  
}

int validarNascimento(char dataNasc[], int erros[]){
    
    char aux[12];
    int data;
    int dia, mes, ano;
    int i, j = 0;
    erros[3] = 0;
    
    do{
        j = 0;
        // Lendo data de nascimento;
        printf("\nData de nascimento\n[dd/mm/aaaa]\n>> ");
        fgets(aux, 12, stdin);
        
        // Copiando apenas numeros para o vetor dataNasc
        for(i = 0; aux[i] != '\0'; i++){
            if(aux[i] >= 48 && aux[i] <= 57){
                dataNasc[j] = aux[i];
                j++;
            }
        }
        dataNasc[j] = '\0';

        if(j < 8)
            printf("Erro. Formato errado\n");

    } while(j < 8);
    
    // Transformando a data (string) em data (int)
    data = atoi(dataNasc);
    
    ano = data % 10000;
    mes = (data / 10000) % 100;
    dia = (data / 10000) / 100;
    
    if(dia > 31)
        erros[3] = -1;
        // printf("\nDia invalido");
    if(mes > 12)
        erros[3] = -1;
        // printf("\nMes invalido");
    if(ano > anoAtual)
        erros[3] = -1;
        // printf("\nAno maior que o ano atual");
    
    int maxDias;
    if(mes == 2){
        if((ano % 400 == 0) || ((ano % 4 == 0) && (ano % 100 != 0))) {
            // Ano Bissexto
                maxDias = 29;
        }
        else {
            // Ano não bissexto
                maxDias = 28;
        }
        if(dia > maxDias)
            erros[3] = -1;
            // printf("Erro. O mes %d teve %d dias neste ano.", mes, maxDias);
    }
    else{
        if(mes == 4 || mes == 6 || mes == 9 || mes == 11)
            maxDias = 30;
        else
            maxDias = 31;
            
        if(dia > maxDias)
            erros[3] = -1;
            // printf("\nErro. O mes %d possui apenas %d dias", mes, maxDias);
    }

    return erros[3];
}

int main(){
    int erros[4], i, sucesso = 0;

    cadastrarCliente(erros);

    for(i = 0; i < 4; i++){
        if(erros[i] == 0)
            sucesso++;
    }
    // printf("\n%d", sucesso);
    if(sucesso == 4)
        printf("\nExito. Cadastro realizado com sucesso.");
    else{
        if(erros[0] == -1)
            printf("\nErro. Nome deve ter ate 20 caracteres.");
        if(erros[1] == -1)
            printf("\nErro. Sexo invalido.");
        if(erros[2] == -1)
            printf("\nErro. CPF invalido.");
        if(erros[3] == -1)
            printf("\nErro. Data de nascimento invalida.\n");
    }

    return 0;
}
