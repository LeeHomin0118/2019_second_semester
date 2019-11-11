#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

const char *password = "kkk";		//sangsangdomothanhandlename

int allyear = 1, allmonth = 1, allday = 1;		// 윤년 계산 안함 2월은 항상 28일

typedef struct S_date {		//대출시 기록할 때 부터 반납일을 기록함
	int check;			//빌린 책의 권수 max=3
	char ISBN[3][20];	//ISBN값으로 책 목록을 검색해서 책 정보를 출력
	int year[3], month[3], day[3];
	int late[3];
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
	int year, month, day;
} sbook;

void calender_sys(sperson *per, sbook *book);

void add_person(sperson *per);						//회원정보 추가			--- 끝
void del_person();									//회원정보 삭제			--- 끝
void print_person(sperson *per, sbook *book);		//회원정보 리스트 출력	--- 끝
void find_person(sperson *per, sbook *book);		//회원정보 검색			--- 끝
void add_book(sbook *book);							//책 추가				--- 끝
void del_book();									//책 삭제				--- 끝
void find_book(sperson *per, sbook *book);			//책 찾기				--- 끝
void print_book(sbook *book);						//책 리스트 출력		--- 끝
void borrowed_booklist_print(sbook *book);			//빌려진 책 리스트 출력	--- 끝
void borrow_book(sperson *per, sbook *book);		//책 빌리기				--- 끝
void return_book(sperson *per, sbook *book);		//책 반납하기			--- 끝

void print_info();
int admin_login();
//회원 정보 수정하기
//책 정보 수정하기

sperson personend, personhead;
sbook bookend, bookhead;

