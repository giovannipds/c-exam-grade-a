#include <stdio.h>
#include <windows.h>

int sum(char* strPointer);

int main()
{
	SetConsoleOutputCP(1252);
	
	char str[8] = "2030678";
	
	printf("A soma dos dígitos é: %d", sum(str));
	
	return 1;
}

int sum(char* strPointer)
{
	char c = *strPointer;
	int n = *strPointer - 48;
	
//	printf("%c e %d\n", c, n);

	return c != '\0' ? n + sum(++strPointer) : 0;
}

