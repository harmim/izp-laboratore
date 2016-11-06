#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	if (argc > 1 && strcmp(argv[1], "--help") == 0) {
		printf("First argument is qual to --help.\n");
	}

	return 0;
}

