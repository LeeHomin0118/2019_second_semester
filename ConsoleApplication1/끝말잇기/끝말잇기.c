#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct S_word {
	char *word;
	char *mean;
	int used;
} sword;

sword wordlist[50000];
int wordcnt = 0;
int player_life = 3;
int pscr = 0, cscr = 0;

void create_word_list(FILE *f) {
	char str[1000];
	int cnt = 0;
	while (fgets(str, sizeof(str), f)) {
		char *token = strtok(str, ":");
		token[strlen(token)-1] = NULL;
		int len = strlen(token);
		if (!(len >= 4 && len <= 10)) { continue; }
		int flag = 0;
		for (int i = 0; i < len; i++) {
			int tmpflag = 1;
			for (char j = 'a'; j <= 'z'; j++) {
				if (token[i] == j) tmpflag = 0;
			}
			if (tmpflag) flag = 1;
		}
		if (flag) { continue; }
		len = strlen(token) + 1;
		char *newptr = (char*)malloc(sizeof(char)*len);
		strcpy(newptr, token);
		wordlist[cnt].word = newptr;
		token = strtok(NULL, ":");
		token[strlen(token) - 1] = NULL;
		len = strlen(token) + 1;
		newptr = (char*)malloc(sizeof(char)*len);
		strcpy(newptr, token);
		wordlist[cnt].mean = newptr;
		wordlist[cnt].used = 0;
		cnt++;
	}
	wordcnt = cnt;
}

char computer_turn(char start) {
	printf("컴퓨터의 차례입니다.\n");
	int tmp = -1;
	for (int i = 0; i < wordcnt; i++) {
		if (wordlist[i].word[0] == start && !wordlist[i].used) {
			printf("%s,%s (점수:%d)\n", wordlist[i].word, wordlist[i].mean, strlen(wordlist[i].word));
			cscr += strlen(wordlist[i].word);
			wordlist[i].used = 1;
			tmp = i;
			break;
		}
	}
	if (tmp == -1) {
		printf("더이상 단어가 없습니다. 컴퓨터가 패배했습니다.");
		exit(0);
	}
	return wordlist[tmp].word[strlen(wordlist[tmp].word) - 1];
}

char player_turn(char start, int ck) {
	if (player_life == 0) {
		printf("플레이어가 패배했습니다.\n");
		exit(0);
	}
	if(ck) printf("사용자의 차례입니다.\n");
	printf("단어를 입력하세요.\n");
	char str[100];
	scanf("%s", str);
	int len = strlen(str);
	if (!(len >= 4 && len <= 10)) {
		printf("단어가 길어 틀렸습니다.\n");
		player_life--;
		return player_turn(start, 0);
	}
	int tmp=-1;
	for (int i = 0; i < wordcnt; i++) {
		if (!strcmp(str, wordlist[i].word)) {
			if (!wordlist[i].used) {
				printf("%s%s\n", wordlist[i].word, wordlist[i].mean);
				printf("맞았습니다.(점수:%d)\n", len);
				pscr += len;
				wordlist[i]	.used = 1;
				tmp = i;
				return wordlist[tmp].word[strlen(wordlist[tmp].word) - 1];
				break;
			}
			else {
				printf("이전에 입력한 단어입니다.\n");
				player_life--;
				return player_turn(start, 0);
			}
			break;
		}
	}
	if (tmp == -1) {
		printf("없는 단어입니다.\n");
		player_life--;
		return player_turn(start, 0);
	}
}

int main() {
	FILE *fp1;
	if ((fp1 = fopen("dict_test.TXT", "r")) == NULL) {
		printf("fale to open file.");
		return 0;
	}
	create_word_list(fp1);
	srand(time(NULL));
	int rnd = rand() % wordcnt;
	int tmplen = strlen(wordlist[rnd].word) - 1;
	char tmp = wordlist[rnd].word[tmplen];
	printf("컴퓨터의 차례입니다.\n");
	for (int i = 0; i < wordcnt; i++) {
		if (wordlist[i].word[0] == tmp && !wordlist[i].used) {
			printf("%s,%s\n", wordlist[i].word, wordlist[i].mean);
			wordlist[i].used = 1;
			tmp = wordlist[i].word[strlen(wordlist[i].word) - 1];
			break;
		}
	}
	while (1) {
		tmp = player_turn(tmp, 1);
		tmp = computer_turn(tmp);
	}
	fclose(fp1);
}