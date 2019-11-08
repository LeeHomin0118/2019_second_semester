#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//sangsangdomothanhandlename
const char *password = "kkk";

typedef struct S_date {		//대출시 기록할 때 부터 반납일을 기록함
	//책은 한번에 3권만 빌릴 수 있다.
	int check;			//빌린 책의 권수 max=3
	char ISBN[3][20];	//ISBN값으로 책 목록을 검색해서 책 정보를 출력
	int year[3], month[3], day[3];
	int late;		//늦게 반납하면 페널티로 late일동안 대출 불가
} sdate;

typedef struct S_birthday {
	int year, month, day;
} sbirthday;

typedef struct S_person {
	char name[20];
	char phonenumber[20];
	char pinnumber[20];
	sbirthday birthday;
	struct S_person *myper;
	sdate date;
} sperson;

typedef struct S_book {
	int state;	//책이 빌려진지에 대한 state
	char bookname[50];
	char author[20];
	char ISBN[20];
	struct S_book *mybook;
	char pername[20];		//책을 빌린사람의 이름을 기록
} sbook;

void add_person(sperson *per, int pernum);			//회원정보 추가
void del_person(sperson *per, int pernum);			//회원정보 삭제
void print_person(sperson *per, sbook *book);		//회원정보 리스트 출력 --- 끝
void find_person(sperson *per, sbook *book);		//회원정보 검색 --- 끝
void add_book(sbook *book, int booknum);			//책 추가
void del_book(sbook *book, int booknum);			//책 삭제
void find_book(sperson *per, sbook *book);			//책 찾기
void print_book(sbook *book, int booknum);			//책 리스트 출력 --- 끝
void borrow_book(sperson *per, sbook *book);		//책 빌리기
void return_book(sperson *per, sbook *book);		//책 반납하기

//회원 정보 수정하기
//책 정보 수정하기

int main() {
	sperson personlist[100] = {
	{"joe", "010-1234-5678", "1960107", 1996,01,07, &personlist[1]},
	{"elly", "010-1111-2222", "2030419", 2003,04,19, &personlist[2]},
	{"mike", "010-3333-4444", "3991128", 1999,11,28, &personlist[3]},
	{"cathy", "010-5555-6666", "4830311", 1983,03,11, &personlist[4]},
	{"bang", "010-7777-8888", "5990419", 1999,04,19, &personlist[5]},
	};
	sbook booklist[100] = {
	{0, "homo_sapiens", "yuval_noah_harari", "SSBN0001", &booklist[1]},
	{0, "homo_deus", "yuval_noah_harari", "SSBN0002", &booklist[2]},
	{0, "guns_germs_and_steel", "jared_mason_diamond", "SSBN0003", &booklist[3]},
	{0, "cosmos", "carl_sagan", "SSBN0004", &booklist[4]},
	{0, "les_miserables", "victor-marie_hugo", "SSBN0005", &booklist[5]},
	};
	int personnum = 5;
	int booknum = 5;
	for(int i=0; i<personnum; i++) personlist[0].date.check = 0;
	personlist[personnum].myper = NULL;
	booklist[booknum].mybook = NULL;
	printf("1. 회원 추가하기\n");
	printf("2. 회원 삭제하기 --- 관리자 기능\n");
	printf("3. 회원 리스트 출력하기 --- 관리자 기능\n");
	printf("4. 책 추가하기\n");
	printf("5. 책 검색하기\n");
	printf("6. 책 리스트 출력하기\n");
	printf("7. 책 빌리기\n");
	printf("8. 책 반납하기\n");
	printf("9. 책 삭제하기 --- 관리자 기능\n");
	printf("10. 회원 검색하기 --- 관리자 기능\n");
	printf("1000. 날짜 1하루 증가시키기\n");
	printf("0. 프로그램 끝내기\n");
	while (1) {
		printf("명령을 입력하세요. : ");
		int num;
		scanf("%d", &num);
		switch (num) {
		case 1: add_person(personlist, personnum); break;
		case 2: del_person(personlist, personnum); break;
		case 3: print_person(personlist, booklist); break;		//완성
		case 4: add_book(booklist, booknum); break;
		case 5: find_book(booklist, booklist); break;			//완성
		case 6: print_book(booklist, booknum); break;			//완성
		case 7: find_book(personlist, booklist); break;			//완성
		case 8: return_book(personlist, booklist); break;
		case 9: del_book(personlist, booklist); break;
		case 10: find_person(personlist, booklist); break;		//완성
		case 1000: break;		//미완성
		case 0: return 0;
		default: {
			printf("그런 명령은 없습니다.\n");
			printf("1. 회원 추가하기\n");
			printf("2. 회원 삭제하기 --- 관리자 기능\n");
			printf("3. 회원 리스트 출력하기 --- 관리자 기능\n");
			printf("4. 책 추가하기\n");
			printf("5. 책 검색하기\n");
			printf("6. 책 리스트 출력하기\n");
			printf("7. 책 빌리기\n");
			printf("8. 책 반납하기\n");
			printf("9. 책 삭제하기 --- 관리자 기능\n");
			printf("10. 회원 검색하기 --- 관리자 기능\n");
			printf("1000. 날짜 1하루 증가시키기\n");
			printf("0. 프로그램 끝내기\n");
			break; 
		}
		}
	}
}

