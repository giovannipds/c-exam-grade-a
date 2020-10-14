#include <stdio.h>
#include <windows.h>

void readDate(int* pointer)
{	
	printf("Insira o dia: ");
	scanf("%d", &pointer[0]);
	
	printf("Insira o mês: ");
	scanf("%d", &pointer[1]);
	
	printf("Insira o ano: ");
	scanf("%d", &pointer[2]);
	
	printf("\n");
	return;
}

int main()
{
	SetConsoleOutputCP(1252);
	
	int date1[3], date2[3];
	readDate(date1);
	readDate(date2);
	printf("%d/%d/%d\n", date1[0], date1[1], date1[2]);
	printf("%d/%d/%d\n", date2[0], date2[1], date2[2]);
	
	return 1;
}

