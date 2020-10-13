#include <stdio.h>
#include <windows.h>

int main()
{
	SetConsoleOutputCP(1252);
	
	int passeio = 0, offRoad = 0;
	
	printf("Quantos veículos de passeio tem na empresa? ");
	scanf("%d", &passeio);
	
	printf("Quantos veículos off-road? ");
	scanf("%d", &offRoad);
	
	printf("\nPasseio: %d\nOff-road: %d", passeio, offRoad);
	
	return 1;
}

