#include <stdio.h>
#include <string.h>
#include <windows.h>

int printStr(char* strPointer);

int main()
{
	SetConsoleOutputCP(1252);
	
	char str[50] = "Grupo Uniftec - Centro Universitário e Faculdades";
	
	printStr(str);
	
	return 1;
}

int printStr(char* strPointer)
{
	int vowels, consonants, spaces, others;
	for (char* p = strPointer; *p != '\0'; p++) {
		char c = tolower(*p);
		if (c == ' ')
			++spaces;
		else if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
			++vowels;
		else
			switch(c) {
				case 'a' ... 'z':
					++consonants;
					break;
				default:
					++others;
					break;
			};
	}
	printf("Palavra: %s\n\n", strPointer);
	
	printf("Vogais: %d\n", vowels);
	printf("Consoantes: %d\n", consonants);
	printf("Espaços: %d\n", spaces);
	printf("Outros: %d\n", others);
}

