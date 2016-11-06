#include <stdio.h>

int main()
{
	char string1[] = "foo";
	char string2[] = "bar";
	printf("%s, %s.\n", string1, string2);
	
	int i = 1;
	printf("%d - %s.\n", i, string1);
	i++;
	printf("%d - %s.\n", i, string2);

	return 0;
}

