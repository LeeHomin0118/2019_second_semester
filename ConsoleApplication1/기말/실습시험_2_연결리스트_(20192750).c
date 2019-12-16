#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <Windows.h>

//저장하기 위한 구조체
typedef struct SS {
	char a;
	char b;
	struct SS* myptr;	//링크를 위한 포인터
} wordSS;

void make(wordSS* tmpptr);
void display(wordSS* tmpptr);
void empty(wordSS* tmpptr);

int main() {
	//리스트의 head와 end를 위한 할당
	wordSS* SShead = (wordSS*)malloc(sizeof(wordSS));
	wordSS* SSend = (wordSS*)malloc(sizeof(wordSS));
	SShead->myptr = SSend;
	SSend->myptr = NULL;
	make(SShead);
	display(SShead);
	empty(SShead);
}

//make함수 head와 end사이에 값들은 동적할당으로 집어넣는다.
void make(wordSS* tmpptr) {
	for (int i = 'A'; i <= 'Z'; i++) {
		for (int j = 'A'; j <= 'Z'; j++) {
			wordSS* newword;
			newword = (wordSS*)malloc(sizeof(wordSS));
			newword->a = i;
			newword->b = j;
			newword->myptr = tmpptr->myptr;
			tmpptr->myptr = newword;
			tmpptr = newword;
		}
	}
}
//display 함수 head와 end사이의 값들을 NULL즉 end의 포인터를 만나기 전까지 출력한다.
void display(wordSS* tmpptr) {
	tmpptr = tmpptr->myptr;
	while (tmpptr->myptr) {
		printf("%c%c->", tmpptr->a, tmpptr->b);
		tmpptr = tmpptr->myptr;
	}
}
//empty 함수 head와 end를 포함해서 모든 동적할당을 free해준다.
void empty(wordSS* tmpptr) {
	while (tmpptr->myptr) {
		wordSS* tmp = tmpptr->myptr;	//임시로 포인터를 저장하기위한 공간
		free(tmpptr);
		tmpptr = tmp;
	}
	//마지막 end를 free해준다.
	free(tmpptr);
}