#include <stdio.h>

int main()
{
	char word[11];

	while (scanf("%10s", word)) {
		printf("%s\n", word);	
	}

	return 0;
}

