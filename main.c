// https://codeforces.com/problemset/problem/158/A?locale=en
// Problem 'Next Round'

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void)
{
	int n, k;

	scanf("%d %d", &n, &k);

	if (n <= 0) {
		perror("Wrong number of participants\n");
	} else if ( k > n || k < 0 ) {
		perror("Placement is out of range\n");
	}

	int *results = malloc(sizeof(int) * n);

	for (int i = 0; i < n; ++i) {
		scanf(" %d", &results[i]);
	}
	
	for (int i = 0; i < n; ++i) {
		printf("%i ", results[i]);
	}

	int m = 1;
	if (results[k] == 0)
		m = -1;

	int j = k + m;
	for (; j < n && j >= 0; j += m) {
		if (results[j] != results[k])
			break;
	}

	printf("%i is number of participants advancing to the next round", j);
	printf("\n");

	return 0;
}
