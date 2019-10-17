#define _CRT_SECURE_NO_WARNINGS
/*
extern "C" {
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
	int main() {
		char str[100] = "l  am tom   and you  are     jane";
		int sum = 0;
		int len = strlen(str);
		bool ign = false;
		bool ck = true;
		for (int i = 0; i < len; i++) {
			char tmp = str[i];
			if (tmp == ' ' || tmp == '.' || tmp == ',') {
				ign = false;
				if (ck) {
					continue;
				}
				ck = false;
			}
			else {
				ck = true;
				if (ign) {
					continue;
				}
				sum++;
				ign = true;
			}
		}
		printf("%d", sum);
	}
}
*/
/*
extern "C" {
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
	char *mystrcat(char *a, char *b) {
		char *tmp = a + strlen(a);
		while(*b) {
			*tmp++ = *b++;
		}
		*tmp = 0;
		return a;
	}
	int main() {
		char stra[20] = "hello";
		char strb[20] = "world";
		char *result;
		result = mystrcat(stra, strb);
		printf("%s", result);
	}
}
/*
extern "C" {
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
	int main() {
		char str[100];
		scanf("%s", str);
		char *token;
		token = strtok(str, "+");
		int sum = 0;
		while (token != NULL) {
			sum += atoi(token);
			token = strtok(NULL, "+");
		}
		printf("%d", sum);
	}
}
*/
/*
extern "C" {
//7주차 실습 끝말잇기
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
	int main() {
		char stra[6];
		char strb[6];
		strcpy(stra, "apple");
		printf("시작은 apple로 한다. 단어는 5글자이어야 한다.\n");
		int cnt = 1;
		printf("(%d) %s\n", cnt, stra);
		cnt++;
		while (1) {
			printf("끝말잇기 단어는? ");
			scanf("%s", strb);
			if (strlen(strb) != 5) {
				printf("옳지 않은 끝말잇기 단어입니다. 다시 입력하세요.\n");
				continue;
			}
			else {
				if (strb[0] == stra[4]) {
					printf("(%d) %s\n", cnt++, strb);
					strcpy(stra, strb);
					for (int i = 0; i < 6; i++) {
						strb[i] = NULL;
					}
				}
				else {
					printf("옳지 않은 끝말잇기 단어입니다. 다시 입력하세요.\n");
					continue;
				}
			}
		}
	}
}
*/
/*
extern "C" {
#include <stdio.h>
	int main() {
		int value = 123456789;
		float fvalue1 = 12.625;
		float fvalue2 = 24.625;
		unsigned char* ptr = &value;
		printf("%08x\n", value);
		ptr = (unsigned char*)&value;
		for (int i = 0; i < 4; i++) {
			printf("%2x ", *ptr++);
		}
		printf("\n");
		ptr = (unsigned char*)&value;
		for (int i = 0; i < 4; i++) {
			unsigned char flag = 0x80;
			for (int j = 0; j < 8; j++) {
				if (*ptr&flag) {
					printf("1");
				}
				else {
					printf("0");
				}
				flag >>= 1;
			}
			ptr++;
			printf(" ");
		}
		printf("\n");
		ptr = (unsigned char*)&fvalue1;
		for (int i = 0; i < 4; i++) {
			printf("%2x ", *ptr++);
		}
		printf("\n");
		ptr = (unsigned char*)&fvalue1;
		for (int i = 0; i < 4; i++) {
			unsigned char flag = 0x80;
			for (int j = 0; j < 8; j++) {
				if (*ptr&flag) {
					printf("1");
				}
				else {
					printf("0");
				}
				flag >>= 1;
			}
			ptr++;
			printf(" ");
		}
		printf("\n");
		ptr = (unsigned char*)&fvalue2;
		for (int i = 0; i < 4; i++) {
			printf("%2x ", *ptr++);
		}
		printf("\n");
		ptr = (unsigned char*)&fvalue2;
		for (int i = 0; i < 4; i++) {
			unsigned char flag = 0x80;
			for (int j = 0; j < 8; j++) {
				if (*ptr&flag) {
					printf("1");
				}
				else {
					printf("0");
				}
				flag >>= 1;
			}
			ptr++;
			printf(" ");
		}
		printf("\n");
	}
}
*/
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string.h>
#include <cstring>
using namespace std;

void w06_01();

int main() {
	w06_01();
}

void w06_01() {
	char name[10], number[10], phone[15];
	strcpy(name, "이호민");
	strcpy(number, "20192750");
	strcpy(phone, "010-9142-8488");
	//scanf("%s", name);
	//scanf("%s", number);
	//scanf("%s", phone);
	printf("%s\n%s\n%s", name, number, phone);
}
*/