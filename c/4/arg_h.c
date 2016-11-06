#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	for (int i = 1; i < argc; i++) {
		if (strcmp(argv[i], "-h") == 0) {
			printf("Argument -h was found in index %d.\n", i);
		}
	}

	return 0;
}

