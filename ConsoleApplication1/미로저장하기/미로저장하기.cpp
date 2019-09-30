#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main() {
	wchar_t arr[12][2] = { 0 };
	arr[0][0] = 34221;
	arr[0][1] = 1442;
	arr[1][0] = 11423;
	arr[1][1] =	1142;
	arr[2][0] =	23421;
	arr[2][1] = 1121;
	arr[3][0] = 11311;
	arr[3][1] = 1213;
	arr[4][0] = 34111;
	arr[4][1] = 4122;
	arr[5][0] = 21121;
	arr[5][1] = 1222;
	arr[6][0] = 11223;
	arr[6][1] = 4122;
	arr[7][0] = 12211;
	arr[7][1] = 3221;
	arr[8][0] = 24231;
	arr[8][1] = 4243;
	arr[9][0] = 41421;
	arr[9][1] = 1121;
	arr[10][0] = 11143;
	arr[10][1] = 1221;
	arr[11][0] = 32323;
	arr[11][1] = 2232;
	for (int i = 0; i < 19; i++) {
		if (i % 2 == 0) printf("+");
		else printf("%c%c%c", 6, 6, 6);
	}
	printf("\n");
	int tmp = 0;
	double powck = 1;
	for (int i = 0; i < 12; i++) {
		tmp = 0;
		powck = 1;
		for (int j = 0; j < 9; j++) {
			if (j == 5) {
				tmp = 1;
				powck = 1;
			}
			int tmpnum = arr[i][tmp] % int(pow(10, powck)) / pow(10, powck - 1);
			powck++;
			if (tmpnum == 1) {
				printf("%c   ", 5);
				continue;
			}
			if (tmpnum == 2) {
				printf("    ");
				continue;
			}
			if (tmpnum == 3) {
				printf("%c   ", 5);
				continue;
			}
			if (tmpnum == 4) {
				printf("    ");
				continue;
			}
		}
		printf("%c\n", 5);
		tmp = 0;
		powck = 1;
		for (int j = 0; j < 9; j++) {
			if (j == 5) {
				tmp = 1;
				powck = 1;
			}
			int tmpnum = arr[i][tmp] % int(pow(10, powck)) / pow(10, powck - 1);
			powck++;
			if (tmpnum == 1) {
				printf("+   ");
				continue;
			}
			if (tmpnum == 2) {
				printf("+%c%c%c", 6, 6, 6);
				continue;
			}
			if (tmpnum == 3) {
				printf("+%c%c%c", 6, 6, 6);
				continue;
			}
			if (tmpnum == 4) {
				printf("+   ");
				continue;
			}
		}
		printf("+\n");
	}
	printf("\nsize of array : %d\n", sizeof(arr));
}