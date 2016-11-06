#include <stdio.h>

int main(int argc, char *argv[])
{
	printf("Number of args: %d.\n", argc);
	printf("Name of program (0. arg): %s.\n", argv[0]);	
	
	int i;

	for (i = 1; i < argc; i++) {
		printf("Value of arg number %d is %s.\n", i, argv[i]);
	}

	i = 1;
	while (i < argc) {
		printf("Value of arg number %d is %s.\n", i, argv[i]);
		i++;
	}

	return 0;
}

