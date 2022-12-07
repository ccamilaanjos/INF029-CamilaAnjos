#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "EstruturaVetores.h"

Auxiliar vetorPrincipal[TAM];

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'
Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/

int criarEstruturaAuxiliar(int posicao, int tamanho) {

	// se posição é um valor válido {entre 1 e 10}
	if(!ehPosicaoValida(posicao)){
		return POSICAO_INVALIDA;
	}
	// a posicao pode já existir estrutura auxiliar
	else if(haEstruturaAux(posicao)){
		return JA_TEM_ESTRUTURA_AUXILIAR;
	}
	// o tamanho nao pode ser menor que 1
	else if(tamInvalido(tamanho)){
		return TAMANHO_INVALIDO;
	}
	// deu tudo certo, crie
	else{
		vetorPrincipal[posicao - 1].estrutura = (int*) malloc(tamanho * sizeof(int));
		vetorPrincipal[posicao - 1].tamanho = tamanho;
		
		// o tamanho ser muito grande
		if(!temEspacoNaMemoria(posicao))
			return SEM_ESPACO_DE_MEMORIA;
	}
	
	return SUCESSO;
}

int haEstruturaAux(int posicao){
	int retorno = 0;
	
	if(vetorPrincipal[posicao - 1].estrutura != NULL){
		retorno = JA_TEM_ESTRUTURA_AUXILIAR;
	}
	return retorno;
}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao) {
	
	if (posicao < 1 || posicao > 10) {
		return 0;
	}
	else{
		return 1;
	}
}

int tamInvalido(int tamanho){
	int retorno = 0;
	
	if(tamanho < 1){
		retorno = TAMANHO_INVALIDO;
	}

	return retorno;
}

int temEspacoNaMemoria(int posicao){
	
	if(!vetorPrincipal[posicao - 1].estrutura){
		return 0;
	}
	else{
		return 1;
	}
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Retorno (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/

int inserirNumeroEmEstrutura(int posicao, int valor) {
  int retorno = 0;
	
	if (!ehPosicaoValida(posicao))
		retorno = POSICAO_INVALIDA;
	else{
		// testar se existe a estrutura auxiliar
		if(haEstruturaAux(posicao)){
			if(temEspacoNaLista(posicao)){
				posicao--;
				vetorPrincipal[posicao].estrutura[vetorPrincipal[posicao].qtd] = valor;
				vetorPrincipal[posicao].qtd++;
				retorno = SUCESSO;
			}
			else{
				retorno = SEM_ESPACO;
			}
		}
		else{
			retorno = SEM_ESTRUTURA_AUXILIAR;
		}
	}

  return retorno;
}

int temEspacoNaLista(int posicao){
	int retorno = 0;
	posicao--;
	
	if(vetorPrincipal[posicao].qtd < vetorPrincipal[posicao].tamanho){
		retorno = 1;
	}
		
	return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar
da seguinte forma [3, 8, 7,  ,  ,  ]. Obs. Esta é uma exclusão lógica
Retorno(int)
	SUCESSO - excluido com sucesso
	ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/

int excluirNumeroDoFinaldaEstrutura(int posicao) {
	int retorno;
	
	if(!ehPosicaoValida(posicao)){
		retorno = POSICAO_INVALIDA;
	}
	else if(!haEstruturaAux(posicao)){
		retorno = SEM_ESTRUTURA_AUXILIAR;
	}
	else if(estruturaVazia(posicao)){
		retorno = ESTRUTURA_AUXILIAR_VAZIA;
	}
	else{
		vetorPrincipal[posicao - 1].qtd--;
				
		retorno = SUCESSO;
	}
	
	return retorno;
}

int estruturaVazia(int posicao){
	int retorno = 0;
	
	if(vetorPrincipal[posicao - 1].qtd == 0){
		retorno = ESTRUTURA_AUXILIAR_VAZIA;
	}
	
	return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições
anteriores ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o
valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ] Obs. Esta é
uma exclusão lógica Retorno (int) SUCESSO - excluido com sucesso 'valor' da
estrutura na posição 'posicao'
	ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/

int excluirNumeroEspecificoDeEstrutura(int posicao, int valor) {
	int retorno;

	if(!ehPosicaoValida(posicao)){
		retorno = POSICAO_INVALIDA;
	}
	else if(!haEstruturaAux(posicao)){
		retorno = SEM_ESTRUTURA_AUXILIAR;
	}
	else if(vetorPrincipal[posicao - 1].qtd == 0){
		retorno = ESTRUTURA_AUXILIAR_VAZIA;
	}
	else{
		posicao--;
		int i, j, existe = 0, posNum;

		// Busca do numero na estrutura
		for(i = 0; i < vetorPrincipal[posicao].qtd; i++){
			if(vetorPrincipal[posicao].estrutura[i] == valor){
				existe = 1;
				posNum = i;
				break;
			}
		}

		// Se o numero existe na estrutura
		if(existe){
			for(j = posNum; j < vetorPrincipal[posicao].qtd; j++){
				vetorPrincipal[posicao].estrutura[j] = vetorPrincipal[posicao].estrutura[j + 1];
			}
			vetorPrincipal[posicao].qtd--;
			
			retorno = SUCESSO;

		}
		else{
			retorno = NUMERO_INEXISTENTE;
		}	
	}
	
	return retorno;
}

/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux
Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
	SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
	POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/

int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]) {
	int retorno;

	if(!ehPosicaoValida(posicao)){
		retorno = POSICAO_INVALIDA;
	}
	else if(!haEstruturaAux(posicao)){
		retorno = SEM_ESTRUTURA_AUXILIAR;
	}
	else{
		for(int i = 0; i < vetorPrincipal[posicao - 1].qtd; i++){
			vetorAux[i] = vetorPrincipal[posicao - 1].estrutura[i];
		}
		
		retorno = SUCESSO;
	}
	
	return retorno;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao
(1..10)'. os números devem ser armazenados em vetorAux
Retorno (int)
	SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/

int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]) {
	int retorno = 0;

	if(!ehPosicaoValida(posicao)){
		retorno = POSICAO_INVALIDA;
	}
	else if(!haEstruturaAux(posicao)){
		retorno = SEM_ESTRUTURA_AUXILIAR;
	}
	else{	
		for(int i = 0; i < vetorPrincipal[posicao - 1].qtd; i++){
			vetorAux[i] = vetorPrincipal[posicao - 1].estrutura[i];
		}
		ordenarDados(vetorAux, vetorPrincipal[posicao - 1].qtd);
		retorno = SUCESSO;
	}
	
	return retorno;
}

