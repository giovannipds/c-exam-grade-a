#include <stdio.h>
#include <windows.h>

int main()
{
	SetConsoleOutputCP(1252);
	int num, salto;

	num = 0;
	salto = 1;
	while (num<=496)
	{
		printf("%d\n",num);
		num += salto++;
	}
}

