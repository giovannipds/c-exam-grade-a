#include <stdio.h>
#include <windows.h>

int sum(char* strPointer);

int main()
{
	SetConsoleOutputCP(1252);
	
	char str[8] = "2030678";
	
	printf("A soma dos dígitos é: ", sum(str));
	
	return 1;
}

int sum(char* strPointer)
{
	printf("%s\n\n", strPointer);
	return 0;
}

