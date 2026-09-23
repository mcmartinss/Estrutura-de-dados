#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Musica{
	
	char titulo[100];
	char artista[50];
	
	struct Musica* prox;
	struct Musica* ant;
	
} Musica;

Musica* head=NULL;
Musica* atual=NULL;

void adicionarMusica(char *titulo, char* artista){
	
	Musica* nova=(Musica*) malloc(sizeof(Musica));
	if(nova==NULL){
		printf("\nErro! Falha ao alocar memoria!\n");
		return;
	}
	
	strcpy(nova->titulo, titulo);
	strcpy(nova->artista, artista);
	
	nova->prox=NULL;
	nova->ant=NULL;
	
	if(head==NULL){
		head=nova;
		atual=nova;
	} else {
		Musica* aux=head;
		while(aux->prox!=NULL){
			aux=aux->prox;
		}
	aux->prox=nova;
	nova->ant=aux;
	nova->prox=NULL;
	}
	
	printf("\nMusica '%s' de '%s' adicionada com sucesso!\n", titulo, artista);
}

void removerMusica(char* titulo){
	
	if(head==NULL){
		printf("\nA playlista esta vazia\n");
		return;
	}
	
	Musica* aux=head;
	while(aux!=NULL && strcasecmp(aux->titulo, titulo)!=0){
		aux=aux->prox;
	}
	
	if(aux==NULL){
		printf("\nMusica nao encontrada\n");
		return;
	}
	
	if(aux==atual){
		if(atual->prox!=NULL){
			atual=atual->prox;
		} else {
			atual=atual->ant;
		}
	}
	
	if(aux==head){
		head=aux->prox;
	}
	
	if(aux->ant!=NULL){
		aux->ant->prox=aux->prox;
	}
	
	if(aux->prox!=NULL){
		aux->prox->ant=aux->ant;
	}
	
	free(aux);
	printf("\nMusica '%s' removida com sucesso!\n", titulo);
	
}

void proxima(){
	
	if(atual==NULL){
		printf("\Nenhuma musica na playlist\n");
		return;
	}
	
	if(atual->prox!=NULL){
		atual=atual->prox;
		printf("Tocando: '%s' - '%s'\n", atual->titulo, atual->artista);
	} else {
		printf("\nVoce ja esta na ultima musica!\n");
	}	
}

void anterior(){
	
	if(atual==NULL){
		printf("\nNenhuma musica na playlist\n");
		return;
	}
	
	if(atual->ant!=NULL){
		atual=atual->ant;
		printf("Tocando: '%s' - '%s'\n", atual->titulo, atual->artista);
	} else {
		printf("\nVoce ja esta na primeira musica\n");
	}
}

void exibirPlaylist(){
	
	if(head==NULL){
		printf("\nA playlist esta vazia\n");
		return;
	}
	
	printf("\nPLAYLIST: \n");
	Musica* aux=head;
	
	while(aux!=NULL){
		if(aux==atual){
			printf("\nTocando agora: %s de %s\n", aux->titulo, aux->artista);
		} else {
			printf("\n%s de %s\n", aux->titulo, aux->artista);
		}
		aux=aux->prox;
	}
}

int main(){
	
	int opcao;
	char titulo[100], artista[50];
	
	do{
		printf("\nMENU DE OPCOES: \n");
		printf("1 - Adicionar musica\n");
		printf("2 - Remover musica\n");
		printf("3 - Proxima\n");
		printf("4 - Anterior\n");
		printf("5 -  Exibir playlist\n");
		printf("0  - Sair\n");
		printf("Digite a opcao: ");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1:
				getchar();
				printf("\nDigite o nome da musica: ");
				fgets(titulo, sizeof(titulo), stdin);
				titulo[strcspn(titulo, "\n")] = 0;
				
				printf("Digite o nome do artista: ");
				fgets(artista, sizeof(artista), stdin);
				artista[strcspn(artista, "\n")] = 0;
				adicionarMusica(titulo, artista);
				break;
				
			case 2:
				getchar();
				printf("Digite o nome da musica a ser removida: ");
				fgets(titulo, sizeof(titulo), stdin);
 				titulo[strcspn(titulo, "\n")] = 0;
				removerMusica(titulo);
				break;
				
			case 3:
				proxima();
				break;
			
			case 4:
				anterior();
				break;
				
			case 5:
				exibirPlaylist();
				
			case 0:
				printf("\nEncerrando...\n");
				break;
				
			default:
				printf("Erro! Opcao invalida\n");		
		}
	} while(opcao!=0);
	
	return 0;
}
