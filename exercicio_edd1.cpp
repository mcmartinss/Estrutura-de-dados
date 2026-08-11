#include<stdio.h>
#include<stdlib.h>

int somaVetor(int vetor[], int tamanho){
	
	if(tamanho<=0){
		return 0;
	}
	
	return vetor[tamanho - 1]+somaVetor(vetor, tamanho - 1);
}

int main(){
	
	int n;
	
	printf("Digite o tamanho do vetor: ");
	scanf("%d", &n);
	
	int vetor[n];
	
	printf("Digite os elementos do vetor: \n");
	for(int i=0; i<n; i++){
		scanf("%d", &vetor[i]);
	}
	
	int resultado=somaVetor(vetor, n);
	
	printf("\nSaida: \n");
	printf("soma=%d\n", resultado);
	
return 0;

}
