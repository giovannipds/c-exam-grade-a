#include <stdio.h>
#include <windows.h>

int main()
{
	SetConsoleOutputCP(1252);
	int qtdVeicPasseio, qtdVeicOffRoad;
	float capacTanqueVeicPasseio, capacTanqueVeicOffRoad;
	float valorGalaoGasolina, valorLitroGasolina;
	float valorTotal;

    printf("Informe o pre�o do gal�o de gasolina: ");
	scanf("%f", &valorGalaoGasolina);
	valorLitroGasolina = valorGalaoGasolina*0.26417;
	
    printf("Informe a quantidade de ve�culos de passeio: ");
	scanf("%d", &qtdVeicPasseio);
	printf("Informe a capacidade (l) do tanque de combust�vel dos ve�culos de passeio: ");
	scanf("%f", &capacTanqueVeicPasseio);
	
	printf("Informe a quantidade de ve�culos de off-road: ");
	scanf("%d", &qtdVeicOffRoad);
	printf("Informe a capacidade (l) do tanque de combust�vel dos ve�culos off-road: ");
	scanf("%f", &capacTanqueVeicOffRoad);
	
	valorTotal = (qtdVeicPasseio*capacTanqueVeicPasseio+qtdVeicOffRoad*capacTanqueVeicOffRoad)*valorLitroGasolina;

	printf("O valor total para encher os tanques de gasolina dos %d ve�culos da frota � %10.2f\n",qtdVeicPasseio+qtdVeicOffRoad,valorTotal);
}

