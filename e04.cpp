#include <stdio.h>
#include <windows.h>

int main()
{
	SetConsoleOutputCP(1252);
	
	float p1, p2, p3, p4, a;
	
	printf("Digite o pre�o do produto no estabelecimento 1: ");
	scanf("%f", &p1);
	
	printf("Digite o pre�o no estabelecimento 2: ");
	scanf("%f", &p2);
	
	printf("Digite o pre�o no estabelecimento 3: ");
	scanf("%f", &p3);
	
	printf("Digite o pre�o no estabelecimento 4: ");
	scanf("%f", &p4);
	
	a = (p1 + p2 + p3 + p4) / 4;
	printf("\nO valor m�dio do produto �: R$%.2f", a);
	
	return 1;
}

