#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int tmp = m - n;
	int wtmp = 60 / (m - n + 2);
	wtmp = 10 * (4 - (m - n));
	for (int i = 1; i <= 9; i++) {
		for (int j = n; j <= m; j++) {
			for (int k = 0; k < wtmp; k++)
				printf(" ");
			printf("%d * %d = %2d", i, j, i*j);
		}
		printf("\n");
	}
}