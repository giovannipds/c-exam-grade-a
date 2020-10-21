#include <stdio.h>
#include <windows.h>
#include <math.h>

int main()
{
	SetConsoleOutputCP(1252);
	float c1, c2, h, area, perimetro;

    printf("Informe o tamanho do primeiro cateto: ");
	scanf("%f", &c1);
    printf("Informe o tamanho do segundo cateto: ");
	scanf("%f", &c2);
	
	h = sqrt(pow(c1,2)+pow(c2,2));
	area = (c1*c2)/2;
	perimetro = c1+c2+h;

	printf("O tamanho da hipotenusa � %5.2f\n",h);
	printf("A �rea do tri�ngulo � %5.2f\n",area);
	printf("O per�metro do tri�ngulo � %5.2f\n",perimetro);
}

