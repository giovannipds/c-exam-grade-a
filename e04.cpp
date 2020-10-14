#include <stdio.h>
#include <windows.h>

int main()
{
	SetConsoleOutputCP(1252);
	
	float p1, p2, p3, p4;
	
	printf("Digite o preço do produto no estabelecimento 1: ");
	scanf("%f", &p1);
	
	printf("Digite o preço no estabelecimento 2: ");
	scanf("%f", &p2);
	
	printf("Digite o preço no estabelecimento 3: ");
	scanf("%f", &p3);
	
	printf("Digite o preço no estabelecimento 4: ");
	scanf("%f", &p4);
	
	return 1;
}

