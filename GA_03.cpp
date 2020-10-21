#include <stdio.h>
#include <windows.h>

int main()
{
	SetConsoleOutputCP(1252);
	int qtdVeicPasseio, qtdVeicOffRoad;
	float capacTanqueVeicPasseio, capacTanqueVeicOffRoad;
	float valorGalaoGasolina, valorLitroGasolina;
	float valorTotal;

    printf("Informe o preço do galão de gasolina: ");
	scanf("%f", &valorGalaoGasolina);
	valorLitroGasolina = valorGalaoGasolina*0.26417;
	
    printf("Informe a quantidade de veículos de passeio: ");
	scanf("%d", &qtdVeicPasseio);
	printf("Informe a capacidade (l) do tanque de combustível dos veículos de passeio: ");
	scanf("%f", &capacTanqueVeicPasseio);
	
	printf("Informe a quantidade de veículos de off-road: ");
	scanf("%d", &qtdVeicOffRoad);
	printf("Informe a capacidade (l) do tanque de combustível dos veículos off-road: ");
	scanf("%f", &capacTanqueVeicOffRoad);
	
	valorTotal = (qtdVeicPasseio*capacTanqueVeicPasseio+qtdVeicOffRoad*capacTanqueVeicOffRoad)*valorLitroGasolina;

	printf("O valor total para encher os tanques de gasolina dos %d veículos da frota é %10.2f\n",qtdVeicPasseio+qtdVeicOffRoad,valorTotal);
}

