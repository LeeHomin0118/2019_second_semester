#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct S_city {
	char cityname[15];
	int buliding;
} scity;

typedef struct S_player {
	int balance;
	int position;
} splayer;

scity cityarr[10] = { {"start", 0},{"seoul", 0},{"tokyo", 0},{"sydney", 0},{"LA", 0},{"cairo", 0},{"phuket", 0},{"new delhi", 0},{"hanoi", 0},{"paris", 0}, };

splayer player1 = { 5000, 0 };
splayer player2 = { 5000, 0 };

int runturn();
void print_board();
void print_perstate(int n);

int main() {
	srand(time(NULL));
	for (int i = 0; i < 30; i++) {
		printf("Turn %d\n", i + 1);
;		if (!runturn()) return 0;
	}
}

int runturn() {
	int random1 = (rand() % 6) + 1;
	int random2 = (rand() % 6) + 1;
	player1.position += random1; player1.position %= 10;
	player2.position += random2; player2.position %= 10;
	printf("player1 got %d\n", player1.position + 1);
	printf("%s", cityarr[player1.position].cityname);
	if (!cityarr[player1.position].buliding)
		printf("(empty)\n");
	else
		printf("(%d)\n", cityarr[player1.position].buliding);
	if (cityarr[player1.position].buliding == 2) {
		player1.balance -= 600;
		player2.balance += 600;
		if (player1.balance < 0) {
			printf("player1's balance is %d\n", player1.balance);
			printf("player2's balance is %d\n", player2.balance);
			printf("player2 win the game\n");
			print_board();
			return 0;
		}
	}
	else if (cityarr[player1.position].buliding == 0) {
		if (player1.balance >= 300 && player1.position != 0) {
			printf("player1 buy %s\n", cityarr[player1.position].cityname);
			player1.balance -= 300;
			cityarr[player1.position].buliding = 1;
		}
		else {
			printf("can't buy %s\n", cityarr[player1.position].cityname);
		}
	}
	printf("player2 got %d\n", player2.position + 1);
	printf("%s", cityarr[player2.position].cityname);
	if (!cityarr[player2.position].buliding)
		printf("(empty)\n");
	else
		printf("(%d)\n", cityarr[player2.position].buliding);
	if (cityarr[player2.position].buliding == 1) {
		player2.balance -= 600;
		player1.balance += 600;
		if (player2.balance < 0) {
			printf("player1's balance is %d\n", player1.balance);
			printf("player2's balance is %d\n", player2.balance);
			printf("player1 win the game\n");
			print_board();
			return 0;
		}
	}
	else if (cityarr[player2.position].buliding == 0) {
		if (player2.balance >= 300 && player2.position != 0) {
			printf("player2 buy %s\n", cityarr[player2.position].cityname);
			player2.balance -= 300;
			cityarr[player2.position].buliding = 2;
		}
		else {
			printf("can't buy %s\n", cityarr[player2.position].cityname);
		}
	}
	printf("player1's balance is %d\n", player1.balance);
	printf("player2's balance is %d\n", player2.balance);
	print_board();
}

void print_board() {
	printf("┌─────────────┐  ┌─────────────┐  ┌─────────────┐  ┌─────────────┐  ┌─────────────┐\n");
	printf("│   %s", cityarr[5].cityname);
	if (cityarr[5].buliding) printf("(%d)  │  ", cityarr[5].buliding);
	else printf("( )  │  "); printf("│   %s", cityarr[6].cityname);
	if (cityarr[6].buliding) printf("(%d) │  ", cityarr[6].buliding);
	else printf("( ) │  "); printf("│ %s", cityarr[7].cityname);
	if (cityarr[7].buliding) printf("(%d)│  ", cityarr[7].buliding);
	else printf("( )│  "); printf("│   %s", cityarr[8].cityname);
	if (cityarr[8].buliding) printf("(%d)  │  ", cityarr[8].buliding);
	else printf("( )  │  "); printf("│   %s", cityarr[9].cityname);
	if (cityarr[9].buliding) printf("(%d)  │\n", cityarr[9].buliding);
	else printf("( )  │\n");
	print_perstate(5); print_perstate(6); print_perstate(7); print_perstate(8); print_perstate(9); printf("\n");
	printf("└─────────────┘  └─────────────┘  └─────────────┘  └─────────────┘  └─────────────┘\n");
	printf("       ↑                                                                  │\n");
	printf("       │                                                                   │\n");
	printf("       │                                                                   │\n");
	printf("       │                                                                   │\n");
	printf("       │                                                                   ↓\n");
	printf("┌─────────────┐  ┌─────────────┐  ┌─────────────┐  ┌─────────────┐  ┌─────────────┐\n");
	printf("│     %s", cityarr[4].cityname);
	if (cityarr[4].buliding) printf("(%d)   │  ", cityarr[4].buliding);
	else printf("( )   │  "); printf("│   %s", cityarr[3].cityname);
	if (cityarr[3].buliding) printf("(%d) │  ", cityarr[3].buliding);
	else printf("( ) │  "); printf("│   %s", cityarr[2].cityname);
	if (cityarr[2].buliding) printf("(%d)  │  ", cityarr[2].buliding);
	else printf("( )  │  "); printf("│   %s", cityarr[1].cityname);
	if (cityarr[1].buliding) printf("(%d)  │  ", cityarr[1].buliding);
	else printf("( )  │  "); printf("│   %s", cityarr[0].cityname);
	if (cityarr[0].buliding) printf("(%d)  │\n", cityarr[0].buliding);
	else printf("( )  │\n");
	print_perstate(4); print_perstate(3); print_perstate(2); print_perstate(1); print_perstate(0); printf("\n");
	printf("└─────────────┘  └─────────────┘  └─────────────┘  └─────────────┘  └─────────────┘\n");
}

void print_perstate(int n) {
	if (player1.position == n && player2.position == n) printf("│   (1) (2)   │  ");
	else if (player1.position == n) printf("│   (1) ( )   │  ");
	else if (player2.position == n) printf("│   ( ) (2)   │  ");
	else printf("│   ( ) ( )   │  ");
}
