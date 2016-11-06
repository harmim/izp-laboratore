#include <stdio.h>

int max(int a, int b);
void max_void(int a, int b, int * result);

int main()
{
	printf("Max of 2 and 5: %d\n", max(2, 5));
	int result;
	max_void(2, 5, & result);
	printf("Max of 2 and 5: %d\n", result);

	return 0;
}

/**
 * @param int a
 * @param int b
 * @return int
 */
int max(int a, int b)
{
	return a > b ? a : b;
}

/**
 * @param int a
 * @param int b
 * @param int * result
 * @return void
 */
void max_void(int a, int b, int * result)
{
	* result = a > b ? a : b;
}

