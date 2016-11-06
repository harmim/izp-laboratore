#include <stdio.h>

int main()
{
	int char_value;
	int number_of_chars = 0;

	while ((char_value = getchar()) != EOF) {
		printf("Number value of char: %d.\n", char_value);
		printf("Char value of char: %c.\n", char_value);
		number_of_chars++;
	}

	printf("Number of chars: %d.\n", number_of_chars);

	return 0;
}

