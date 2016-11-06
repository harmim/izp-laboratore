#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int i = 0;
	//while(i < argc) {
	for (; i < argc;) {
		if (strcmp(argv[i], "-h") == 0) {
			printf("Argument -h was found in index %d\n", i);
			//break;
			i = argc;
		}
		i++;
	}

	return 0;
}

