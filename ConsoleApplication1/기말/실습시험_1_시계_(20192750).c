#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <Windows.h>

void print_0(int i);
void print_1(int i);
void print_2(int i);
void print_3(int i);
void print_4(int i);
void print_5(int i);
void print_6(int i);
void print_7(int i);
void print_8(int i);
void print_9(int i);
void print_col(int i);

char arr[10][96] = { 0 };
int main() {
	//파일 오픈
	FILE* fp1 = fopen("number.bmp", "r");
	if (fp1 == NULL) {	//오픈 실패 확인
		printf("fale to open file.");
		return 0;
	}
	fseek(fp1, 62, SEEK_SET);
	//bmp파일에서 데이터 불러오기
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 12; j++) {
			unsigned char a;
			unsigned char b = 128;
			fread(&a, sizeof(a), 1, fp1);
			for (int k = 0; k < 8; k++) {
				if (a & b) arr[9 - i][j * 8 + k] = ' ';
				else arr[9 - i][j * 8 + k] = '@';
				b >>= 1;
			}
		}
	}

	int hour, min, sec;
	time_t current;
	struct tm* d;
	//시계 작동 부분
	while (1) {
		current = time(NULL);

		d = localtime(&current);
		hour = d->tm_hour;
		min = d->tm_min;
		sec = d->tm_sec;

		printf("\n");
		//시계를 출력하는 부분
		for (int i = 0; i < 10; i++) {
			//시간을 표시하는 부분
			if (hour / 10 == 1) print_1(i);
			else if (hour / 10 == 2) print_2(i);
			else print_0(i);
			if (hour % 10 == 0) print_0(i);
			else if (hour % 10 == 1) print_1(i);
			else if (hour % 10 == 2) print_2(i);
			else if (hour % 10 == 3) print_3(i);
			else if (hour % 10 == 4) print_4(i);
			else if (hour % 10 == 5) print_5(i);
			else if (hour % 10 == 6) print_6(i);
			else if (hour % 10 == 7) print_7(i);
			else if (hour % 10 == 8) print_8(i);
			else if (hour % 10 == 9) print_9(i);
			print_col(i);
			//분을 표시하는 부분
			if (min / 10 == 1) print_1(i);
			else if (min / 10 == 2) print_2(i);
			else if (min / 10 == 3) print_3(i);
			else if (min / 10 == 4) print_4(i);
			else if (min / 10 == 5) print_5(i);
			else if (min / 10 == 6) print_6(i);
			else print_0(i);
			if (min % 10 == 0) print_0(i);
			else if (min % 10 == 1) print_1(i);
			else if (min % 10 == 2) print_2(i);
			else if (min % 10 == 3) print_3(i);
			else if (min % 10 == 4) print_4(i);
			else if (min % 10 == 5) print_5(i);
			else if (min % 10 == 6) print_6(i);
			else if (min % 10 == 7) print_7(i);
			else if (min % 10 == 8) print_8(i);
			else if (min % 10 == 9) print_9(i);
			print_col(i);
			//초를 표시하는 부분
			if (sec / 10 == 1) print_1(i);
			else if (sec / 10 == 2) print_2(i);
			else if (sec / 10 == 3) print_3(i);
			else if (sec / 10 == 4) print_4(i);
			else if (sec / 10 == 5) print_5(i);
			else if (sec / 10 == 6) print_6(i);
			else print_0(i);
			if (sec % 10 == 0) print_0(i);
			else if (sec % 10 == 1) print_1(i);
			else if (sec % 10 == 2) print_2(i);
			else if (sec % 10 == 3) print_3(i);
			else if (sec % 10 == 4) print_4(i);
			else if (sec % 10 == 5) print_5(i);
			else if (sec % 10 == 6) print_6(i);
			else if (sec % 10 == 7) print_7(i);
			else if (sec % 10 == 8) print_8(i);
			else if (sec % 10 == 9) print_9(i);
			printf("\n");
		}
		printf("\n");
		//printf("%02d:%02d:%02d\n", hour, min, sec);
		Sleep(1000);
	}

	return 0;
}

//각 숫자를 출력하는 부분
void print_0(int i) {
	for (int j = 72; j < 80; j++) {
		printf("%c", arr[i][j]);
	}
}
void print_1(int i) {
	printf(" ");
	for (int j = 0; j < 6; j++) {
		printf("%c", arr[i][j]);
	}
	printf(" ");
}
void print_2(int i) {
	for (int j = 7; j < 15; j++) {
		printf("%c", arr[i][j]);
	}
}
void print_3(int i) {
	for (int j = 16; j < 24; j++) {
		printf("%c", arr[i][j]);
	}
}
void print_4(int i) {
	for (int j = 24; j < 32; j++) {
		printf("%c", arr[i][j]);
	}
}
void print_5(int i) {
	for (int j = 32; j < 40; j++) {
		printf("%c", arr[i][j]);
	}
}
void print_6(int i) {
	for (int j = 40; j < 48; j++) {
		printf("%c", arr[i][j]);
	}
}
void print_7(int i) {
	for (int j = 49; j < 57; j++) {
		printf("%c", arr[i][j]);
	}
}
void print_8(int i) {
	for (int j = 56; j < 64; j++) {
		printf("%c", arr[i][j]);
	}
}
void print_9(int i) {
	for (int j = 64; j < 72; j++) {
		printf("%c", arr[i][j]);
	}
}
void print_col(int i) {
	for (int j = 82; j < 86; j++) {
		printf("%c", arr[i][j]);
	}
}