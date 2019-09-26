#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int number[3][4] = { {1, 3, 5, 7}, {9, 11, 13, 15}, {17, 19, 21, 23} };
	int i, j, *p;
	p = &number[0][0];
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 4; j++) {
			printf("%d\n", *(*(number+i)+j));
		}
	}
	/*
	1. *(*(number+i)+j)*(p+i*1+j)
	2. *(p+i*1+j)
	*/
}
