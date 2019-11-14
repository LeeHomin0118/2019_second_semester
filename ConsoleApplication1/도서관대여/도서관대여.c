#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

const char *password = "kkk";		//sangsangdomothanhandlename
int allyear = 1, allmonth = 1, allday = 1;		// 윤년 계산 안함 2월은 항상 28일

typedef struct S_date {		//대출시 기록할 때 부터 반납일을 기록함
	int check;				//빌린 책의 권수 max=3
	char ISBN[3][20];		//ISBN값으로 책 목록을 검색해서 책 정보를 출력
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
	sdate date;
	struct S_person *myper;
} sperson;

typedef struct S_book {
	int state;				//책이 빌려진지에 대한 state
	char bookname[50];
	char author[20];
	char ISBN[20];
	char pername[20];		//책을 빌린사람의 이름을 기록
	int year, month, day;
	struct S_book *mybook;
} sbook;

void calender_sys(sperson *per, sbook *book);

void add_person(sperson *per);						//회원정보 추가			--- 끝
void del_person();									//회원정보 삭제			--- 끝
void print_person(sperson *per, sbook *book);		//회원정보 리스트 출력	--- 끝
void find_person(sperson *per, sbook *book);		//회원정보 검색			--- 끝
void add_book(sbook *book);							//책 추가				--- 끝
void del_book();									//책 삭제				--- 끝
void find_book(sperson *per, sbook *book);			//책 찾기				--- 끝
void print_book(sbook *book);						//책 리스트 출력			--- 끝
void borrowed_booklist_print(sbook *book);			//빌려진 책 리스트 출력	--- 끝
void borrow_book(sperson *per, sbook *book);		//책 빌리기				--- 끝
void return_book(sperson *per, sbook *book);		//책 반납하기			--- 끝
void add_person_data(sperson *per, char *name, char *phnnum, char *pinnum, int year, int month, int day);
void add_book_data(sbook *book, char *bname, char *author, char *isbn);
void print_person_info(sperson *per);
void print_book_info(sbook *book);

void print_info();
int admin_login();
//회원 정보 수정하기 책 정보 수정하기

sperson personend, personhead;
sbook bookend, bookhead;

