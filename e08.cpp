#include <stdio.h>
#include <windows.h>

int fatorial(int n);
float numeroNeperiano(int n);

int main()
{
	SetConsoleOutputCP(1252);
	
	int n;
	float e;
	
	printf("Insira o valor de N: ");
	scanf("%d", &n);
	
	e = numeroNeperiano(n);
	printf("Neperiano / valor aproximado de: %f\n", e);
	
	return 1;
}

int fatorial(int n)
{
	return n <= 1 ? 1 : n * fatorial(n - 1);
}

float numeroNeperiano(int n)
{
	return (float)1 / fatorial(n) + (n > 0 ? numeroNeperiano(n - 1) : 0);
}

