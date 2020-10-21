#include <stdio.h>
#include <windows.h>

void avaliaTexto(char* texto)
{
	int vogais=0;
	int consoantes=0;
	int espacos=0;
	int outros=0;
	int pos=0;
	while (texto[pos]!='\0')
	{
		if ((texto[pos]>='A' && texto[pos]<='Z') ||
		    (texto[pos]>='a' && texto[pos]<='z'))
		{
			if (texto[pos]=='A' || texto[pos]=='E' || texto[pos]=='I' || texto[pos]=='O' || texto[pos]=='U' ||
			    texto[pos]=='a' || texto[pos]=='e' || texto[pos]=='i' || texto[pos]=='o' || texto[pos]=='u'
			   )
			    vogais++;
			else
				consoantes++;
		}
		else if (texto[pos]==' ')
			espacos++;
		else
			outros++;
		pos++;
	}
    printf("A quantidade de vogais é: %d\n",vogais);
    printf("A quantidade de consoantes é: %d\n",consoantes);
    printf("A quantidade de espaços é: %d\n",espacos);
    printf("A quantidade de outros caracteres é: %d\n",outros);
	return;
}

int main()
{
	SetConsoleOutputCP(1252);
	char texto[100];
	printf("Informe o texto desejado: ");
	scanf("%99[^\n]s",texto);
	avaliaTexto(texto);
}