int main() {
	personhead.myper = &personend;
	bookhead.mybook = &bookend;
	personend.myper = NULL;
	bookend.mybook = NULL;
	add_person_data(&personhead, "joe", "010-1234-5678", "1960107", 1996, 01, 07);
	add_person_data(&personhead, "elly", "010-1111-2222", "2030419", 2003, 04, 19);
	add_person_data(&personhead, "mike", "010-3333-4444", "3991128", 1999, 11, 28);
	add_person_data(&personhead, "cathy", "010-5555-6666", "4830311", 1983, 03, 11);
	add_person_data(&personhead, "bang", "010-7777-8888", "5990419", 1999, 04, 19);
	add_book_data(&bookhead, "homo_sapiens", "yuval_noah_harari", "SSBN0001");
	add_book_data(&bookhead, "homo_deus", "yuval_noah_harari", "SSBN0002");
	add_book_data(&bookhead, "guns_germs_and_steel", "jared_mason_diamond", "SSBN0003");
	add_book_data(&bookhead, "cosmos", "carl_sagan", "SSBN0004");
	add_book_data(&bookhead, "les_miserables", "victor-marie_hugo", "SSBN0005");
	printf("-----------------------------------\n");
	print_info();
	while (1) {
		printf("명령을 입력하세요. : ");
		int num;
		scanf("%d", &num);
		switch (num) {
		case 1: add_person(&personhead); break;							//완성	--- 데이터셋이 비었을 때 personhead.myper을 하면 함수에서 error
		case 2: del_person(); break;									//완성
		case 3: print_person(personhead.myper, bookhead.mybook); break;	//완성
		case 4: add_book(&bookhead); break;								//완성	--- 데이터셋이 비었을 때 bookhead.mybook을 하면 함수에서 error
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
	printf("1000. 날짜 하루 증가시키기\n");
	printf("0. 프로그램 끝내기\n");
	printf("-----------------------------------\n");
}

void calender_sys(sperson *per, sbook *book) {		//날자의 증가와 반납시키기를 구현할 시스템
	while (1) {
		if (allmonth == 2) {
			if (allday > 28) {
				allmonth++;
				allday -= 28;
			}
			if (allday < 29) break;
		}
		else if (allmonth == 2 || allmonth == 4 || allmonth == 6 || allmonth == 9 || allmonth == 11) {
			if (allday > 30) {
				allmonth++;
				allday -= 30;
			}
			if (allday < 31) break;
		}
		else if (allmonth == 12) {
			if (allday > 31) {
				allmonth = 1;
				allyear++;
				allday -= 31;
			}
			if (allday < 32) break;
		}
		else {
			if (allday > 31) {
				allmonth++;
				allday -= 31;
			}
			if (allday < 32) break;
		}
	}
	while (per->myper) {
		if (per->date.check > 0) {
			for (int i = 0; i < 3; i++) {
				if (per->date.late[i] > 0) per->date.late[i]++;
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

void print_person_info(sperson *per) {
	printf("이름 : %s\n", per->name);
	printf("스마트폰 번호 : %s\n", per->phonenumber);
	printf("핀 번호 : %s\n", per->pinnumber);
	printf("생년월일 : %4d / %2d / %2d\n", per->birthday.year, per->birthday.month, per->birthday.day);
	printf("빌린 책 권수 : %d\n", per->date.check);
	return;
}

void print_book_info(sbook *book) {
	printf("ISBN CODE : %s\n", book->ISBN);
	printf("책 제목 : %s\n", book->bookname);
	printf("저자 : %s\n", book->author);
	return;
}

void add_person(sperson *per) {		//완성
	char name[20]; char phnnum[20]; char pinnum[20]; int year; int month; int day;
	printf("이름을 입력하세요. : ");
	scanf("%s", name);
	printf("스마트폰 번호를 입력하세요. : ");
	scanf("%s", phnnum);
	printf("pin번호 (비밀번호)를 입력하세요. : ");
	scanf("%s", pinnum);
	printf("생년월일을 입력하세요. (yyyymmdd) : ");
	scanf("%4d", &year);
	scanf("%2d", &month);
	scanf("%2d", &day);
	add_person_data(&personhead, name, phnnum, pinnum, year, month, day);
}

void add_person_data(sperson *per, char *name, char *phnnum, char *pinnum, int year, int month, int day) {
	sperson *tmpper = NULL;
	while (1) {
		if (per->myper == NULL) {
			sperson *newperson;
			newperson = malloc(sizeof(sperson));
			if (newperson == NULL) {
				printf("메모리 확보 실패\n");
				exit(0);
			}
			newperson->myper = tmpper->myper;
			tmpper->myper = newperson;
			strcpy(newperson->name, name);
			strcpy(newperson->phonenumber, phnnum);
			strcpy(newperson->pinnumber, pinnum);
			newperson->birthday.year = year;
			newperson->birthday.month = month;
			newperson->birthday.day = day;
			newperson->date.check = 0;
			for (int i = 0; i < 3; i++) newperson->date.late[i] = 0;
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
		print_person_info(per);
		if (per->date.check) {		//빌린 책이 있는지 확인
			printf("----------<보유한 책 목록>----------\n");
			for (int i = 0; i < 3; i++) {
				if (per->date.late[i] <= 0) continue;
				printf("반납일 : %4d / %2d / %2d\n", per->date.year[i], per->date.month[i], per->date.day[i]);
				sbook *tmpbookptr = book;
				while (tmpbookptr->mybook) {		//책 목록 탐색
					if (!strcmp(tmpbookptr->ISBN, per->date.ISBN[i])) {
						print_book_info(tmpbookptr);
						printf("연체일 : %d\n", per->date.late[i]);
						break;
					}
					tmpbookptr = tmpbookptr->mybook;
				}
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
				print_person_info(tmpperptr);
				if (tmpperptr->date.check) {		//빌린 책이 있는지 확인
					printf("----------<보유한 책 목록>----------\n");
					for (int i = 0; i < 3; i++) {
						if (tmpperptr->date.late[i] <= 0) continue;
						printf("반납일 : %4d / %2d / %2d\n", tmpperptr->date.year[i], tmpperptr->date.month[i], tmpperptr->date.day[i]);
						sbook *tmpbookptr = book;
						while (tmpbookptr->mybook) {		//책 목록 탐색
							if (!strcmp(tmpbookptr->ISBN, tmpperptr->date.ISBN[i])) {
								print_book_info(tmpbookptr);
								printf("연체일 : %d\n", tmpperptr->date.late[i]);
								break;
							}
							tmpbookptr = tmpbookptr->mybook;
						}
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
	char bname[50]; char author[20]; char isbn[20];
	printf("책 정보를 입력하세요. : ");
	scanf("%s", bname);
	printf("저자를 입력하세요. : ");
	scanf("%s", author);
	printf("ISBN을 입력하세요. : ");
	scanf("%s", isbn);
	add_book_data(&bookhead, bname, author, isbn);
}

void add_book_data(sbook *book, char *bname, char *author, char *isbn) {
	sbook *tmpbook = NULL;
	while (1) {
		if (book->mybook == NULL) {
			sbook *newbook;
			newbook = malloc(sizeof(sbook));
			if (newbook == NULL) {
				printf("메모리 확보 실패\n");
				exit(0);
			}
			newbook->mybook = tmpbook->mybook;
			tmpbook->mybook = newbook;
			strcpy(newbook->bookname, bname);
			strcpy(newbook->author, author);
			strcpy(newbook->ISBN, isbn);
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
	printf("----------<보유한 책 목록>----------\n");
	while (book->mybook) {
		print_book_info(book);
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
				print_book_info(tmpbookptr);
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
	printf("----------<빌려진 책 목록>----------\n");
	int flag = 1;
	while (book->mybook) {
		if (book->state == 1) {
			print_book_info(book);
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
								if (tmpday > 28) {
									tmpmonth++;
									tmpday -= 28;
								}
								if (tmpday < 29) break;
							}
							else if (tmpmonth == 2 || tmpmonth == 4 || tmpmonth == 6 || tmpmonth == 9 || tmpmonth == 11) {
								if (tmpday > 30) {
									tmpmonth++;
									tmpday -= 30;
								}
								if (tmpday < 31) break;
							}
							else if (tmpmonth == 12) {
								if (tmpday > 31) {
									tmpmonth = 1;
									tmpyear++;
									tmpday -= 31;
								}
								if (tmpday < 32) break;
							}
							else {
								if (tmpday > 31) {
									tmpmonth++;
									tmpday -= 31;
								}
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
									if (!strcmp(tmpperptr->date.ISBN[i], tmpbookptr->ISBN)) {
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

