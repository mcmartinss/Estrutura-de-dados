#include<stdio.h>
#include<stdlib.h>

int buscaRecursiva(int vetor[], int inicio, int fim, int valor){
	
	int meio=(inicio+fim)/2;
	
	if(inicio>fim){
		return -1;
	}
	
	if(vetor[meio]==valor){
		return meio;
	}
	
	if(vetor[meio]>valor){
		return buscaRecursiva(vetor, inicio, meio-1, valor);
	} else {
		return buscaRecursiva(vetor, meio+1, fim, valor);
	}
	
}

int main(){
	
	int vetor[]={3, 7, 12, 18, 25, 30};
	int valorBuscado=18;
	int tamanho=sizeof(vetor)/sizeof(vetor[0]);
	int ini=0;
	int fim=tamanho-1;
	int posicao;
	
	posicao=buscaRecursiva(vetor, ini, fim, valorBuscado);
	
	if(posicao!=-1){
		printf("Elemento 18 na posicao %i\n", posicao);
	} else {
		printf("Elemento nao encontrado no vetor %d\n");
	}
	
	return 0;
}
