#include<stdio.h>
#include<stdlib.h>

int potencia(int base, int exp){
	
	if(exp==0){
		return 1;
	}
	
	return base*potencia(base, exp - 1);
}

int main(){
	
	int base, expoente;
	
	printf("Digite a base: ");
	scanf("%d", &base);
	printf("Digite o expoente: ");
	scanf("%d", &expoente);
	
	int resultado=potencia(base, expoente);
	
	printf("Resultado de %d elevado a %d = %d", base, expoente, resultado);
	
return 0;

}
