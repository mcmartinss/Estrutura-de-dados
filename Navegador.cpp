#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Pagina{
	
	char nomePag[50];
	
	struct Pagina* prox;
	struct Pagina* ant;
	
} Pagina;

Pagina* head=NULL;
Pagina* atual=NULL;

void visitarPagina(char* URL){
	
	if(atual!=NULL && atual->prox!=NULL){
		Pagina *aux=atual->prox;
		while(aux!=NULL){
			Pagina *temp=aux->prox;
			free(aux);
			aux=temp;
		}
	atual->prox=NULL;
	}
	
	Pagina* novaPag=(Pagina*) malloc(sizeof(Pagina));
	if(novaPag==NULL){
		printf("\nErro! Falha ao alocar memoria...\n");
		exit(1);
	}
	
	strcpy(novaPag->nomePag, URL);
	novaPag->prox=NULL;
	
	if(head==NULL){
		novaPag->ant=NULL;
		head=novaPag;
		atual=novaPag;
	} else {
		atual->prox=novaPag;
		novaPag->ant=atual;
		atual=novaPag;
	}
	
	printf("\nVisitando: %s\n", atual->nomePag);
}
void voltar(){
	
	if(atual!=NULL && atual->ant!=NULL){
		atual=atual->ant;
		printf("\nVisitando: %s\n", atual->nomePag);
	} else {
		printf("\nErro! Voce chegou ao fim do historico\n");
	}
}

void avancar(){
	
	if(atual!=NULL && atual->prox!=NULL){
		atual=atual->prox;
		printf("\nVisitando: %s\n", atual->nomePag);
	} else{
		printf("\nErro! Esta eh a ultima pagina do historico\n");
	}
}

void mostrarHistorico(){
	
	if(head==NULL){
		printf("\nErro! O historico de navegacao esta vazio!\n");
		return;
	}
	
	Pagina* aux=head;
	printf("\nHISTORICO DE NAVEGACAO: \n");
	while(aux!=NULL){
		if(aux==atual){
			printf("Atual: [%s]", aux->nomePag);
		} else {
			printf("[%s]", aux->nomePag);
		}
		
		if(aux->prox!=NULL){
			printf(" <-> ");
		}
	aux=aux->prox;
	}
	
	printf("\n");
}

int main(){
	
	int opcao;
	char nomePag[100];
	
	do{
		printf("\nMENU DE OPCOES: \n");
		printf("1 - Visitar pagina\n");
		printf("2 - Voltar\n");
		printf("3 - Avancar\n");
		printf("4 - Mostrar Historico\n");
		printf("0 -  Sair\n");
		printf("Digite a opcao: ");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1: 
			printf("\nDigite o nome da pagina(URL): ");
			scanf("%s", nomePag);
			visitarPagina(nomePag);
			break;
			
			case 2:
				voltar();
				break;
				
			case 3: 
				avancar();
				break;
				
			case 4: 
				mostrarHistorico();
				break;
				
			case 0:
				printf("Saindo...");
				break;
				
			default:
				printf("\nErro! Opcao invalida!\n");
		}
	} while(opcao!=0);
	
	return 0;
}
