#define _CRT_SECURE_NO_WARNINGS
extern "C" {
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_STR 100				//문자열의 길이 제한
#define MAX_PERSON 100			//학생수 제한

	typedef struct SCORE {		//성적 저장
		int korean;
		int english;
		int math;
		int sum;
		int avg;
	} SScore;

	typedef struct PERSON {		//학생정보 저장
		char name[MAX_STR];
		char pnumber[MAX_STR];
		SScore score;
	} SPerson;

	void one(SPerson *a);
	void two(SPerson *a);
	void input(SPerson *a);
	void print(SPerson *a);

	int main() {
		SPerson arr[MAX_PERSON] = {   //미리 데이터셋 3명 입력
			{ "이호민", "010-9142-8488", 100, 90, 80 },
			{ "신연진", "010-1234-1234", 80, 90, 100 },
			{ "설지환", "010-1234-5678", 100, 50, 100 }
		};
		printf("1. Add a person\n");
		printf("2. Print the list\n");
		printf("0. Quit the program\n");
		int cnt = 0;	//학생의 명수를 카운트
		cnt = 3;		//3명을 미리 저장해 뒀기 때문에 값 지정
		while (1) {
			printf("Enter the command: ");
			int a;
			scanf("%d", &a);
			fflush(stdin);
			switch (a) {
			case 1: {		//입력
				if (cnt == MAX_PERSON) {
					printf("Array is now full\n");
					break;
				}
				one(&arr[cnt]);
				cnt++;
				break;
			}
			case 2: {		//출력 ---> 학생이 있는지와 아예 0명인지를 확인
				if (cnt == 0) {
					printf("Please enter the person\n");
					break;
				}
				int cnttmp = 3;
				while (cnttmp--) {
					char tmp[MAX_STR];
					int flag = 0;
					printf("Enter the name who you want to find: ");
					scanf("%s", tmp);
					for (int i = 0; i < cnt; i++) {
						if (!strcmp(arr[i].name, tmp)) {
							two(&arr[i]);
							flag = 1;
							break;
						}
					}
					if (flag == 1) {
						break;
					}
					printf("re");
				}
				/*
				if (cnttmp == 0) {
					printf("There is no such name\n");
				}
				*/
				break;
			}
			case 0: exit(0); break;		//종료
			default: printf("There is no such command\n"); break;	//예외 확인
			}
		}

	}

	void one(SPerson *a) {		//입력
		input(a);
	}

	void two(SPerson *a) {		//출력
		print(a);
	}

	void input(SPerson *a) {	//입력
		printf("Enter the name: ");
		scanf("%s", a->name);
		//gets(a->name);
		printf("Enter the phone number: ");
		scanf("%s", a->pnumber);
		//gets(a->pnumber);
		printf("Enter the Korean score: ");
		scanf("%d", &a->score.korean);
		printf("Enter the English score: ");
		scanf("%d", &a->score.english);
		printf("Enter the Math score: ");
		scanf("%d", &a->score.math);
	}

	void print(SPerson *a) {	//출력
		//출력시에 계산하는게 미리 값을 지정할 때 편함
		a->score.sum = a->score.korean + a->score.english + a->score.math;
		a->score.avg = a->score.sum / 3;
		printf("Name: %s\n", a->name);
		printf("Telephone: %s\n", a->pnumber);
		printf("Korean score: %d\n", a->score.korean);
		printf("English score: %d\n", a->score.english);
		printf("Math score: %d\n", a->score.math);
		printf("SUM: %d\n", a->score.sum);
		printf("AVG: %d\n", a->score.avg);
	}
}