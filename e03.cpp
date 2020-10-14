#include <math.h>
#include <stdio.h>
#include <windows.h>

const float galao = 0.26417;

int main()
{
	SetConsoleOutputCP(1252);
	
	int passeio = 0, offRoad = 0, qtdGalao = 0;
	float pLitros = 0, oLitros = 0, precoRealGalao = 0;
	float totalLitrosPasseio = 0, totalLitrosOffRoad = 0, totalLitros = 0;
	float totalValor = 0;
	
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
	
//	printf("\nPasseio: %d\nOff-road: %d\n", passeio, offRoad);
	
//	printf("\nLitros Passeio: %.1fl\nLitros Off-road: %.1fl\n", pLitros, oLitros);
	
//	printf("\nPre�o R$/gal�o: R$%.2f\nGal�o: %.5f\n", precoRealGalao, galao);
	
	totalLitrosPasseio = pLitros * passeio;
	totalLitrosOffRoad = oLitros * offRoad;
	totalLitros = totalLitrosPasseio + totalLitrosOffRoad;
//	printf("\nTotal Litros Passeio: %.1fl", totalLitrosPasseio);
//	printf("\nTotal Litros Off-road: %.1fl", totalLitrosOffRoad);
//	printf("\nTotal Litros: %.1fl\n", totalLitros);
	
	qtdGalao = ceil(totalLitros * galao);
	totalValor = precoRealGalao * qtdGalao;
//	printf("\nTotal de Gal�es necess�rios: %d", qtdGalao);
	printf("\nValor total para comprar os gal�es necess�rios e encher o tanque de todos ve�culos: R$%.2f", totalValor);
	
	return 1;
}

