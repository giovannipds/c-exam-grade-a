#include <stdio.h>
#include <windows.h>

int main()
{
	SetConsoleOutputCP(1252);
	
	for (int i = 0, n = 0; i <= 496; i += ++n) {
		printf("%d ", i);
	}
	
	return 1;
}

