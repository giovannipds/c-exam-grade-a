#include <stdio.h>
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
	
	printf("\nDia: %d \nMês: %d \nAno: %d \n\n", d, m, y);
	
	printf("Data %s.", validDate(d, m, y) ? "válida" : "inválida");
	
	return 1;
}

