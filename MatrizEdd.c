#include<stdio.h>
#include<stdlib.h>

int main(){
	
	int linhas, colunas; 
	int **matriz=NULL;
	
	printf("Digite o numero de linhas: ");
	scanf("%i", &linhas);
	printf("Digite o numero de colunas: ");
	scanf("%i", &colunas);
	
	matriz=(int **) calloc(linhas, sizeof(int *));
	if(matriz==NULL){
		printf("Erro! Falha ao alocar memoria!\n");
		return 1;
	}
	
	for(int i=0; i<linhas; i++){
		matriz[i]=(int *) calloc(linhas, sizeof(int));
		
		if(matriz==NULL){
			printf("Erro! Falha ao alocar memoria!\n");
			return 1;
		}
	}
	
	printf("\nMatriz recem criada: inicializada com zeros\n");
	for(int i=0; i<linhas; i++){
		for(int j=0; j<colunas; j++){
			printf("%i ", matriz[i][j]);
		}
		printf("\n");
	}
	
	printf("\n");
	for(int i=0; i<linhas; i++){
		for(int j=0; j<colunas; j++){
			printf("Insira o dado [%d][%d]: ", i, j);
			scanf("%i", &matriz[i][j]);
		}
	}
	
	printf("\nMatriz Formatada!\n");
	for(int i=0; i<linhas; i++){
		for(int j=0; j<colunas; j++){
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}
	
	for(int i=0; i<linhas; i++){
		free(matriz[i]);
	}
	
	free(matriz);
	matriz=NULL;
	
	return 0;
	
}
