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

void ordenaDatas(int *dia1,int *mes1,int *ano1,int *dia2,int *mes2,int *ano2)
{
	bool trocar = false;

	if (*ano1<100)
		*ano1+=2000;
	if (*ano2<100)
		*ano2+=2000;

	if (*ano1>*ano2)
		trocar = true;
	else if (*ano1==*ano2)
	{
		if (*mes1>*mes2)
			trocar = true;
		else if (*mes1==*mes2)
			if (*dia1>*dia2)
				trocar = true;
	}
	if (trocar)
	{
		int aux;
		aux=*ano1;		
		*ano1=*ano2;
		*ano2=aux;
		aux=*mes1;		
		*mes1=*mes2;
		*mes2=aux;
		aux=*dia1;		
		*dia1=*dia2;
		*dia2=aux;
	}		
}

int qtdDiasAno(int ano)
{
	return ehBissexto(ano) ? 366 : 365;
}

int difDiasEntreDatas(int dia1,int mes1,int ano1,int dia2,int mes2,int ano2)
{
	int difDias=0;
	if (ano1==ano2)
		difDias=diaDoAno(dia2,mes2,ano2)-diaDoAno(dia1,mes1,ano1);
	else
	{
		difDias=qtdDiasAno(ano1)-diaDoAno(dia1,mes1,ano1);
		for (int a=ano1+1;a<ano2;a++)
			difDias+=qtdDiasAno(a);
		difDias+=diaDoAno(dia2,mes2,ano2);
	}
	return difDias;
}

int main()
{
	SetConsoleOutputCP(1252);
	int dia1, mes1, ano1;
	int dia2, mes2, ano2;
	int difDias;
	printf("Primeira Data - Informe o dia: ");
	scanf("%d",&dia1);
	printf("                Informe o mês: ");
	scanf("%d",&mes1);
	printf("                Informe o ano: ");
	scanf("%d",&ano1);
	printf("Segunda Data - Informe o dia: ");
	scanf("%d",&dia2);
	printf("               Informe o mês: ");
	scanf("%d",&mes2);
	printf("               Informe o ano: ");
	scanf("%d",&ano2);
	
	if (ehDataValida(dia1,mes1,ano1) && ehDataValida(dia2,mes2,ano2))
	{
		ordenaDatas(&dia1,&mes1,&ano1,&dia2,&mes2,&ano2);
		difDias=difDiasEntreDatas(dia1,mes1,ano1,dia2,mes2,ano2);
		printf("Existem %d dias entre %02d/%02d/%04d e %02d/%02d/%04d\n",difDias,dia1,mes1,ano1,dia2,mes2,ano2);
	}
	else
		printf("Há uma data inválida\n");
}

