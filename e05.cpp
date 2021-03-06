#include <stdio.h>
#include <string.h>
#include <windows.h>

const char *months[12] = {
	"Janeiro", "Fevereiro", "Mar�o", "Abril", "Maio", "Junho",
	"Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"
};

bool validYear(int year);
bool validMonth(int month);
bool isLeapYear(int year);
int* getMonthDaysArray(int year);
bool validDay(int day, int month, int year);
bool validateDate(int day, int month, int year);
char* longDate(int day, int month, int year);
int getDayOfTheYear(int day, int month, int year);

int main()
{
	SetConsoleOutputCP(1252);
	
	int d, m, y;
	bool validDate;
	
	printf("Insira o dia: ");
	scanf("%d", &d);
	
	printf("Insira o m�s: ");
	scanf("%d", &m);
	
	printf("Insira o ano: ");
	scanf("%d", &y);
	
//	printf("\nDia: %d \nM�s: %d \nAno: %d \n\n", d, m, y);
	
	validDate = validateDate(d, m, y);
	printf("\na) Data %s.\n", validDate ? "v�lida" : "inv�lida");
	
	if (!validDate)
		return 0;
		
	printf("b) Data por extenso: %s.\n", longDate(d, m, y));
	
	printf("c) Dia do ano: %d.", getDayOfTheYear(d, m, y));
	
	return 1;
}

bool validateDate(int day, int month, int year)
{
	return validYear(year) && validMonth(month) && validDay(day, month, year);
}

bool validYear(int year)
{
	return year >= 1900 && year <= 2100;
}

bool validMonth(int month)
{
	return month >= 1 && month <= 12;
}

bool validDay(int day, int month, int year)
{
	int* monthDays = getMonthDaysArray(year);
	return day >= 1 && day <= monthDays[month - 1];
}

int* getMonthDaysArray(int year)
{
	int monthDays[12] = {
		31, isLeapYear(year) ? 29 : 28, 31, 30, 31, 30,
		31, 31, 30, 31, 30, 31
	};
	return monthDays;
}

bool isLeapYear(int year)
{
	return year % 4 == 0 && ! (year % 100 == 0 && ! (year % 400 == 0));
}

char* longDate(int day, int month, int year)
{
	char date[80];
	char strYear[5];
	itoa(day, date, 10);
	strcat(date, " de ");
	strcat(date, months[month - 1]);
	strcat(date, " de ");
	itoa(year, strYear, 10);
	strcat(date, strYear);
	return strdup(date);
}

int getDayOfTheYear(int day, int month, int year)
{
	int* monthDays = getMonthDaysArray(year);
	int dayOfTheYear = day;
	for (int i = 0; i < month - 1; i++) {
		dayOfTheYear += monthDays[i];
	}
	return dayOfTheYear;
}

