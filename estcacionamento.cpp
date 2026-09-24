#include<stdio.h>
#include<stdlib.h>

#define TAM_LINHAS 10
#define TAM_COLUNAS 10

typedef struct No{
	int linhas;
	int colunas;
	int valor;
	struct No* prox;
} No;

typedef struct{
	int totalLinhas;
	int totalColunas;
	No* head;
} matrizEsparsa;

void iniciarMatriz(matrizEsparsa *m){
	
	m->totalLinhas=TAM_LINHAS;
	m->totalColunas=TAM_COLUNAS;
	m->head=NULL;
	
}

void inserirMatriz(matrizEsparsa *m, int linha, int coluna, int valor){
	
	if(linha<0 || linha>=m->totalLinhas || coluna<0 || coluna>=m->totalColunas){
		printf("\nErro! Posicao fora dos limites do estacionamento\n");
		return;
	}
	
	if(valor==0){
		No* atual=m->head;
		No* ant=NULL;
		while(atual!=NULL){
			if(atual->linhas==linha && atual->colunas==coluna){
				if(ant==NULL){
					m->head=atual->prox;
				} else{
					ant->prox=atual->prox;
				}
			free(atual);
			printf("\nVaga [%d] [%d] liberada com sucesso!\n", linha, coluna);
			return;
			}
		ant=atual;
		atual=atual->prox;
		}
	return;
	}
	
	No* atual=m->head;
	while(atual!=NULL){
		if(atual->linhas == linha && atual->colunas == coluna) {
            atual->valor = valor;
            printf("Vaga (%d, %d) atualizada com o veiculo %d.\n", linha, coluna, valor);
            return;
        }
        atual = atual->prox;
    }

    No* novo = (No*) malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro de alocacao de memoria!\n");
        return;
    }
    novo->linhas = linha;
    novo->colunas = coluna;
    novo->valor = valor;
    novo->prox = m->head; 
    m->head= novo;

    printf("Veiculo %d estacionado na vaga (%d, %d).\n", valor, linha, coluna);
}

int consultar(matrizEsparsa *m, int linha, int coluna){
	
	if(linha<0 || linha>=m->totalLinhas || coluna<0 || coluna>=m->totalColunas){
		printf("\nErro! Posicao fora dos limites do estacionamento\n");
		return -1;
	}
	
	No* atual=m->head;
	while(atual!=NULL){
		if(atual->linhas==linha && atual->colunas==coluna){
			return atual->valor;
		}
	atual=atual->prox;
	}
	
	return 0;
}

void removerElementos(matrizEsparsa *m, int linha, int coluna){
	
	if(linha<0 || linha>=m->totalLinhas || coluna<0 || coluna>=m->totalColunas){
		printf("\nErro! Posicao fora do estacionamento\n");
		return;
	}
	
	No* atual=m->head;
	No* ant=NULL;
	
	while(atual!=NULL){
		if(atual->linhas==linha && atual->colunas==coluna){
			if(ant==NULL){
				m->head=atual->prox;
			} else {
				ant->prox=atual->prox;
			}
		free(atual);
		printf("\nVaga [%d] [%d] liberada com sucesso!\n", linha, coluna);
		return;
		}
	ant=atual;
	atual=atual->prox;
	}
	
	printf("\nA posicao [%d] [%d] ja esta vazia!\n");
}

void exibirMatriz(matrizEsparsa* m){
	
	printf("\nVIZUALISACAO DO ESTACIONAMENTO: \n");
	for(int i=0; i<m->totalLinhas; i++){
		for(int j=0; j<m->totalColunas; j++){
			int val=consultar(m, i, j);
			printf("%3d ", val);
		}
		printf("\n");
	}
	printf("\n");
	
}

int contarNaoNulos(matrizEsparsa* m){
	
	int cont=0;
	
	No* atual=m->head;
	while(atual!=NULL){
		cont++;
		atual=atual->prox;
	}
	
	return cont;
}

void exibirInterno(matrizEsparsa* m){
	
	printf("\nESTRUTURA INTERNA: \n");
	
	No* atual=m->head;
	if(atual==NULL){
		printf("\nA lista esta vazia\n");
		return;
	}
	
	while(atual!=NULL){
		printf("(%d, %d, %d )", atual->linhas, atual->colunas, atual->valor);
		if(atual->prox!=NULL){
			printf(" -> ");
		}
		atual=atual->prox;
	}
	printf(" -> NULL\n");
}

void destruirMatriz(matrizEsparsa* m){
	
	No* atual=m->head;
	while(atual!=NULL){
		No* aux=atual->prox;
		free(atual);
		atual=aux;
	}
	m->head=NULL;
}

int main(){
	
	matrizEsparsa estacionamento;
	iniciarMatriz(&estacionamento);
	
	printf("\nCADASTRO INICIAL DE VEICULOS: \n");
	inserirMatriz(&estacionamento, 0, 2, 5);
	inserirMatriz(&estacionamento, 1, 4, 8);
	inserirMatriz(&estacionamento, 2, 1, 3);
	inserirMatriz(&estacionamento, 3, 3, 7);
	
	exibirInterno(&estacionamento);
	exibirMatriz(&estacionamento);
	
	printf("\nTotal de vagas ocupadas: %d\n", contarNaoNulos(&estacionamento));
	
	int buscaLinha=1;
	int buscaColuna=4;
	printf("\nConsulta posicao [%d] [%d]: veiculo %d\n", buscaLinha, buscaColuna, consultar(&estacionamento, buscaLinha, buscaColuna));
	
	int linhaVazia=0;
	int colunaVazia=0;
	printf("\nConsulta posicao [%d] [%d]: veiculo %d (0= vaga vazia)\n", linhaVazia, colunaVazia, consultar(&estacionamento, linhaVazia, colunaVazia));
	
	printf("\nREMOVIDO VEICULO: \n");
	removerElementos(&estacionamento, 2, 1);
	
	exibirInterno(&estacionamento);
	printf("\nTotal de vagas pos remocao: %d\n", contarNaoNulos(&estacionamento));
	
	destruirMatriz(&estacionamento);
	
	return 0;
}
