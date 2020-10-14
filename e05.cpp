#include <stdio.h>
#include <string.h>
#include <windows.h>

const char *months[12] = {
	"Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho",
	"Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"
};

bool validYear(int year)
{
	return year >= 1900 && year <= 2100;
}

bool validMonth(int month)
{
	return month >= 1 && month <= 12;
}

bool isLeapYear(int year)
{
	return year % 4 == 0 && ! (year % 100 == 0 && ! (year % 400 == 0));
}

bool validDay(int day, int month, int year)
{
	const int monthDays[12] = {
		31, isLeapYear(year) ? 29 : 28, 31, 30, 31, 30,
		31, 31, 30, 31, 30, 31
	};
	return day >= 1 && day <= monthDays[month - 1];
}

bool validDate(int day, int month, int year)
{
	return validYear(year) && validMonth(month) && validDay(day, month, year);
}

char* longDate(int day, int month, int year)
{
	char date[80];
	itoa(day, date, 10);
	strcat(date, " de ");
	strcat(date, months[month - 1]);
	strcat(date, " de ");
//	strcat(date, itoa(year, date, 10));
//	strcpy(date, );
	//%d de %s de %d. //d, months[m - 1], y
	return strdup(date); //month + year;
}

int yearDate(int day, int month, int year)
{
	return 0;
}

int main()
{
	SetConsoleOutputCP(1252);
	
	int d, m, y;
	
	printf("Insira o dia: ");
	scanf("%d", &d);
	
	printf("Insira o mês: ");
	scanf("%d", &m);
	
	printf("Insira o ano: ");
	scanf("%d", &y);
	
//	printf("\nDia: %d \nMês: %d \nAno: %d \n\n", d, m, y);
	
	printf("a) Data %s.\n", validDate(d, m, y) ? "válida" : "inválida");
	
	printf("b) Data por extenso: %s.\n", longDate(d, m, y));
	
	printf("c) Dia do ano: %d", yearDate(d, m, y));
	
	return 1;
}

