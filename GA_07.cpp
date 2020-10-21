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

char* substr(char *texto,int posInicio,int qtdCaracteres)
{
	char subTexto[100];
	char pos=0;
	int posFim=posInicio+qtdCaracteres;
	for (int p=posInicio;(p<posFim && texto[p]!='\0');p++)
	   subTexto[pos++]=texto[p];
	subTexto[pos]='\0';
	return strdup(subTexto);
}

void convData(char *data,int *dia,int *mes,int *ano)
{
	*dia=atoi(substr(data,0,2));
	*mes=atoi(substr(data,3,2));
	*ano=atoi(substr(data,6,4));
    return;
}

char* convData(int dia,int mes,int ano)
{
	char data[11];
	if (ano<100)
		ano+=2000;
	sprintf(data, "%02d/%02d/%04d",dia,mes,ano);
	return strdup(data);
}

char* diaSeguinte(char *data)
{
	int dia,mes,ano;
	char diaSeg[11];
	convData(data,&dia,&mes,&ano);
	dia++;
	if (!ehDataValida(dia,mes,ano))
	{
		dia=1;
		mes++;
		if (!ehDataValida(dia,mes,ano))
		{	
			mes=1;
			ano++;
		}
	}
	return convData(dia,mes,ano);
}

int main()
{
	SetConsoleOutputCP(1252);
	int dia, mes, ano;
	char data[11];
	char dataSeguinte[11];
	printf("Data - Informe o dia: ");
	scanf("%d",&dia);
	printf("       Informe o mês: ");
	scanf("%d",&mes);
	printf("       Informe o ano: ");
	scanf("%d",&ano);

	if (ehDataValida(dia,mes,ano))
	{
		strcpy(data,convData(dia,mes,ano));
		strcpy(dataSeguinte,diaSeguinte(data));
		printf("O dia seguinte a %s é %s\n",data,dataSeguinte);
	}
	else
		printf("Há uma data inválida\n");
}

