#include <stdio.h>

#define N 10
#define A 6
#define B 12
#define STR "foo"

int main()
{
	printf("Vzestupne interval [0;%d) ", N);
	for (int i = 0; i < N; i++) { printf("%d ", i); }

	printf("\nVzestupne inteval [%d;%d] ", A, B);
	for (int i = A; i <= B; i++) { printf("%d ", i); }

	printf("\nSestupne interval [%d;%d) ", A, B);
	for (int i = B - 1; i >= A; i--) { printf("%d ", i); }

	printf("\nVzestupne ob jedno interval [%d;%d] ", A, B);
	for (int i = A; i <= B; i += 2) { printf("%d ", i); }

	printf("\nPo zacich retezce ");
	for (int i = 0; (STR[i] != '\0'); i++) { printf("%c ", STR[i]); }

	printf("\nPo znacich ze stdin  ");
	for (char c; ((c = getchar()) != EOF);) { printf("%c", c); }

	printf("\n");

	return 0;
}

