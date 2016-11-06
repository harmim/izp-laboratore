#include <stdio.h>
#include <stdlib.h>

int main()
{
	char str[] = "123abc";

	printf("atoi(): %d\n", atoi(str));

	printf("%d\n", (int) strtol(str, (char **) NULL, 10));

	return 0;
}

