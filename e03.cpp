#include <stdio.h>
#include <windows.h>

int main()
{
	SetConsoleOutputCP(1252);
	
	int passeio = 0, offRoad = 0;
	float pLitros = 0, oLitros = 0;
	
	printf("Quantos veículos de passeio tem na empresa? ");
	scanf("%d", &passeio);
	
	printf("Quantos veículos off-road? ");
	scanf("%d", &offRoad);
	
	printf("Quantos litros cabem num tanque de um veículo de passeio? ");
	scanf("%f", &pLitros);
	
	printf("Quantos litros cabem num tanque de um veículo off-road? ");
	scanf("%f", &oLitros);
	
	printf("\nPasseio: %d\nOff-road: %d\nLitros Passeio: %.1f\nLitros Off-road: %.1f", passeio, offRoad, pLitros, oLitros);
	
	return 1;
}

