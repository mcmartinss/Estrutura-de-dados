#include<stdio.h>
#include<stdlib.h>

int main(){
	
	int n, soma;
	int *vetor=NULL; 
	
	printf("Digite a quantidade de elementos desejados: ");
	scanf("%i", &n);
	
	vetor = (int*) calloc(n, sizeof(int));
	if(vetor==NULL){
		printf("Erro! Nao foi possivel alocar memoria!\n");
		return 1;
	} 
	
	for(int i=0; i<n; i++){
		printf("Digite o numero: ");
		scanf("%i", &vetor[i]);
		soma += vetor[i];
	}
	
	float media=(float)soma/n;
	
	printf("Soma final: %i\n", soma);
	printf("Media final: %.2f\n", media);
	
	free(vetor);
	vetor=NULL;
	
	return 0;
}
