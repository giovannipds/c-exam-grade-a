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

void orderDates(int* dateA, int* dateB)
{
	if (dateA[2] < dateB[2])
		return;
	if (dateA[1] < dateB[1])
		return;
	if (dateA[0] < dateB[0])
		return;
	int dateTemp[3] = { dateA[0], dateA[1], dateA[2] };
	dateA[0] = dateB[0];
	dateA[1] = dateB[1];
	dateA[2] = dateB[2];
	dateB[0] = dateTemp[0];
	dateB[1] = dateTemp[1];
	dateB[2] = dateTemp[2];
	return;
}

int main()
{
	SetConsoleOutputCP(1252);
	
	int dateA[3], dateB[3];
	readDate(dateA);
	readDate(dateB);
	printf("Data A: %d/%d/%d\n", dateA[0], dateA[1], dateA[2]);
	printf("Data B: %d/%d/%d\n", dateB[0], dateB[1], dateB[2]);
	orderDates(dateA, dateB);
	printf("Data A: %d/%d/%d\n", dateA[0], dateA[1], dateA[2]);
	printf("Data B: %d/%d/%d\n", dateB[0], dateB[1], dateB[2]);
	
	return 1;
}

