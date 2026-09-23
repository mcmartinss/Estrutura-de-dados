#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Aluno {
    int matricula;
    char nome[50];
    char curso[100];
    int idade;
    float nota;
    
    struct Aluno *ant;
    struct Aluno *prox;
} Aluno;


//Considere a estrutura acima, crie um pequeno sistema que contenha um menu de opção com:
//	1. Inserir: Em ordem alfatética
//	2. Remove: Remove um elemento da lista. Não esqueça de dar o free
//	3. Buscar: Usuário fornece um nome e o sistema retorna os dados do aluno
//	4. Relatório: imprime na tela um relatório dos dados cadastrados

Aluno* cadastro(){
	
	Aluno* novo=(Aluno*) malloc(sizeof(Aluno));
	if(novo==NULL){
		printf("Erro! Falha ao alocar memoria...\n");
		exit(1);
	}
	
	printf("\nCADASTRO DE NOVO ALUNO: \n");
	printf("Matricula: ");
	scanf("%d", &novo->matricula);
	getchar();
	
	printf("Nome: ");
	fgets(novo->nome, sizeof(novo->nome), stdin);
	novo->nome[strcspn(novo->nome, "\n")] = '\0';
	
	printf("Curso: ");
	fgets(novo->curso, sizeof(novo->curso), stdin);
	novo->curso[strcspn(novo->curso, "\n")] = '\0';
	
	printf("Idade: ");
	scanf("%d", &novo->idade);
	
	printf("Nota: ");
	scanf("%f", &novo->nota);
	
	return novo;
}

void inserirNome(Aluno** head){
	
	Aluno* novo=cadastro();
	
	if(*head==NULL){
		*head=novo;
		printf("\nNovo aluno inserido com sucesso!\n");
		return;
	}
	
	if(strcmp(novo->nome, (*head)->nome)<0){
		novo->prox=*head;
		(*head)->ant=novo;
		*head=novo;
		printf("\nAluno inserido com sucesso!\n");
		return;
	}
	
	Aluno* atual=*head;
	while(atual->prox!=NULL && strcmp (atual->prox->nome, novo->nome)<0){
		atual=atual->prox;
	}
	
	novo->prox=atual->prox;
    novo->ant=atual;
    
    if(atual->prox!=NULL){
    	atual->prox->ant=novo;
	}
	
	atual->prox = novo;
    printf("\nAluno inserido com sucesso!\n");
    
}

void removerAluno(Aluno** head){
	
	if(*head==NULL){
		printf("\nA lista esta vazia!\n");
		return;
	}
	
	char nomeBusca[50];
	getchar();
	printf("\nDigite o nome do aluno que deseja remover: ");
	fgets(nomeBusca, sizeof(nomeBusca), stdin);
	nomeBusca[strcspn(nomeBusca, "\n")] = '\0';
	
	Aluno* atual=*head;
	while(atual->prox!=NULL && strcmp(atual->nome, nomeBusca)!=0){
		atual=atual->prox;
	}
	
	if(atual==NULL){
		printf("\nAluno nao encontrado!\n");
		return;
	}
	
	if(atual==*head){
		*head=atual->prox;
	} else {
		atual->ant->prox=atual->prox;
	}
	
	if(atual->prox!=NULL){
		atual->prox->ant=atual->ant;
	}
	
	free(atual);
	printf("\nAluno removido com sucesso!\n");
	
}

void buscarAluno(Aluno* head){
	
	if(head==NULL){
		printf("\nA lista esta vazia!\n");
		return;
	}
	
	char nomeBusca[50];
	getchar();
	printf("Digite o nome do aluno que deseja buscar: ");
	fgets(nomeBusca, sizeof(nomeBusca), stdin);
	nomeBusca[strcspn(nomeBusca, "\n")] = '\0';
	
	Aluno* atual=head;
	while(atual!=NULL){
		if(strcmp(atual->nome, nomeBusca)==0){
			printf("\nAluno encontrado!\n");
			printf("Matricula: %d\n", atual->matricula);
			printf("Nome: %s\n", atual->nome);
			printf("Curso: %s\n", atual->curso);
			printf("Idade: %d\n", atual->idade);
			printf("Nota: %.2f\n", atual->nota);
			return;
		}
	atual=atual->prox;
	}
	
	printf("\nAluno nao encontrado!\n");
}

void relatorio(Aluno* head){
	
	if(head==NULL){
		printf("\nNenhum aluno cadastrado!\n");
		return;
	}
	
	Aluno* atual=head;
	printf("\nRELATORIO DE ALUNOS: ");
	while(atual!=NULL){
		printf("Matricula: %d\n", atual->matricula);
		printf("Nome: %s\n", atual->nome);
		printf("Curso: %s\n", atual->curso);
		printf("Idade: %d\n", atual->idade);
		printf("Nota: %.2f\n", atual->nota);
		atual=atual->prox;
	}
	
	printf("\n");
	
}

void liberarLista(Aluno** head){
	
	Aluno* atual=*head;
	while(atual!=NULL){
		Aluno* proxNo=atual->prox;
		free(atual);
		atual=proxNo;
	}
	
	*head=NULL;
}

int main(){
	
	Aluno* lista=NULL;
	int opcao;
	
	do{
		printf("\nMENU DE OPCOES: \n");
		printf("1 - Inserir aluno(Ordem alfabetica)\n");
		printf("2 - Remover aluno\n");
		printf("3 - Busca por aluno\n");
		printf("4 - Imprimir reatorio\n");
		printf("0 - Sair\n");
		printf("Escolha uma opcao: ");
		scanf("%d", &opcao);
		
		switch (opcao){
			case 1: 
			inserirNome(&lista);
			break;
			
			case 2:
				removerAluno(&lista);
				break;
				
			case 3: 
				buscarAluno(lista);
				break;
				
			case 4:
				relatorio(lista);
				break;
				
			case 0: 
				liberarLista(&lista);
				break;
			
			default:
				printf("Erro! Opcao Invalida!\n");
				break;
		} 
		
	} while(opcao!=0);
	
	return 0;
}
