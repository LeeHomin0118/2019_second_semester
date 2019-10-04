#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define people 5
#define constk 10

int arr[people + 2][(people * 10 + 11)];
int result[people][people] = { 0 };
int find_random[constk][people][people] = { 0 };

int create_random_number(int min, int max);		//min <= number <= max�� number�� �������� �̴� �Լ�
void create_ladder();							//��ٸ��� ȣ���ϴ� �Լ�
void ladder(int k, int rand);					//�ٸ��� �������� ������ִ� �Լ�
void print_ladder();							//��ٸ��� ����ϴ� �Լ�
void print_result();							//��ٸ��� Ÿ�� ����� ����ϰ� ����ϴ� �Լ�

int main() {
    srand(time(NULL));
	for (int j = 0; j < constk; j++) {
		for (int i = 0; i < people; i++)
			for (int j = 0; j < people; j++)
				result[i][j] = 0;
		for (int i = 0; i < 100; i++) {
			printf("\n%2d ��° ��ٸ�\n", i + 1);
			create_ladder();
		}
		for (int i = 0; i < people; i++)
			for (int k = 0; k < people; k++)
				find_random[j][i][k] = result[i][k];
	}
	printf("������ ���⼺ ����\n");
	for (int k = 0; k < constk; k++) {
		printf("%2d��° ��ٸ� ����\n", k + 1);
		for (int i = 0; i < people; i++) {
			printf("%2d:( ", i + 1);
			for (int j = 0; j < people; j++) {
				printf("%c : %3d ", j + 65, find_random[k][i][j]);
			}
			printf(")\n");
		}
		printf("\n");
	}
	for (int i = 0; i < people; i++) {
		int sum[people] = { 0 };
		for (int k = 0; k < constk; k++) {
			printf("%2d��°%c:( ", k + 1, i + 65);
			for (int j = 0; j < people; j++) {
				printf("%2d : %3d ", j + 1, find_random[k][i][j]);
				sum[j] += find_random[k][i][j];
			}
			printf(")\n");
		}
		printf("%c�� ���:\n", i + 65);
		for (int j = 0; j < people; j++) {
			printf("%d�� ���: %2d ", j + 1, sum[j] / 10);
		}
		printf("\n");
	}
}

void create_ladder() {
	for (int j = 0; j < people + 2; j++)
		for (int i = 0; i < people * 10 + 11; i++)
			arr[j][i] = 0;
	for (int i = 1; i < people; i++)
		ladder(i, create_random_number(people, people * 2 - create_random_number(0, people / 2)) - 3);
	print_ladder();
	print_result();
}

void ladder(int k, int rand) {
	int cnt = 0;
	int count = 100;
	while (count--) {
		for (int i = 1; i < (people * 10 + 10); i+=create_random_number(1, 3)) {
			cnt++;
			if (rand <= 0) break;
			int tmp = (arr[k][i] == 0 && arr[k][i - 1] == 0 && arr[k][i + 1] == 0);
			if (create_random_number(0, 4) == 2 && rand!=0 && tmp) {
				arr[k][i] = k;
				arr[k + 1][i] = k;
				rand--;
			}
		}
		if (rand <= 0) break;
	}
	//printf("ladder : %d\n", cnt);
	//printf("\n***%d***\n", k);
	//print_ladder();
}

void print_ladder() {
	for (int i = 0; i < people; i++)
		printf("%2d         ", i + 1);
	printf("\n");
	for (int i = 0; i < (people * 10 + 11); i++) {
		for (int j = 1; j <= people; j++) {
			if (arr[j][i] == j)
				printf("%c%c%c%c%c%c%c%c%c%c%c", 25, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6);
			else if (arr[j][i] == j - 1 && arr[j][i] != 0)
				printf("%c          ", 23);
			else
				printf("%c          ", 5);
		}
		printf("\n");
	}
	for (int i = 0; i < people; i++)
		printf("%c          ", i + 65);
}

void print_result() {
	printf("\n�̹� ���� ���\n");
	for (int i = 1; i <= people; i++) {
		int tmp = i;
		for (int j = 0; j < (people * 10 + 11); j++) {
			if (arr[tmp][j] == tmp) tmp++;
			else if (arr[tmp][j] == tmp - 1 && arr[tmp][j] != 0) tmp--;
		}
		printf("%d : %c     ", i, 64 + tmp--);
		result[i-1][tmp]++;
	}
	printf("\n���ݱ����� �� ���\n");
	for (int i = 0; i < people; i++) {
		printf("%2d:( ", i + 1);
		for (int j = 0; j < people; j++) {
			printf("%c : %3d ", j + 65, result[i][j]);
		}
		printf(")\n");
	}
	printf("\n");
}

int create_random_number(int min, int max) {
	int n = rand() % max + min;
	return n;
}
