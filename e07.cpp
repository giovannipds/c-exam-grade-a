#include <stdio.h>
#include <windows.h>

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

int main()
{
	SetConsoleOutputCP(1252);
	char* data = convData(7, 3, 20);
	printf("%s\n", data);
//	char* data2 = convData(13, 9, 2018);
//	printf("%s\n", data2);
	int dia = 22, mes, ano;
	extrair(data, &dia, &mes, &ano);
	printf("Data %d/%d/%d", dia, mes, ano);
	return 1;
}

