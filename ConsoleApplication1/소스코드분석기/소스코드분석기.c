#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct S_word {
	char* word;
	char* mean;
} sword;

int main() {
	FILE *fp1;
	char *str;
	sword wordlist[52000];
	if ((fp1 = fopen("dict_test.TXT", "r")) == NULL) {
		printf("fale to open file.");
		return 0;
	}
	int cnt = 0;
	while (fgets(str, 1000, fp1)) {
		char *token = strtok(str, ":");
		token[strlen(token)] = NULL;
		int len = strlen(token);
		if (!(len >= 4 && len <= 10)) { continue; }
		strcpy(wordlist[cnt].word, token);
		token = strtok(NULL, ":");
		strcpy(wordlist[cnt].mean, token);
		cnt++;
	}
	for (int i = 0; i < cnt; i++) {
		printf("%s %s\n", wordlist[i].word, wordlist[i].mean);
	}
}