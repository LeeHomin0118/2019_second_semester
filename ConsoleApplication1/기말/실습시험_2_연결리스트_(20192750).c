#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <Windows.h>

//�����ϱ� ���� ����ü
typedef struct SS {
	char a;
	char b;
	struct SS* myptr;	//��ũ�� ���� ������
} wordSS;

void make(wordSS* tmpptr);
void display(wordSS* tmpptr);
void empty(wordSS* tmpptr);

int main() {
	//����Ʈ�� head�� end�� ���� �Ҵ�
	wordSS* SShead = (wordSS*)malloc(sizeof(wordSS));
	wordSS* SSend = (wordSS*)malloc(sizeof(wordSS));
	SShead->myptr = SSend;
	SSend->myptr = NULL;
	make(SShead);
	display(SShead);
	empty(SShead);
}

//make�Լ� head�� end���̿� ������ �����Ҵ����� ����ִ´�.
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
//display �Լ� head�� end������ ������ NULL�� end�� �����͸� ������ ������ ����Ѵ�.
void display(wordSS* tmpptr) {
	tmpptr = tmpptr->myptr;
	while (tmpptr->myptr) {
		printf("%c%c->", tmpptr->a, tmpptr->b);
		tmpptr = tmpptr->myptr;
	}
}
//empty �Լ� head�� end�� �����ؼ� ��� �����Ҵ��� free���ش�.
void empty(wordSS* tmpptr) {
	while (tmpptr->myptr) {
		wordSS* tmp = tmpptr->myptr;	//�ӽ÷� �����͸� �����ϱ����� ����
		free(tmpptr);
		tmpptr = tmp;
	}
	//������ end�� free���ش�.
	free(tmpptr);
}