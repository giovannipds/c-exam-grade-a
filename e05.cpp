#include <stdio.h>
#include <windows.h>

int main()
{
	SetConsoleOutputCP(1252);
	
	int d, m, y;
	
	printf("Insira o dia: ");
	scanf("%d", &d);
	
	printf("Insira o mês: ");
	scanf("%d", &m);
	
	printf("Insira o ano: ");
	scanf("%d", &y);
	
	printf("Dia: %d \nMês: %d \nAno: %d", d, m, y);
	
	return 1;
}

