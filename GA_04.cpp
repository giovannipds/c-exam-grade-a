#include <stdio.h>
#include <windows.h>

int main()
{
	SetConsoleOutputCP(1252);
	float precoEst1,precoEst2,precoEst3,precoEst4;
	float precoMedioAtual,precoMedioAnt;
	float variacao;

	printf("Informe o pre�o do produto no estabelecimento 1: ");
	scanf("%f", &precoEst1);
	printf("Informe o pre�o do produto no estabelecimento 2: ");
	scanf("%f", &precoEst2);
	printf("Informe o pre�o do produto no estabelecimento 3: ");
	scanf("%f", &precoEst3);
	printf("Informe o pre�o do produto no estabelecimento 4: ");
	scanf("%f", &precoEst4);
	precoMedioAtual=(precoEst1+precoEst2+precoEst3+precoEst4)/4;
    printf("Informe o �ltimo pre�o m�dio do produto: ");
	scanf("%f", &precoMedioAnt);
	variacao=((precoMedioAtual/precoMedioAnt)-1)*100;

	printf("Pre�o m�dio da semana anterior: R$ %6.2f\n",precoMedioAnt);
	printf("Pre�o m�dio da semana atual...: R$ %6.2f\n",precoMedioAtual);
	if (variacao<0)
		printf("Houve defla��o de %4.2f%%\n",-variacao);
	else if (variacao>0)
		printf("Houve infla��o de %4.2f%%\n",variacao);
	else
		printf("Houve estabilidade de pre�os\n");
}

