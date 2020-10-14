#include <stdio.h>
#include <windows.h>

const char *months[12] = {
	"Janeiro", "Fevereiro", "Mar�o", "Abril", "Maio", "Junho",
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

bool validDay(int day, int month)
{
	const int monthDays[12] = {
		31, 28, 31, 30, 31, 30,
		31, 31, 30, 31, 30, 31
	};
	return day >= 1 && day <= monthDays[month - 1];
}

bool validDate(int day, int month, int year)
{
	return validYear(year) && validMonth(month) && validDay(day, month);
}

int main()
{
	SetConsoleOutputCP(1252);
	
	int d, m, y;
	
	printf("Insira o dia: ");
	scanf("%d", &d);
	
	printf("Insira o m�s: ");
	scanf("%d", &m);
	
	printf("Insira o ano: ");
	scanf("%d", &y);
	
	printf("\nDia: %d \nM�s: %d \nAno: %d \n\n", d, m, y);
	
	printf("Data %s.", validDate(d, m, y) ? "v�lida" : "inv�lida");
	
	return 1;
}