int main() {
	personend.myper = NULL;
	bookend.mybook = NULL;
	sperson *personlist1 = malloc(sizeof(sperson));
	sperson *personlist2 = malloc(sizeof(sperson));
	sperson *personlist3 = malloc(sizeof(sperson));
	sperson *personlist4 = malloc(sizeof(sperson));
	sperson *personlist5 = malloc(sizeof(sperson));
	strcpy(personlist1->name, "joe"); strcpy(personlist1->phonenumber, "010-1234-5678"); strcpy(personlist1->pinnumber, "1960107");
	strcpy(personlist2->name, "elly"); strcpy(personlist2->phonenumber, "010-1111-2222"); strcpy(personlist2->pinnumber, "2030419");
	strcpy(personlist3->name, "mike"); strcpy(personlist3->phonenumber, "010-3333-4444"); strcpy(personlist3->pinnumber, "3991128");
	strcpy(personlist4->name, "cathy"); strcpy(personlist4->phonenumber, "010-5555-6666"); strcpy(personlist4->pinnumber, "4830311");
	strcpy(personlist5->name, "bang"); strcpy(personlist5->phonenumber, "010-7777-8888"); strcpy(personlist5->pinnumber, "5990419");
	personlist1->birthday.year = 1996; personlist1->birthday.month = 01; personlist1->birthday.day = 07;
	personlist2->birthday.year = 2003; personlist2->birthday.month = 04; personlist2->birthday.day = 19;
	personlist3->birthday.year = 1999; personlist3->birthday.month = 11; personlist3->birthday.day = 28;
	personlist4->birthday.year = 1993; personlist4->birthday.month = 03; personlist4->birthday.day = 11;
	personlist5->birthday.year = 1999; personlist5->birthday.month = 04; personlist5->birthday.day = 19;
	personlist1->date.check = 0; for (int i = 0; i < 3; i++) personlist1->date.late[i] = 0;
	personlist2->date.check = 0; for (int i = 0; i < 3; i++) personlist2->date.late[i] = 0;
	personlist3->date.check = 0; for (int i = 0; i < 3; i++) personlist3->date.late[i] = 0;
	personlist4->date.check = 0; for (int i = 0; i < 3; i++) personlist4->date.late[i] = 0;
	personlist5->date.check = 0; for (int i = 0; i < 3; i++) personlist5->date.late[i] = 0;
	personhead.myper = personlist1;
	personlist1->myper = personlist2;
	personlist2->myper = personlist3;
	personlist3->myper = personlist4;
	personlist4->myper = personlist5;
	personlist5->myper = &personend;
	sbook *booklist1 = malloc(sizeof(sbook));
	sbook *booklist2 = malloc(sizeof(sbook));
	sbook *booklist3 = malloc(sizeof(sbook));
	sbook *booklist4 = malloc(sizeof(sbook));
	sbook *booklist5 = malloc(sizeof(sbook));
	booklist1->state = 0; strcpy(booklist1->bookname, "homo_sapiens"); strcpy(booklist1->author, "yuval_noah_harari"); strcpy(booklist1->ISBN, "SSBN0001");
	booklist2->state = 0; strcpy(booklist2->bookname, "homo_deus"); strcpy(booklist2->author, "yuval_noah_harari"); strcpy(booklist2->ISBN, "SSBN0002");
	booklist3->state = 0; strcpy(booklist3->bookname, "guns_germs_and_steel"); strcpy(booklist3->author, "jared_mason_diamond"); strcpy(booklist3->ISBN, "SSBN0003");
	booklist4->state = 0; strcpy(booklist4->bookname, "cosmos"); strcpy(booklist4->author, "carl_sagan"); strcpy(booklist4->ISBN, "SSBN0004");
	booklist5->state = 0; strcpy(booklist5->bookname, "les_miserables"); strcpy(booklist5->author, "victor-marie_hugo"); strcpy(booklist5->ISBN, "SSBN0005");
	bookhead.mybook = booklist1;
	booklist1->mybook = booklist2;
	booklist2->mybook = booklist3;
	booklist3->mybook = booklist4;
	booklist4->mybook = booklist5;
	booklist5->mybook = &bookend;
	printf("-----------------------------------\n");
	print_info();
	while (1) {
		printf("명령을 입력하세요. : ");
		int num;
		scanf("%d", &num);
		switch (num) {
		case 1: add_person(personhead.myper); break;					//완성
		case 2: del_person(); break;									//완성
		case 3: print_person(personhead.myper, bookhead.mybook); break;	//완성
		case 4: add_book(bookhead.mybook); break;						//완성
		case 5: find_book(personhead.myper, bookhead.mybook); break;	//완성
		case 6: print_book(bookhead.mybook); break;						//완성
		case 7: find_book(personhead.myper, bookhead.mybook); break;	//완성
		case 8: return_book(personhead.myper, bookhead.mybook); break;	//완성
		case 9: del_book(); break;										//완성
		case 10: find_person(personhead.myper, bookhead.mybook); break;	//완성
		case 11: borrowed_booklist_print(bookhead.mybook); break;		//완성
		case 1000: allday++; calender_sys(personhead.myper, bookhead.mybook);  break;	//완성
		case 0: return 0;
		default: {
			printf("-----------------------------------\n");
			printf("그런 명령은 없습니다.\n");
			print_info();
			break; 
		}
		}
	}
}

int admin_login() {
	char tmp[50];
	printf("비밀번호를 입력해주세요.\n");
	scanf("%s", tmp);
	if (strcmp(password, tmp)) {
		printf("비밀번호가 틀렸습니다.\n");
		return 1;
	}
	else return 0;
}

void print_info() {
	printf("관리자 기능은 관리자 비밀번호가 필요합니다.\n");
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
	printf("11. 빌려진 책 목록 출력 --- 관리자 기능\n");
	printf("1000. 날짜 1하루 증가시키기\n");
	printf("0. 프로그램 끝내기\n");
	printf("-----------------------------------\n");
}

