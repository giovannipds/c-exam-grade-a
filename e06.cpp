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

bool isLeapYear(int year)
{
	return year % 4 == 0 && ! (year % 100 == 0 && ! (year % 400 == 0));
}

int* getMonthDaysArray(int year)
{
	int monthDays[12] = {
		31, isLeapYear(year) ? 29 : 28, 31, 30, 31, 30,
		31, 31, 30, 31, 30, 31
	};
	return monthDays;
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

int daysDiff(int* minorDate, int* majorDate)
{
	int daysA = getDayOfTheYear(minorDate[0], minorDate[1], minorDate[2]);
	int daysB = getDayOfTheYear(majorDate[0], majorDate[1], majorDate[2]);
	int diff = daysB - daysA;
	if (minorDate[2] != majorDate[2]) {
		for (int i = minorDate[2]; i < majorDate[2]; i++) {
			diff += isLeapYear(i) ? 366 : 365;
		}
	}
	return diff;
}

int main()
{
	SetConsoleOutputCP(1252);
	int dateA[3], dateB[3], diff;
	readDate(dateA);
	readDate(dateB);
	orderDates(dateA, dateB);
	diff = daysDiff(dateA, dateB);
	printf("Entre as datas %d/%d/%d e %d/%d/%d há %d dia%s de diferença.", 
		dateA[0], dateA[1], dateA[2],
		dateB[0], dateB[1], dateB[2],
		diff, diff != 1 ? "s" : "");
	return 1;
}

