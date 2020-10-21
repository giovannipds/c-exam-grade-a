#include <stdio.h>
#include <windows.h>

int fatorial(int n)
{
	if (n==0)
		return 1;
	else
		return n*fatorial(n-1);
}

double neperiano(int N)
{
	if (N==0)
		return 1/fatorial(N);
	else
	    return 1/(float)fatorial(N)+neperiano(N-1);
}

int main()
{
	SetConsoleOutputCP(1252);
	int N;
	printf("Informe o número de aproximações para o cálculo do número neperiano e: ");
	scanf("%d",&N);
	printf("O valor aproximado do número neperiano n é %7.6f\n",neperiano(N));
}

