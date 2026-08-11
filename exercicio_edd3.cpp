#include<stdio.h>
#include<stdlib.h>

int buscaRecursiva(int vetor[], int inicio, int fim, int valor){
	
	if(inicio>fim){
		return -1;
	}
	
	int meio=inicio+(fim-inicio)/2;
	if(vetor[meio]==valor){
		return meio;
	}
	
	if(valor<vetor[meio]){
		return buscaRecursiva(vetor, inicio, meio-1, valor);
	}
	
	return buscaRecursiva(vetor, meio+1, fim, valor);
}

int main(){
	
	int vetor[]={3, 7, 12, 18, 25, 30};
	int tamanho=sizeof(vetor)/sizeof(vetor[0]);
	int valor=3;
	
	int posicao=buscaRecursiva(vetor, 0, tamanho-1, valor);
	
	if(posicao!=-1){
		printf("Elemento encontrado na posicao %d\n", posicao+1);
	} else {
		printf("Elemento nao encoontrado(-1)\n");
	}
	
return 0;

}
