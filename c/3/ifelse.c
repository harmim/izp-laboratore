#include <stdio.h>

int main()
{
	int number = 42;
	number += 3;

	if (number > 44) {
		printf("Number is bigger than 44.\n");
	}

	if (number > 45) {
		printf("Number is bigger than 45.\n");
	} else {
		printf("Number is not bigger than 45.\n");
	}		

	return 0;
}

