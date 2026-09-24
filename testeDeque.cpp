#include <stdio.h>

#define MAX 100

typedef struct{
	int dados[MAX];
	int inicio, fim, qtd;
} deque;

void iniciarDeque(deque* d){
	
	d->inicio=0;
	d->fim=-1;
	d->qtd=0;
	
}

int vazio(deque* d){
	return(d->qtd==0);
}

int cheio(deque* d){
	return(d->qtd==MAX);
}

void inserirInicio(deque* d, int x){
	
	if(cheio(d)) return;
	if(vazio(d)){
		d->inicio = 0;
        d->fim = 0; // O fim passa a apontar para o primeiro elemento inserido!
        d->dados[d->inicio] = x;
    } else {
        // Se já houver elementos, recua o início de forma circular
        d->inicio = (d->inicio - 1 + MAX) % MAX;
        d->dados[d->inicio] = x;
    }

    d->qtd++;
}

int removerFim(deque* d){
	
	if(vazio(d)) return -1;
	int x=d->dados[d->fim];
	d->fim=(d->fim-1+MAX)%MAX;
	d->qtd--;
	return x;
	
}

void imprimirDeque(deque *d){
	
	if(vazio(d)){
		printf("\nDeque vazio!\n");
		return;
	}
	
	printf("\nConteudo do deque: \n");
	int y=d->inicio;
	for(int i=0; i<d->qtd; i++){
		printf("%d ", d->dados[y]);
		y=(y+1)%MAX;
	}
	printf("\n");
}

int main(){
	
	deque d;
	
	iniciarDeque(&d);
	
	printf("\nInserindo 10, 20 e 30 no inicio...\n");
	inserirInicio(&d, 10);
	inserirInicio(&d, 20);
	inserirInicio(&d, 30);
	
	imprimirDeque(&d);
	
	int removido=removerFim(&d);
	printf("\nElemento removido do fim: %d\n", removido);
	imprimirDeque(&d);
	
	return 0;
}
