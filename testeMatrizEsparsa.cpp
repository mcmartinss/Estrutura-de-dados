#include<stdio.h>
#include<stdlib.h>

#define MAXNZ 100

typedef struct No{
	int linhas;
	int colunas;
	int valor;
} No;

typedef struct{
	int totalLinhas;
	int totalColunas;
	int n;
	No dados[MAXNZ];
} matrizEsparsa;

void iniciarMatriz(matrizEsparsa *m, int linhas, int colunas){
	
	m->totalLinhas=linhas;
	m->totalColunas=colunas;
	m->n=0;
	
}

void inserirMatriz(matrizEsparsa *m, int l, int c, int v){
	
	if(m->n < MAXNZ){
		m->dados[m->n].linhas=l;
		m->dados[m->n].colunas=c;
		m->dados[m->n].valor=v;
		m->n++;
	}
	
}

void imprimirMatriz(matrizEsparsa *m){
	
	int k=0;
	for(int i=0; i<m->totalLinhas; i++){
		for(int j=0; j<m->totalColunas; j++){
			if(k < m->n && m->dados[k].linhas==i && m->dados[k].colunas==j){
				printf("%d ", m->dados[k].valor);
				k++;
			} else {
				printf("0 ");
			}
		}
		printf("\n");
	}
	
}

int main(){
	
	matrizEsparsa m;
	iniciarMatriz(&m, 5, 6);
	
	inserirMatriz(&m, 0, 2, 5); // Linha 0, Coluna 2 -> Valor 5
    inserirMatriz(&m, 1, 4, 8); // Linha 1, Coluna 4 -> Valor 8
    inserirMatriz(&m, 2, 1, 3); // Linha 2, Coluna 1 -> Valor 3
    inserirMatriz(&m, 3, 3, 7); // Linha 3, Coluna 3 -> Valor 7
    
    printf("\nMATRIZ ESPARSA\n");
    imprimirMatriz(&m);
    
    return 0;
}