void calender_sys(sperson *per, sbook *book) {		//날자의 증가와 반납시키기를 구현할 시스템
	while (1) {
		if (allmonth == 2) {
			if (allday > 28) allmonth++; allday -= 28;
			if (allday < 29) break;
		}
		else if (allmonth == 2 || allmonth == 4 || allmonth == 6 || allmonth == 9 || allmonth == 11) {
			if (allday > 30) allmonth++; allday -= 30;
			if (allday < 31) break;
		}
		else if (allmonth == 12) {
			if (allday > 31) allmonth = 1; allyear++; allday -= 31;
			if (allday < 32) break;
		}
		else {
			if (allday > 31) allmonth++; allday -= 31;
			if (allday < 32) break;
		}
	}
	while (per->myper) {
		if (per->date.check > 0) {
			for (int i = 0; i < 3; i++) {
				if (per->date.late[i] > 0) {
					per->date.late[i]++;
				}
				if (per->date.late[i] > 7) {
					sbook *tmpbookptr = book;
					while (tmpbookptr->mybook) {
						if (!strcmp(tmpbookptr->ISBN, per->date.ISBN[i])) {
							printf("%s 님 ", per->name);
							printf("%s 책을 반납하세요.\n", tmpbookptr->bookname);
							break;
						}
						tmpbookptr = tmpbookptr->mybook;
					}
				}
			}
		}
		per = per->myper;
	}
	printf("%d %d %d\n", allyear, allmonth, allday);
}

void add_person(sperson *per) {		//완성
	sperson *tmpper = NULL;
	while (1) {
		if (per->myper == NULL) {
			//동적할당
			sperson *newperson;
			newperson = malloc(sizeof(sperson));
			if (newperson == NULL) {
				printf("메모리 확보 실패\n");
				exit(0);
			}
			newperson->myper = tmpper->myper;
			tmpper->myper = newperson;
			printf("이름을 입력하세요. : ");
			scanf("%s", newperson->name);
			printf("스마트폰 번호를 입력하세요. : ");
			scanf("%s", newperson->phonenumber);
			printf("pin번호 (비밀번호)를 입력하세요. : ");
			scanf("%s", newperson->pinnumber);
			printf("생년월일을 입력하세요. (yyyymmdd) : ");
			scanf("%4d", &newperson->birthday.year);
			scanf("%2d", &newperson->birthday.month);
			scanf("%2d", &newperson->birthday.day);
			printf("등록되었습니다.\n");
			newperson->date.check = 0;
			for(int i = 0; i < 3; i++) newperson->date.late[i] = 0;
			return;
		}
		tmpper = per;
		per = per->myper;
	}
}

void del_person() {		//완성
	if (admin_login()) return;
	while (1) {
		char pername[20];
		printf("endl 을 입력하면 종료합니다.\n");
		printf("삭제할 사람의 이름을 입력하세요. : ");
		scanf("%s", pername);
		if (!strcmp(pername, "endl")) break;
		sperson *tmpperptr = personhead.myper;
		sperson *tmpper = &personhead;
		int flag = 1;
		while (tmpperptr->myper) {
			if (!strcmp(tmpperptr->name, pername)) {
				tmpper->myper = tmpperptr->myper;
				free(tmpperptr);
				printf("삭제하였습니다.\n");
				flag = 0;
				break;
			}
			tmpper = tmpperptr;
			tmpperptr = tmpperptr->myper;
		}
		if (flag) printf("그런 사람은 없습니다. 다시 입력해 주세요.\n");
	}
}

