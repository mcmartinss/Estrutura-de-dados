#include<stdio.h>
#include<stdlib.h>

void decimalBinario(int numero){
	
	if(numero==0){
		return;
	}
	
	decimalBinario(numero/2);
	
	printf("Numero = %d\n", numero%2);
}

int main(){
	
	int num;
	
	printf("Insira um numero: ");
	scanf("%i", &num);
	
	if(num==0){
		printf("\0 ");
	} else { 
		decimalBinario(num);
	}
	printf("\n");
	
	return 0;
}
