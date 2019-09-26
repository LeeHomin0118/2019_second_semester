#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <random>
using namespace std;

int arr[7][31];

int create_random_number(int min, int max);
void create_ladder();
void print_ladder();
void ladder(int k, int rand);

int main() {
	for (int i = 0; i < 10; i++) {
		printf("\n*****%d*****\n", i);
		create_ladder();
	}
}

void create_ladder() {
	for (int j = 0; j < 7; j++) {
		for (int i = 0; i < 31; i++) {
			arr[j][i] = 0;
		}
	}
	for (int i = 1; i <= 4; i++) {
		ladder(i, create_random_number(4, 7));
	}
	print_ladder();
}
void ladder(int k, int rand) {
	while (1) {
		for (int i = 1; i < 30; i++) {
			bool tmp = (arr[k][i] == 0 && arr[k][i - 1] == 0 && arr[k][i + 1] == 0);
			if (create_random_number(0, 4) == 2 && rand!=0 && tmp) {
				arr[k][i] = k;
				arr[k + 1][i] = k;
				rand--;
			}
		}
		if (rand == 0) break;
	}
	//printf("\n***%d***\n", k);
	//print_ladder();
}
void print_ladder() {
	for (int i = 0; i < 31; i++) {
		for (int j = 1; j <= 5; j++) {
			if (arr[j][i] == j) {
				printf("|-----");
			}
			else {
				printf("|     ");
			}
		}
		printf("\n");
	}
}
int create_random_number(int min, int max) {
	random_device rnd;
	mt19937_64 rng(rnd());
	uniform_int_distribution<int> val(min, max);
	int n = val(rng);
	return n;
}