void add_person(sperson *per, int pernum) {

}

void del_person(sperson *per, int pernum) {
	char tmp[100];
	printf("비밀번호를 입력해주세요.\n");
	scanf("%s", tmp);
	if (strcmp(password, tmp)) {
		printf("비밀번호가 틀렸습니다.\n");
		return;
	}
}

void print_person(sperson *per, sbook *book) {		//완성
	char tmp[100];
	printf("비밀번호를 입력해주세요.\n");
	scanf("%s", tmp);
	if (strcmp(password, tmp)) {
		printf("비밀번호가 틀렸습니다.\n");
		return;
	}
	printf("-----------------------------------\n");
	while (per->myper) {
		printf("이름 : %s\n", per->name);
		printf("스마트폰 번호 : %s\n", per->phonenumber);
		printf("핀 번호 : %s\n", per->pinnumber);
		printf("생년월일 : %4d / %2d / %2d\n", per->birthday.year, per->birthday.month, per->birthday.day);
		printf("-----------------------------------\n");
		if (per->date.check) {		//빌린 책이 있는지 확인
			printf("-----<빌린 책 목록>-----\n");
			for (int i = 0; i < per->date.check; i++) {
				printf("반납일 : %4d / %2d / %2d\n", per->date.year[i], per->date.month[i], per->date.day[i]);
				printf("ISBN CODE : %s\n", per->date.ISBN[i]);
				while (book->mybook) {		//책 목록 탐색
					if (!strcmp(book->ISBN, per->date.ISBN[i])) {
						printf("책 제목 : %s\n", book->bookname);
						printf("저자 : %s\n", book->author);
					}
				}
				printf("-----------------------------------\n");
			}
		}
		else{
			printf("빌린 책은 없습니다.\n");
			printf("-----------------------------------\n");
		}
		per = per->myper;
	}
	return;
}

void find_person(sperson *per, sbook *book) {		//완성
	char tmp[100];
	printf("비밀번호를 입력해주세요.\n");
	scanf("%s", tmp);
	if (strcmp(password, tmp)) {
		printf("비밀번호가 틀렸습니다.\n");
		return;
	}
	while (1) {
		char pername[20];
		printf("endl 을 입력하면 종료합니다.\n");
		printf("이름을 입력하세요. : ");
		scanf("%s", pername);
		if (!strcmp(pername, "endl")) {
			break;
		}
		sperson *tmpperptr = per;
		sbook *tmpbookptr = book;
		int flag = 1;
		while (tmpperptr->myper) {
			if (!strcmp(tmpperptr->name, pername)) {
				printf("이름 : %s\n", tmpperptr->name);
				printf("스마트폰 번호 : %s\n", tmpperptr->phonenumber);
				printf("핀 번호 : %s\n", tmpperptr->pinnumber);
				printf("생년월일 : %4d / %2d / %2d\n", tmpperptr->birthday.year, tmpperptr->birthday.month, tmpperptr->birthday.day);
				printf("-----------------------------------\n");
				if (tmpperptr->date.check) {		//빌린 책이 있는지 확인
					printf("-----<빌린 책 목록>-----\n");
					for (int i = 0; i < tmpperptr->date.check; i++) {
						printf("반납일 : %4d / %2d / %2d\n", tmpperptr->date.year[i], tmpperptr->date.month[i], tmpperptr->date.day[i]);
						printf("ISBN CODE : %s\n", tmpperptr->date.ISBN[i]);
						while (tmpbookptr->mybook) {		//책 목록 탐색
							if (!strcmp(tmpbookptr->ISBN, tmpperptr->date.ISBN[i])) {
								printf("책 제목 : %s\n", tmpbookptr->bookname);
								printf("저자 : %s\n", tmpbookptr->author);
							}
						}
						printf("-----------------------------------\n");
					}
				}
				else {
					printf("빌린 책은 없습니다.\n");
					printf("-----------------------------------\n");
				}
				flag = 0;
				break;
			}
			tmpperptr = tmpperptr->myper;
		}
		if (flag) {
			printf("그런 사람은 없습니다. 다시 입력해 주세요.\n");
		}
	}
}

