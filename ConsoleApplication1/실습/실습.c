#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct {
	char name[10];
	int kor;
	int eng;
	int math;
} s_std;

int compare_name(const void *a, const void *b) {
	return strcmp(((s_std*)a)->name, ((s_std*)b)->name);
}

int compare_kor(const void *a, const void *b) {
	return ((s_std*)a)->kor, ((s_std*)b)->kor;
}

int main() {
	s_std std[10] = {
	{"lee", 100, 80, 70},
	{"yon", 99, 79, 69},
	{"a", 98, 78, 68},
	{"cc", 97, 77, 67},
	{"ddf", 96, 76, 66},
	{"dfg", 95, 75, 65},
	{"nvb", 94, 74, 64},
	{"awr", 93, 73, 63},
	{"jpo", 92, 72, 62},
	{"zfbf", 91, 71, 61},
	};

	qsort(std, 10, sizeof(s_std), compare_name);
	for (int i = 0; i < 10; i++) {
		printf("%s %d %d %d\n", std[i].name, std[i].kor, std[i].eng, std[i].math);
	}
	printf("--------------------------------\n");
	qsort(std, 10, sizeof(s_std), compare_kor);
	for (int i = 0; i < 10; i++) {
		printf("%s %d %d %d\n", std[i].name, std[i].kor, std[i].eng, std[i].math);
	}
}

/*
typedef struct student {
	int kor;
	int eng;
	struct student *mystd;
} S_student;

int main() {
	S_student std3 = { 70, 88, NULL };
	S_student std2 = { 80, 70, &std3 };
	S_student std1 = { 90, 66, &std2 };
	S_student *ptr = &std1;
	for (int i = 0; i < 3; i++) {
		printf("%d %d\n", ptr->kor, ptr->eng);
		ptr = ptr->mystd;
	}
	printf("--------------------\n");
	ptr = &std1;
	while (ptr) {
		printf("%d %d\n", ptr->kor, ptr->eng);
		ptr = ptr->mystd;
	}
}
*/

/*
int main() {
	int n;
	printf("학생수는? ");
	scanf("%d", &n);
	int *score;
	score = malloc(n * sizeof(int));
	int sum = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &score[i]);
		printf("%d\n", score[i]);
		sum += score[i];
	}
	printf("sum : %d\navg : %d", sum, sum / n);
}
*/

/*
#define MAX_STR 100				//문자열의 길이 제한
#define MAX_PERSON 100			//학생수 제한

	typedef struct SCORE {		//성적 저장
		int korean;
		int english;
		int math;
		int sum;
	} SScore;

	typedef struct PERSON {		//학생정보 저장
		int num;
		int rank;
		char name[MAX_STR];
		SScore score;
	} SPerson;

	void print_student(SPerson *a);

	int main() {
		SPerson arr[MAX_PERSON] = {
			{ 1, 0, "KIM", 50, 60, 70 },
			{ 2, 0, "LEE", 60, 70, 50 },
			{ 3, 0, "PARK", 66, 77, 88 },
			{ 4, 0, "HONG", 88, 99, 77}
		};

		for (int i = 0; i < 4; i++) {
			arr[i].score.sum = arr[i].score.korean + arr[i].score.english + arr[i].score.math;
		}

		for (int i = 0; i < 4; i++) {
			print_student(&arr[i]);
		}
		printf("\n");

		for (int i = 3; i > 0; i--) {
			for (int j = 0; j < i; j++) {
				if (arr[j].score.sum < arr[j + 1].score.sum) {
					SPerson tmp;
					tmp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = tmp;
				}
			}
		}

		for (int i = 0; i < 4; i++) {
			arr[i].rank = i + 1;
			print_student(&arr[i]);
		}
	}

	void print_student(SPerson *a) {	//출력
		printf("Rank : %d ", a->rank);
		printf("No. %d ", a->num);
		printf("Name: %4s ", a->name);
		printf("Korean score: %3d ", a->score.korean);
		printf("English score: %3d ", a->score.english);
		printf("Math score: %3d ", a->score.math);
		printf("SUM: %3d\n", a->score.sum);
	}
*/
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