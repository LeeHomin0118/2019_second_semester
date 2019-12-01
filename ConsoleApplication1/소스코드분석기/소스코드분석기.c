#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *key[34] = { "auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern", "float", "for", "goto", "if", "inline", "int", "long", "register", "restrict", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while" };

int main() {
	FILE *fp1;
	char str[10000];

	if ((fp1 = fopen("myprog.c", "r")) == NULL) {    //fail to open file for read
		printf("fale to open file.");
		return 0;
	}

	const char delimiters[] = " \n\t";

	while (fgets(str, sizeof(str), fp1)) {
		for (int i = 0; i < 34; i++) {

		}
	}
}