void add_book(sbook *book, int booknum) {

}

void del_book(sbook *book, int booknum) {
	char tmp[100];
	printf("비밀번호를 입력해주세요.\n");
	scanf("%s", tmp);
	if (strcmp(password, tmp)) {
		printf("비밀번호가 틀렸습니다.\n");
		return;
	}

}

void print_book(sbook *book, int booknum) {		//완성
	printf("-----<보유한 책 목록>-----\n");
	printf("-----------------------------------\n");
	while (book->mybook) {
		printf("ISBN CODE : %s\n", book->ISBN);
		printf("책 제목 : %s\n", book->bookname);
		printf("저자 : %s\n", book->author);
		if (book->state == 0) {
			printf("상태 : 보유중\n");
		}
		else {
			printf("상태 : 대출중\n");
		}
		printf("-----------------------------------\n");
		book = book->mybook;
	}
}

void find_book(sperson *per, sbook *book) {		//완성
	while (1) {
		char tmpbookname[50];
		int flag = 1;
		sperson *tmpperptr = per;
		sbook *tmpbookptr = book;
		printf("endl 을 입력하면 종료합니다.\n");
		printf("찾으실 책 이름을 입력하세요. : ");
		scanf("%s", tmpbookname);
		if (!strcmp(tmpbookname, "endl")) {
			break;
		}
		while (tmpbookptr->mybook) {
			if (!strcmp(tmpbookname, tmpbookptr->bookname)) {
				printf("ISBN CODE : %s\n", tmpbookptr->ISBN);
				printf("책 제목 : %s\n", tmpbookptr->bookname);
				printf("저자 : %s\n", tmpbookptr->author);
				if (tmpbookptr->state == 1) {
					printf("대출중인 책입니다.\n");
				}
				else {
					char tmpc[4];
					printf("책을 보유중입니다. 대출하시겠습니까? ( yes / no ) : ");
					scanf("%s", tmpc);
					strlwr(tmpc);
					if (!strcmp(tmpc, "yes")) {
						borrow_book(per, tmpbookptr);
					}
				}
				flag = 0;
				break;
			}
			tmpbookptr = tmpbookptr->mybook;
		}
		if (flag) {
			printf("그런 책은 없습니다. 다시 입력해 주세요.\n");
		}
	}
}

void borrow_book(sperson *per, sbook *book) {
	while (1) {
		char pername[20];
		printf("endl 을 입력하면 종료합니다.\n");
		printf("대출하실 회원의 이름을 입력하세요. : ");
		scanf("%s", pername);
		if (!strcmp(pername, "endl")) {
			break;
		}
		sperson *tmpperptr = per;
		sbook *tmpbookptr = book;
		int flag = 1;
		while (tmpperptr->myper) {
			if (!strcmp(tmpperptr->name, pername)) {
				
				flag = 0;
				break;
			}
			tmpperptr = tmpperptr->myper;
		}
		if (flag) {
			printf("그런 사람은 없습니다. 다시 입력해 주세요.\n");
		}
	}
}

void return_book(sperson *per, sbook *book) {

}