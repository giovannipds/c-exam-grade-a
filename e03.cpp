#include <stdio.h>
#include <windows.h>

int main()
{
	SetConsoleOutputCP(1252);
	
	int passeio = 0, offRoad = 0;
	float pLitros = 0, oLitros = 0, precoRealGalao = 0;
	
	printf("Quantos ve�culos de passeio tem na empresa? ");
	scanf("%d", &passeio);
	
	printf("Quantos ve�culos off-road? ");
	scanf("%d", &offRoad);
	
	printf("Quantos litros cabem num tanque de ve�culo de passeio? ");
	scanf("%f", &pLitros);
	
	printf("Quantos litros cabem num off-road? ");
	scanf("%f", &oLitros);
	
	printf("Quanto custa o gal�o americano de gasolina em Reais (R$)? ");
	scanf("%f", &precoRealGalao);
	
	printf("\nPasseio: %d\nOff-road: %d\nLitros Passeio: %.1fl\nLitros Off-road: %.1fl\nPre�o R$/gal�o: R$%.2f", passeio, offRoad, pLitros, oLitros, precoRealGalao);
	
	return 1;
}

