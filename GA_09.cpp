#include <stdio.h>
#include <windows.h>

int somaDigitos(char* texto)
{
	if (texto[0]=='\0')
		return 0;
	else
		return (texto[0]-48)+somaDigitos(&texto[1]);
}

int main()
{
	SetConsoleOutputCP(1252);
	char texto[10];
	printf("Informe o n�mero desejado: ");
	scanf("%[^\n]s",texto);
	printf("A soma dos d�gitos do n�mero %s � %d\n",texto,somaDigitos(texto));
}

