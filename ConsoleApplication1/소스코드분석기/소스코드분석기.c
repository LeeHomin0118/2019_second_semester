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
	int flag = 0;
	while (!feof(fp1)) {
		tmpc = fgetc(fp1);
		if (tmpc == '"' && flag==0) {
			str[ck++] = tmpc;
			str[ck] = NULL;
			flag = 1;
			continue;
		}
		if (tmpc == '"' && flag == 1) {
			printf("%s", str);
			ck = 0;
			str[ck] = NULL;
			printf("%c", tmpc);
			flag = 0;
			continue;
		}
		if (!(tmpc >= 'a'&&tmpc <= 'z')) {
			printf("%s", str);
			ck = 0;
			str[ck] = NULL;
			printf("%c", tmpc);
		}
		else {
			str[ck++] = tmpc;
			str[ck] = NULL;
			for (int i = 0; i < 34; i++) {
				if (!strcmp(str, key[i])) {
					printf("(%s)", str);
					ck = 0;
					str[ck] = NULL;
					break;
				}
			}
		}
	}
}