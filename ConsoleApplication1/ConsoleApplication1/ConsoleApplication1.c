#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	FILE *fp1 = fopen("TWICE.bmp", "r");
	if (fp1 == NULL) {
		printf("fale to open file.");
		return 0;
	}
	char arr[24][64] = { 0 };
	fseek(fp1, 62, SEEK_SET);
	for (int i = 0; i < 24; i++) {
		for (int j = 0; j < 8; j++) {
			unsigned char a;
			unsigned char b = 128;
			fread(&a, sizeof(a), 1, fp1);
			for (int k = 0; k < 8; k++) {
				if (a&b) arr[23 - i][j * 8 + k] = '*';
				else arr[23 - i][j * 8 + k] = ' ';
				b >>= 1;
			}
		}
	}
	for (int i = 0; i < 24; i++) {
		for (int j = 0; j < 64; j++) {
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}
}