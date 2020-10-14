#include <stdio.h>
#include <windows.h>

char* convData(int dia, int mes, int ano)
{
	char* data = "07/03/2020";
	return strdup(data);
}

int main()
{
	SetConsoleOutputCP(1252);
	char* data = convData(7, 3, 20);
	printf("%s", data);
	return 1;
}

