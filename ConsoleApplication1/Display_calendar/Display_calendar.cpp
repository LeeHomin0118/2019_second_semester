#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int arr[50] = { 0 };
void print_c(int start, int k) {
	int cnt = 1;
	for (int i = start; i < k + start; i++)
		arr[i] = cnt++;
	for (int i = 0; i < k + start; i++) {
		if (i % 7 == 0) printf("\n");
		if (arr[i] == 0) printf("     ");
		else printf("%4d ", arr[i]);
	}
}
int main() {
	int year, month;
	printf("yyyy mm?\n");
	scanf("%d %d", &year, &month);
	int sum = 0;
	sum = year * 365;
	int yun = 0;
	for (int i = 1; i < year; i++) {
		if (i % 400 == 0 || (i % 4 == 0 && i % 100 != 0))
			++sum;
	}
	for (int i = 1; i < month; i++) {
		if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10) sum += 31;
		else if (i == 4 || i == 6 || i == 9 || i == 11) sum += 30;
		else if (i == 2 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))) sum += 29;
		else sum += 28;
	}
	int start = sum % 7;
	//printf("===day%d %d\n", sum, start);
	int cnt = 1;
	printf("          %4d     %2d\n", year, month);
	printf(" SUN  MON  TUE  WED  TUR  FRI  SAT\n");
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10) {
		print_c(start, 31);
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11) {
		print_c(start, 30);
	}
	else if (month == 2 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))) {
		print_c(start, 29);
	}
	else {
		print_c(start, 28);
	}
}