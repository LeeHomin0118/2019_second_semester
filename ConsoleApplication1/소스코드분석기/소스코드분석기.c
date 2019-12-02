#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *key[34] = { "auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern", "float", "for", "goto", "if", "inline", "int", "long", "register", "restrict", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while" };

int main() {
	FILE *fp1;
	char str[10000];

	if ((fp1 = fopen("myprog.c", "r")) == NULL) {
		printf("fale to open file.");
		return 0;
	}
	char tmpc;
	int ck = 0;
	while (!feof(fp1)) {
		tmpc = fgetc(fp1);
		if (!(tmpc >= 'a'&&tmpc <= 'z'||tmpc >= 'A'&&tmpc <= 'Z'||tmpc >= '0'&&tmpc <= '9'||tmpc == '_')) {
			int flag = 1;
			for (int i = 0; i < 34; i++) {
				if (!strcmp(str, key[i])) {
					printf("(%s)", str);
					ck = 0;
					str[ck] = NULL;
					printf("%c", tmpc);
					flag = 0;
					break;
				}
			}
			if (flag) {
				printf("%s", str);
				ck = 0;
				str[ck] = NULL;
				printf("%c", tmpc);
			}
		}
		else {
			str[ck++] = tmpc;
			str[ck] = NULL;
		}
	}
}