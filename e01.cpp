#include <math.h>
#include <stdio.h>
#include <windows.h>

int main()
{
	SetConsoleOutputCP(1252);
	
	float c1, c2, h, a, p;
	
	printf("Informe o primeiro cateto de um tri�ngulo ret�ngulo (em cm): ");
	scanf("%f", &c1);
	
	printf("Informe o segundo (em cm): ");
	scanf("%f", &c2);
	
	h = sqrt(pow(c1, 2) + pow(c2, 2));
	printf("\na) O valor da hipotenusa � %.1fcm\n", h);
	
	a = (c1 * c2) / 2;
	printf("b) A �rea do tri�ngulo � %.1fcm\n", a);
	
	p = h + c1 + c2;
	printf("c) O per�metro do tri�ngulo � %.1fcm\n", p);
	
	return 1;
}

