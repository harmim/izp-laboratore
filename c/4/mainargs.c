#include <stdio.h>

int main(int argc, char *argv[])
{
	printf("Number of args: %d.\n", argc);
	printf("Program name (0. arg): %s.\n", argv[0]);

	for (int i = 1; i < argc; i++) {
		printf("Value of arg number %d is %s.\n", i, argv[i]);
	}

	return 0;
}

