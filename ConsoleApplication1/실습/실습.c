#define _CRT_SECURE_NO_WARNINGS
/*
c로 파일 형식을 바꿔야함
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
*/
/*
cpp로 파일 형식을 바꿔야함
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