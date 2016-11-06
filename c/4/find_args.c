#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
	bool error, found_h, found_o = false;

	for (int i = 1; i < argc; i++) {
		if (strcmp(argv[i], "-h") == 0) {
			found_h = true;

		} else if (strcmp(argv[i], "-o") == 0) {
			found_o = true;

		} else {
			error = true;
			break;
		}
	}

	if (( ! found_h && ! found_o) || (found_h && found_o)) {
		error = true;
	}

	if (error) {
		fprintf(stderr ,"Error occurred.\n");
		return 1;

	} else if (found_h) {
		printf("Napoveda\n");

	} else if (found_o) {
		printf("Argument -o was found.\n");
	}

	return 0;
}

