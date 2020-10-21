#include <stdio.h>
#include <windows.h>

bool ehBissexto(int ano)
{
	bool anoBissexto;
	anoBissexto = (ano % 4 == 0) && ( (ano % 100 != 0) || (ano % 400 == 0) );
	return anoBissexto;
}

bool ehDataValida(int dia, int mes, int ano)
{
	bool valida = true;
	if (ano<100)
		ano += 2000;
	if (ano<1900 || ano>2100 || mes<1 || mes>12 || dia<1 || dia>31)
		valida = false;
	else
		if ((mes==4 || mes==6 || mes==9 || mes==11) && dia>30)
			valida = false;
		else if (mes==2 && ((ehBissexto(ano) && dia>29) || (!ehBissexto(ano) && dia>28)))
		    valida = false;
	return valida;
}

char* mesExtenso(int mes)
{
	char extenso[10]="";
	switch (mes)
	{
		case 1:
			strcpy(extenso,"janeiro");
			break;
		case 2:
			strcpy(extenso,"fevereiro");
			break;
		case 3:
			strcpy(extenso,"março");
			break;
		case 4:
			strcpy(extenso,"abril");
			break;
		case 5:
			strcpy(extenso,"maio");
			break;
		case 6:
			strcpy(extenso,"junho");
			break;
		case 7:
			strcpy(extenso,"julho");
			break;
		case 8:
			strcpy(extenso,"agosto");
			break;
		case 9:
			strcpy(extenso,"setembro");
			break;
		case 10:
			strcpy(extenso,"outubro");
			break;
		case 11:
			strcpy(extenso,"novembro");
			break;
		case 12:
			strcpy(extenso,"dezembro");
			break;
	}
	return strdup(extenso);
}

int diaDoAno(int dia, int mes, int ano)
{
	int contaDias=0;
	for (int i=1; i<mes; i++)
	{
		if (i==4 || i==6 || i==9 || i==11)
			contaDias+=30;
		else if (i==2)
			contaDias+=(ehBissexto(ano))? 29 : 28;
		else
			contaDias+=31;			
	}
	contaDias+=dia;
	return contaDias;
}

char* dataExtenso(int dia, int mes, int ano)
{
	char extenso[24]="";
	sprintf(extenso, "%02d de %s de %04d", dia, mesExtenso(mes), (ano<100)?2000+ano:ano);
    return strdup(extenso);
}

int main()
{
	SetConsoleOutputCP(1252);
	int dia, mes, ano;
	printf("Informe o dia: ");
	scanf("%d",&dia);
	printf("Informe o mês: ");
	scanf("%d",&mes);
	printf("Informe o ano: ");
	scanf("%d",&ano);
	if (ehDataValida(dia,mes,ano))
	{
		printf("A data é válida\n");
	    printf("Data por extenso: %s\n",dataExtenso(dia,mes,ano));	
	    printf("Dia do ano: %d\n",diaDoAno(dia,mes,ano));	
	}
	else
		printf("A data é inválida\n");
}

