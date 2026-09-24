#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct No{
	int numeroSenha;
	char nome[100];
	char tipoAtendimento[20];
	struct No* prox;
	struct No* ant;
} No;

typedef struct{
	No* inicio;
	No* fim;
	No* atual;
} Clinica;

void inicializarClinica(Clinica* c){
	c->inicio=NULL;
	c->fim=NULL;
	c->atual=NULL;
}

void cadastrarSenha(Clinica* c, int num, char *nome, char *tipo){
	
	No* novo=(No*) malloc(sizeof(No));
	if(novo==NULL){
		printf("\nErro ao alocar memoria!\n");
		return;
	}
	
	novo->numeroSenha=num;
	strcpy(novo->nome, nome);
	strcpy(novo->tipoAtendimento, tipo);
	novo->ant=NULL;
	novo->prox=NULL;
	
	if(c->inicio==NULL){
		c->inicio=novo;
		c->fim=novo;
	} else if (strcmp(tipo, "prioritario")==0){
		novo->prox=c->inicio;
		c->inicio->ant=novo;
		c->inicio=novo;
	} else {
		novo->ant=c->fim;
		c->fim->prox=novo;
		c->fim=novo;
	}
	
	printf("\nSenha [%d] cadastrada com sucesso (%s)!\n", num, tipo);
}

void proxima(Clinica* c){
	
	if(c->inicio==NULL){
		printf("\nA lista esta vazia!\n");
		return;
	}
	
	if(c->atual==NULL){
		c->atual=c->inicio;
	} else if (c->atual->prox!=NULL){
		c->atual=c->atual->prox;
	} else {
		printf("\nTodos os pacientes ja foram chamados!\n");
		return;
	}
	
	printf("\nCHAMANDO: \n");
	printf("Senha: %d, Paciente: %s (%s)\n", c->atual->numeroSenha, c->atual->nome, c->atual->tipoAtendimento);
}

void consultarSenha(Clinica *c){
	
	if(c->atual==NULL){
		printf("\nNenhum paciente esta sendo atendido no momento!\n");
		return;
	} else {
		printf("\nSenha em atendimento atual: %d - Paciente: %s (%s)\n", c->atual->numeroSenha, c->atual->nome, c->atual->tipoAtendimento);
	}
}

void consultarSenhaAnterior(Clinica* c){
	
	if(c->atual==NULL || c->atual->ant == NULL){
		printf("\nNao ha senha anterior!\n");
		return;
	} else {
		No* ant=c->atual->ant;
		printf("\nSenha anterior: %d - Paciente: %s (%s)\n", ant->numeroSenha, ant->nome, ant->tipoAtendimento);
	}
	
}

void consultarProx(Clinica *c){
	
	if(c->inicio==NULL){
		printf("\nNao ha proxima senha!\n");
		return;
	}
	
	if(c->atual==NULL){
		printf("\nProxima senha: %d - Paciente: %s (%s)\n", c->inicio->numeroSenha, c->inicio->nome, c->inicio->tipoAtendimento);
	} else if(c->atual->prox==NULL){
		printf("\nNao ha mais senhas na fila\n");
	} else {
		No* prox=c->atual->prox;
		printf("\nProxima senha: %d - Paciente: %s (%s)\n", prox->numeroSenha, prox->nome, prox->tipoAtendimento);
	}
}

void percorrerOrdem(Clinica *c){

	if(c->inicio==NULL){
		printf("\nNao ha proxima senha!\n");
		return;
	}
	
	printf("\nSENHAS EM ORDEM: \n");
	No* aux=c->inicio;
	while(aux!=NULL){
		printf("\n%d - Paciente %s (%s)\n", aux->numeroSenha, aux->nome, aux->tipoAtendimento);
		aux=aux->prox;
	}
}

void percorrerOrdemInversa(Clinica *c){

	if(c->inicio==NULL){
		printf("\nNao ha proxima senha!\n");
		return;
	}
	
	printf("\nSENHAS EM ORDEM INVERSA: \n");
	No* aux=c->fim;
	while(aux!=NULL){
		printf("\n%d - Paciente %s (%s)\n", aux->numeroSenha, aux->nome, aux->tipoAtendimento);
		aux=aux->ant;
	}
}

int main(){
	
	Clinica clinica;
	inicializarClinica(&clinica);
	
	cadastrarSenha(&clinica, 101, "Carlos", "comum");
	cadastrarSenha(&clinica, 102, "Teresa", "prioritario");
	cadastrarSenha(&clinica, 103, "Pedro", "prioritario");
	cadastrarSenha(&clinica, 104, "Livia", "comum");
	
	percorrerOrdem(&clinica);
	percorrerOrdemInversa(&clinica);
	
	proxima(&clinica);
	proxima(&clinica);
	
	printf("\nCONSULTAS DO ESTADO ATUAL: \n");
	consultarSenha(&clinica);
	consultarSenhaAnterior(&clinica);
	consultarProx(&clinica);
	
	return 0;
}
