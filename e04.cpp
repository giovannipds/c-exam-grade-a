#include <math.h>
#include <stdio.h>
#include <windows.h>

int main()
{
	SetConsoleOutputCP(1252);
	
	float p1, p2, p3, p4, oldA, a, vp;
	
	printf("Digite o preço do produto no estabelecimento 1: ");
	scanf("%f", &p1);
	
	printf("Digite o preço no estabelecimento 2: ");
	scanf("%f", &p2);
	
	printf("Digite o preço no estabelecimento 3: ");
	scanf("%f", &p3);
	
	printf("Digite o preço no estabelecimento 4: ");
	scanf("%f", &p4);
	
	a = (p1 + p2 + p3 + p4) / 4;
	
	printf("Digite agora o valor médio do produto na semana passada: ");
	scanf("%f", &oldA);
	
	printf("\nO valor médio da semana anterior era: R$%.2f", oldA);
	printf("\nO valor médio da semana atual é: R$%.2f\n", a);
	
	vp = fabs((a / oldA - 1) * 100);
	
	if (oldA < a) {
		printf("Houve inflação de: %.1f%%", vp);
	} else if (oldA > a) {
		printf("Houve deflação de: %.1f%%", vp);
	} else {
		printf("Houve estabilidade de preços.");
	}
	
	return 1;
}