void ordenarDados(int vetorAux[], int N){
	int i, j, menor, aux;
	
	// Selection Sort
	for(i = 0; i < N - 1; i++){
        menor = i;
        for(j = i + 1; j < N; j++){
            if(vetorAux[j] < vetorAux[menor]){
                menor = j;
            }
        }
        if(i != menor){
            aux = vetorAux[i];
            vetorAux[i] = vetorAux[menor];
            vetorAux[menor] = aux;
        }
    }
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux
Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
	TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares
estão vazias
*/

int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]) {
	int retorno;

	if(todasEstruturasVazias()){
		retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
	}
	else{
		int posicao, j, k = 0;

		for(posicao = 0; posicao < TAM; posicao++){
			if(!estruturaVazia(posicao + 1)){
				for(j = 0; j < vetorPrincipal[posicao].qtd; j++){
					vetorAux[k] = vetorPrincipal[posicao].estrutura[j];
					k++;
				}
			}
		}
		
		retorno = SUCESSO;
	}
	
	return retorno;
}

int todasEstruturasVazias(){
	int vazias = 0;

	for(int i = 0; i < TAM; i++){
		if(estruturaVazia(i))
			vazias++;
	}
	if(vazias == TAM){
		return 1;
	}
	else
		return 0;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux
Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição
'posicao' TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares
estão vazias
*/

int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]) {
	int retorno = 0;

	if(todasEstruturasVazias()){
		retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
	}
	else{
		int posicao, j, k = 0, total = 0;

		// Contando elementos de toda a estrutura
		for(posicao = 0; posicao < TAM; posicao++){
			if(!estruturaVazia(posicao + 1)){
				total = total + vetorPrincipal[posicao].qtd;
				for(j = 0; j < vetorPrincipal[posicao].qtd; j++){
					vetorAux[k] = vetorPrincipal[posicao].estrutura[j];
					k++;
				}
			}
		}
		ordenarDados(vetorAux, total);
		
		retorno = SUCESSO;
	}
	
	return retorno;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o
novo tamanho 'novoTamanho' + tamanho atual Suponha o tamanho inicial = x, e novo
tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser
sempre >= 1
Retorno (int)
	SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/

int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho) {
	int retorno;
	novoTamanho = novoTamanho + vetorPrincipal[posicao - 1].tamanho;
	
	if(!ehPosicaoValida(posicao)){
		retorno = POSICAO_INVALIDA;
	}
	else if(!haEstruturaAux(posicao)){
		retorno = SEM_ESTRUTURA_AUXILIAR;
	}
	else if(tamInvalido(novoTamanho)){
		retorno = NOVO_TAMANHO_INVALIDO;
	}
	else{
		int pos = posicao - 1;
		int *vetor = vetorPrincipal[pos].estrutura;
		vetor = (int*) realloc(vetor, novoTamanho * sizeof(int));
		if(!temEspacoNaMemoria(posicao)){
			retorno = SEM_ESPACO;
		}
		else{
			if(novoTamanho < vetorPrincipal[pos].qtd){
				vetorPrincipal[pos].qtd = novoTamanho;
			}
			
			vetorPrincipal[pos].tamanho = novoTamanho;
			
			retorno = SUCESSO;
		}
	}
	
	return retorno;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da
posição 'posicao'.
Retorno (int)
	POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/

int getQuantidadeElementosEstruturaAuxiliar(int posicao) {
	int retorno = 0;

	if(!ehPosicaoValida(posicao)){
		retorno = POSICAO_INVALIDA;
	}
	else if(!haEstruturaAux(posicao)){
		retorno = SEM_ESTRUTURA_AUXILIAR;
	}
	else if(estruturaVazia(posicao)){
		retorno = ESTRUTURA_AUXILIAR_VAZIA;
	}
	else{
		retorno = vetorPrincipal[posicao - 1].qtd;
	}
	
	return retorno;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes
em todas as estruturas. Retorno (No*) NULL, caso não tenha nenhum número nas
listas No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote() { return NULL; }

/*
Objetivo: retorna os números da lista encadeada com cabeçote armazenando em
vetorAux. Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[]) {}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.
Retorno
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio) {}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa
*/
void inicializar() {
	for(int i = 0; i < TAM; i++){
		vetorPrincipal[i].estrutura = NULL;
		vetorPrincipal[i].qtd = 0;
		vetorPrincipal[i].tamanho = 0;
	}
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa
para poder liberar todos os espaços de memória das estruturas auxiliares.
*/
void finalizar() {
  for(int i = 0; i < TAM; i++){
		free(vetorPrincipal[i].estrutura);
	}
}