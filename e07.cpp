#include <stdio.h>
#include <windows.h>

char* convData(int dia, int mes, int ano);
void extrair(char* data, int* dia, int* mes, int* ano);
bool validateDate(int day, int month, int year);
bool validYear(int year);
bool validMonth(int month);
bool validDay(int day, int month, int year);
bool isLeapYear(int year);
int* getMonthDaysArray(int year);

void imprimeDataSeguinte(int dia, int mes, int ano)
{
	int* monthDays = getMonthDaysArray(ano);
	if (dia + 1 > monthDays[mes - 1]) {
		dia = 1;
		if (mes + 1 > 12) {
			mes = 1;
			++ano;
		} else {
			++mes;
		}
	} else {
		++dia;
	}
	printf("Próximo dia: %s", convData(dia, mes, ano));
	return;
}

int main()
{
	SetConsoleOutputCP(1252);
	
	char d[11];
	int dia, mes, ano;
	
//	char* data = convData(7, 3, 20);
//	printf("%s\n", data);

//	char* data2 = convData(13, 9, 2018);
//	printf("%s\n", data2);

//	extrair(data, &dia, &mes, &ano);
//	printf("Data %d/%d/%d", dia, mes, ano);
	
	printf("Digite uma data (DD/MM/YYYY): ");
	scanf("%49[^\n]s", &d);
	printf("\n");
	
	extrair(d, &dia, &mes, &ano);
	
	if (validateDate(dia, mes, ano))
		imprimeDataSeguinte(dia, mes, ano);
	else
		printf("Data inválida");
	
	return 1;
}

char* convData(int dia, int mes, int ano)
{
	char data[11];
	if (ano < 100) {
		ano += ano >= 50 ? 1900 : 2000;
	}
	for (int i = 0; i <= 10; i++) {
		char c;
		if (i == 0) {
			c = dia / 10 + '0';
		} else if (i == 1) {
			c = dia % 10 + '0';
		} else if (i == 2 || i == 5) {
			c = '/';
		} else if (i == 3) {
			c = mes / 10 + '0';
		} else if (i == 4) {
			c = mes % 10 + '0';
		} else if (i == 6) {
			c = ano / 1000 + '0';
		} else if (i == 7) {
			c = ano % 1000 / 100 + '0';
		} else if (i == 8) {
			c = ano % 100 / 10 + '0';
		} else if (i == 9) {
			c = ano % 10 + '0';
		} else {
			c = '\0';
		}
//		printf("char %c\n", c);
		data[i] = c;
	}
	return strdup(data);
}

void extrair(char* data, int* dia, int* mes, int* ano)
{
	char* diaStr[3];
	char* mesStr[3];
	char* anoStr[5];
	for (int i = 0; data[i] != '\0'; i++) {
		if (i == 0 || i == 1) {
			diaStr[i] = &data[i];
		} else if (i == 3 || i == 4) {
			mesStr[i - 3] = &data[i];
		} else if (i >= 6 && i <= 9) {
			anoStr[i - 6] = &data[i];
		}
//		printf("char %c\n", data[i]);
	}
	*dia = atoi(*diaStr);
	*mes = atoi(*mesStr);
	*ano = atoi(*anoStr);
	return;
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
