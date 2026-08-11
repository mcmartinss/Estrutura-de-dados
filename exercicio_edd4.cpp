#include<stdio.h>
#include<stdlib.h>

void decimalBinario(int num){
	
	if(num==0){
		return;
	}
	
	decimalBinario(num/2);
	printf("%d", num%2);
}

int main(){
	
	int numero;
	
	printf("Digite um numero: ");
	scanf("%d", &numero);
	
	if(numero==0){
		printf("0");
	} else {
		decimalBinario(numero);
	}
	
	printf("\n");
	
return 0;

}
