#include <math.h>
#include <stdio.h>
#include <windows.h>

int main()
{
	SetConsoleOutputCP(1252);
	
	float p1, p2, p3, p4, oldA, a, vp;
	
	printf("Digite o pre�o do produto no estabelecimento 1: ");
	scanf("%f", &p1);
	
	printf("Digite o pre�o no estabelecimento 2: ");
	scanf("%f", &p2);
	
	printf("Digite o pre�o no estabelecimento 3: ");
	scanf("%f", &p3);
	
	printf("Digite o pre�o no estabelecimento 4: ");
	scanf("%f", &p4);
	
	a = (p1 + p2 + p3 + p4) / 4;
	
	printf("Digite agora o valor m�dio do produto na semana passada: ");
	scanf("%f", &oldA);
	
	printf("\nO valor m�dio da semana anterior era: R$%.2f", oldA);
	printf("\nO valor m�dio da semana atual �: R$%.2f\n", a);
	
	vp = fabs((a / oldA - 1) * 100);
	
	if (oldA < a) {
		printf("Houve infla��o de: %.1f%%", vp);
	} else if (oldA > a) {
		printf("Houve defla��o de: %.1f%%", vp);
	} else {
		printf("Houve estabilidade de pre�os.");
	}
	
	return 1;
}

