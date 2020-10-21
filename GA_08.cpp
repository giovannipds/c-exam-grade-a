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
	printf("Informe o n�mero de aproxima��es para o c�lculo do n�mero neperiano e: ");
	scanf("%d",&N);
	printf("O valor aproximado do n�mero neperiano n � %7.6f\n",neperiano(N));
}

