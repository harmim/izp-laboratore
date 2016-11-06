#include <stdio.h>

int main(int argc, char *argv[])
{
	int found_h = 0, i, j;

	for (i = 1; i < argc && ! found_h; i++) {
		for (j = 0; argv[i][j] != '\0'; j++) {
			if (argv[i][j] == 'h') {
				found_h = 1;
				break;
			}		
		}
	}

	if (found_h) {
		printf("Letter h was found in argument %d in position %d.\n", i, j);
	}

	return 0;
}

