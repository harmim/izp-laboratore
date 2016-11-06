#include <stdio.h>

int main()
{
	int array[5] = {1, 2, 3, 4, 5};
	char str[] = "string";

	int sum = 0;
	for (int i = 0; i < 5; i++) {
		sum += array[i];
	}

	int number_of_chars = 0;
	while (str[number_of_chars] != '\0') {
		number_of_chars++;
	}

	printf("Array sum: %d.\n", sum);
	printf("Number of chars: %d\n", number_of_chars);

	return 0;
}

