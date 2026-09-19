#include<stdio.h>
#include<stdlib.h>

typedef struct{
	char nome[50];
	int idade; 
	float nota;
} Aluno;

int main(){
	
	int n;
	Aluno *turma=NULL;
	
	printf("Insira a quantidade de alunos a cadastrar: ");
	scanf("%i", &n);
	
	turma=(Aluno *) calloc(n, sizeof(Aluno));
	if(turma==NULL){
		printf("Erro! Falha ao alocar memoria!\n");
		return 1;
	} 
	
	for(int i=0; i<n; i++){
		int c;
		while ((c = getchar()) != '\n' && c != EOF);
	
		printf("\n");	
		printf("Nome do aluno: ");
		fgets(turma[i].nome, 50, stdin);
		printf("Idade do aluno: ");
		scanf("%i", &turma[i].idade);
		printf("Nota: ");
		scanf("%f", &turma[i].nota);
	}
	
	int maior=0;
	for(int i=0; i<n; i++){
		if(turma[i].nota>turma[maior].nota){
			maior=i;
		}
	}
	
	printf("\n");
	printf("Aluno(a) com a maior nota: \n");
	printf("Nome do aluno: %s", turma[maior].nome);
	printf("Nota: %.2f", turma[maior].nota);
	
	
	free(turma);
	turma=NULL;
	
	return 0;
}
