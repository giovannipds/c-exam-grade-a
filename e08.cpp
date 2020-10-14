#include <math.h>
#include <stdio.h>
#include <windows.h>

int fatorial(int n)
{
	return n <= 1 ? 1 : n * fatorial(n - 1);
}

int main()
{
	SetConsoleOutputCP(1252);
	
	int i = 5;
	
//	printf("Digite o preço do produto no estabelecimento 1: ");
//	scanf("%f", &p1);

	printf("Fatorial de %d: %d", i, fatorial(i));
	
	return 1;
}