void print_person(sperson *per, sbook *book) {		//완성
	if (admin_login()) return;
	printf("-----------------------------------\n");
	while (per->myper) {
		printf("이름 : %s\n", per->name);
		printf("스마트폰 번호 : %s\n", per->phonenumber);
		printf("핀 번호 : %s\n", per->pinnumber);
		printf("생년월일 : %4d / %2d / %2d\n", per->birthday.year, per->birthday.month, per->birthday.day);
		printf("빌린 책 권수 : %d\n", per->date.check);
		printf("-----------------------------------\n");
		if (per->date.check) {		//빌린 책이 있는지 확인
			printf("-----<빌린 책 목록>-----\n");
			for (int i = 0; i < 3; i++) {
				if (per->date.late[i] <= 0) continue;
				printf("반납일 : %4d / %2d / %2d\n", per->date.year[i], per->date.month[i], per->date.day[i]);
				printf("ISBN CODE : %s\n", per->date.ISBN[i]);
				sbook *tmpbookptr = book;
				while (tmpbookptr->mybook) {		//책 목록 탐색
					if (!strcmp(tmpbookptr->ISBN, per->date.ISBN[i])) {
						printf("책 제목 : %s\n", tmpbookptr->bookname);
						printf("저자 : %s\n", tmpbookptr->author);
						printf("연체일 : %d\n", per->date.late[i]);
						break;
					}
					tmpbookptr = tmpbookptr->mybook;
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
	if (admin_login()) return;
	while (1) {
		char pername[20];
		printf("endl 을 입력하면 종료합니다.\n");
		printf("이름을 입력하세요. : ");
		scanf("%s", pername);
		if (!strcmp(pername, "endl")) break;
		sperson *tmpperptr = per;
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
					for (int i = 0; i < 3; i++) {
						if (tmpperptr->date.late[i] <= 0) continue;
						printf("반납일 : %4d / %2d / %2d\n", tmpperptr->date.year[i], tmpperptr->date.month[i], tmpperptr->date.day[i]);
						printf("ISBN CODE : %s\n", tmpperptr->date.ISBN[i]);
						sbook *tmpbookptr = book;
						while (tmpbookptr->mybook) {		//책 목록 탐색
							if (!strcmp(tmpbookptr->ISBN, tmpperptr->date.ISBN[i])) {
								printf("책 제목 : %s\n", tmpbookptr->bookname);
								printf("저자 : %s\n", tmpbookptr->author);
								printf("연체일 : %d\n", tmpperptr->date.late[i]);
								break;
							}
							tmpbookptr = tmpbookptr->mybook;
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
		if (flag) printf("그런 사람은 없습니다. 다시 입력해 주세요.\n");
	}
}

void add_book(sbook *book) {		//완성
	sbook *tmpbook = NULL;
	while (1) {
		if (book->mybook == NULL) {
			//동적할당
			sbook *newbook;
			newbook = malloc(sizeof(sbook));
			if (newbook == NULL) {
				printf("메모리 확보 실패\n");
				exit(0);
			}
			printf("책 정보를 입력하세요. : ");
			scanf("%s", newbook->bookname);
			printf("저자를 입력하세요. : ");
			scanf("%s", newbook->author);
			printf("ISBN을 입력하세요. : ");
			scanf("%s", newbook->ISBN);
			newbook->mybook = tmpbook->mybook;
			tmpbook->mybook = newbook;
			printf("등록되었습니다.\n");
			newbook->state = 0;
			return;
		}
		tmpbook = book;
		book = book->mybook;
	}
}

void del_book() {		//완성
	if (admin_login()) return;
	while (1) {
		char bookname[20];
		printf("endl 을 입력하면 종료합니다.\n");
		printf("삭제할 책의 이름을 입력하세요. : ");
		scanf("%s", bookname);
		if (!strcmp(bookname, "endl")) break;
		sbook *tmpbookptr = bookhead.mybook;
		sbook *tmpbook = &bookhead;
		int flag = 1;
		while (tmpbookptr->mybook) {
			if (!strcmp(tmpbookptr->bookname, bookname)) {
				tmpbook->mybook = tmpbookptr->mybook;
				free(tmpbookptr);
				printf("삭제하였습니다.\n");
				flag = 0;
				break;
			}
			tmpbook = tmpbookptr;
			tmpbookptr = tmpbookptr->mybook;
		}
		if (flag) printf("그런 책은 없습니다. 다시 입력해 주세요.\n");
	}
}

void print_book(sbook *book) {		//완성
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
			printf("예상 반납일 : %4d %2d %2d\n", book->year, book->month, book->day);
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
		if (!strcmp(tmpbookname, "endl")) break;
		while (tmpbookptr->mybook) {
			if (!strcmp(tmpbookname, tmpbookptr->bookname)) {
				printf("ISBN CODE : %s\n", tmpbookptr->ISBN);
				printf("책 제목 : %s\n", tmpbookptr->bookname);
				printf("저자 : %s\n", tmpbookptr->author);
				if (tmpbookptr->state == 1) {
					printf("대출중인 책입니다.\n");
					printf("예상 반납일 : %4d %2d %2d\n", tmpbookptr->year, tmpbookptr->month, tmpbookptr->day);
				}
				else {
					char tmpc[4];
					printf("책을 보유중입니다. 대출하시겠습니까? ( yes / no ) : ");
					scanf("%s", tmpc);
					if (!strcmp(tmpc, "yes")) borrow_book(per, tmpbookptr);
					else if (strcmp(tmpc, "no")) printf("잘못 입력하셨습니다.\n");
				}
				flag = 0;
				break;
			}
			tmpbookptr = tmpbookptr->mybook;
		}
		if (flag) printf("그런 책은 없습니다. 다시 입력해 주세요.\n");
	}
}

void borrowed_booklist_print(sbook *book) {		//완성
	if (admin_login()) return;
	printf("-----<빌려진 책 목록>-----\n");
	printf("-----------------------------------\n");
	int flag = 1;
	while (book->mybook) {
		if (book->state == 1) {
			printf("ISBN CODE : %s\n", book->ISBN);
			printf("책 제목 : %s\n", book->bookname);
			printf("저자 : %s\n", book->author);
			printf("빌린 사람 : %s\n", book->pername);
			printf("예상 반납일 : %4d %2d %2d\n", book->year, book->month, book->day);
			printf("-----------------------------------\n");
			flag = 0;
		}
		book = book->mybook;
	}
	if (flag) printf("빌려진 책이 없습니다.\n");
}

void borrow_book(sperson *per, sbook *book) {
	while (1) {
		char pername[20];
		printf("endl 을 입력하면 종료합니다.\n");
		printf("대출하실 회원의 이름을 입력하세요. : ");
		scanf("%s", pername);
		if (!strcmp(pername, "endl")) break;
		sperson *tmpperptr = per;
		sbook *tmpbookptr = book;
		while (tmpperptr->myper) {
			if (!strcmp(tmpperptr->name, pername)) {
				printf("pin번호를 입력해 주세요. : ");
				char tmppin[20];
				scanf("%s", tmppin);
				if (strcmp(tmppin, tmpperptr->pinnumber)) {
					printf("pin번호가 다릅니다.\n");
					return;
				}
				if (tmpperptr->date.check < 3) {
					int tmpck = 0;
					for (int i = 0; i < tmpperptr->date.check; i++) if (tmpperptr->date.late[i] > 7) tmpck++;
					if (tmpck == 0) {
						tmpbookptr->state = 1;	//책이 빌려졌다고 표시
						strcpy(tmpbookptr->pername, tmpperptr->name);	//빌린 사람의 이름을 기록
						printf("%s 책이 대출되었습니다.\n", tmpbookptr->bookname);
						int tmpyear = allyear, tmpmonth = allmonth, tmpday = allday + 7;
						while (1) {
							if (tmpmonth == 2) {
								if (tmpday > 28) tmpmonth++; tmpday -= 28;
								if (tmpday < 29) break;
							}
							else if (tmpmonth == 2 || tmpmonth == 4 || tmpmonth == 6 || tmpmonth == 9 || tmpmonth == 11) {
								if (tmpday > 30) tmpmonth++; tmpday -= 30;
								if (tmpday < 31) break;
							}
							else if (tmpmonth == 12) {
								if (tmpday > 31) tmpmonth = 1; tmpyear++; tmpday -= 31;
								if (tmpday < 32) break;
							}
							else {
								if (tmpday > 31) tmpmonth++; tmpday -= 31;
								if (tmpday < 32) break;
							}
						}
						printf("반납일은 %4d / %2d / %2d 입니다.\n", tmpyear, tmpmonth, tmpday);
						tmpbookptr->year = tmpyear;
						tmpbookptr->month = tmpmonth;
						tmpbookptr->day = tmpday;
						for (int i = 0; i < 3; i++) {
							if (tmpperptr->date.late[i] > 0) continue;
							else {
								strcpy(tmpperptr->date.ISBN[i], tmpbookptr->ISBN);	//빌린 책의 고유번호를 회원정보에 등록
								tmpperptr->date.year[i] = tmpyear;
								tmpperptr->date.month[i] = tmpmonth;
								tmpperptr->date.day[i] = tmpday;
								tmpperptr->date.late[i]++;
								break;
							}
						}
						tmpperptr->date.check++;
						return;
					}
					else {
						printf("연채된 책이 있어 대출하실 수 없습니다.\n");
						return;
					}
				}
				else {
					printf("이미 책 3권을 빌리셨습니다. 책을 대출하실 수 없습니다.\n");
					return;
				}
			}
			tmpperptr = tmpperptr->myper;
		}
		printf("그런 회원은 없습니다.\n회원 등록을 하시겠습니까? ( yes / no ) : ");
		char tmpc[4];
		scanf("%s", tmpc);
		if (!strcmp(tmpc, "yes")) add_person(per);
		else if (!strcmp(tmpc, "no")) printf("회원 등록을 하고 책을 빌려주세요.\n");
		else printf("잘못 입력하셨습니다.\n");	
	}
}

void return_book(sperson *per, sbook *book) {
	while (1) {
		char pername[20];
		printf("endl 을 입력하면 종료합니다.\n");
		printf("반납하실 회원의 이름을 입력하세요. : ");
		scanf("%s", pername);
		if (!strcmp(pername, "endl")) break;
		sperson *tmpperptr = per;
		while (tmpperptr->myper) {
			if (!strcmp(tmpperptr->name, pername)) {
				printf("pin번호를 입력해 주세요. : ");
				char tmppin[20];
				scanf("%s", tmppin);
				if (strcmp(tmppin, tmpperptr->pinnumber)) {
					printf("pin번호가 다릅니다.\n");
					return;
				}
				while (1) {
					if (tmpperptr->date.check == 0) {
						printf("빌린 책이 없습니다.\n");
						break;
					}
					char tmpbook[50];
					printf("endl 을 입력하면 종료합니다.\n");
					printf("반납하실 책의 이름을 입력하세요. : ");
					scanf("%s", tmpbook);
					if (!strcmp(tmpbook, "endl")) break;
					else {
						sbook *tmpbookptr = book;
						int flag = 1;
						while (tmpbookptr->mybook) {
							if (!strcmp(tmpbookptr->bookname, tmpbook)) {
								int tmpflag = 1;
								for (int i = 0; i < 3; i++) {
									if (tmpperptr->date.late[i] <= 0) continue;
									if (!strcmp(tmpperptr->date.ISBN, tmpbookptr->ISBN)) {
										printf("%s 책을 반납했습니다.\n", tmpbookptr->bookname);
										tmpbookptr->state = 0;
										tmpperptr->date.check--;
										strcpy(tmpperptr->date.ISBN[i], "");
										tmpperptr->date.late[i] = 0;
										tmpflag = 0;
									}
								}
								if (tmpflag) printf("그런 책은 빌린적이 없습니다.\n");
								flag = 0;
								break;
							}
							tmpbookptr = tmpbookptr->mybook;
						}
						if (flag) printf("그런 책은 없습니다.\n");
					}
				}
			}
			tmpperptr = tmpperptr->myper;
		}
		printf("그런 회원은 없습니다.\n");
	}
}