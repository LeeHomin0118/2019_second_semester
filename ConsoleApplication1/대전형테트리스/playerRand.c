//
// playerRand.c
// Random Player (Level 0)
//
// Created on 2014. 11. 11.
// Last Modified on 2014. 11. 11.
//
// Copyright(c) 2014 Nerrtica and STKim in CAUCSE. All rights reserved.
//

#include "tetrisbattle.h"


void B_Player (char tetrisBoard[25][12], int thisBlock, int nextBlock, int stage, int* location, int* rotation) {
	if (tetrisBoard == NULL) {
		printf("�й� : 00000000\tVer 1.0\n");
		return;
	}

	(*location) = nextBlock;
	(*rotation) = nextBlock / 2;

//	printf("placeblock %d\n", placeBlock(tetrisBoard, thisBlock, *location, *rotation));

}

void player_20192750(char tetrisBoard[25][12], int thisBlock, int nextBlock, int stage, int* location, int* rotation) {
	if (tetrisBoard == NULL) {
		printf("�й� : 20192750\tVer 1.0\n");
		return;
	}
	//���̵�� : �� ��Ȳ�� ���ؼ� ����ġ�� �ְ� ����ġ�� ���� score�� ����ؼ� score�� ���� ���� ���� �δ� �� ���� �Ѵ�.
	//�� 0�� ��� ����� ���� 10 + 7����
	//�� 1�� ��� ����� ���� 8 + 9 + 8 + 9����
	//�� 2�� ��� ����� ���� 8 + 9 + 8 + 9����
	//�� 3�� ��� ����� ���� 9����
	//�� 4�� ��� ����� ���� 8 + 9 + 8 + 9����
	//�� 5�� ��� ����� ���� 8 + 9 + 8 + 9����
	//�� 6�� ��� ����� ���� 8 + 9 + 8 + 9����
	
	//�� 0�� ��� ���� ���� �ΰ��� ��츸 ����ϸ� ��
	//�� 3�� ��� ȸ���� �ʿ� ���� + ��� 9������ ������ ��
	//������ ������ ���ΰ� 2�϶��� 9���� 3�϶��� 9���� ��츦 ����ϰ� �ȴ�.
	
	//������ ������ ���� ������ �ظ� ����
	const double A = -3.78;		//�� ������ ��
	const double B = -8.8;		//�� ���̿� �ִ� �� ������ ��
	const double C = -0.59;		//�� ������ �����ִ� ���� ��
	const double D = 8.2;		//�ϼ��Ǵ� ���� ��
	const double E = 3.7;		//���� ���� ���� ���� ��� ���� ��
	const double F = 2.5;		//���� ���� �¿� ����� ��� ���� ��
	const double G = 4.0;		//���� ���� �ٴڸ�� ��� ���� ��

	char tmpboard[25][12];
	for (int i = 3; i < 25; i++) {
		tmpboard[i][0] = 3;
		tmpboard[i][11] = 3;
	}
	for (int i = 0; i < 12; i++) tmpboard[24][i] = 4;
	for (int i = 3; i < 24; i++) {
		for (int j = 1; j < 11; j++) {
			if (tetrisBoard[i][j] == 1) tmpboard[i][j] = 2;
			else tmpboard[i][j] = 0;
		}
	}

	
//	(*location) = nextBlock;
//	(*rotation) = nextBlock / 2;
	printf("\n-------------------------------------------------\n");
	printf("This block : %d\n", thisBlock);
	printf("Next block : %d\n", nextBlock);
	printf("placeblock %d\n", placeBlock(tetrisBoard, thisBlock, *location, *rotation));
	printf("placeblock %d\n", placeBlock(tetrisBoard, thisBlock, *location, *rotation));
	printf("placeblock %d\n", placeBlock(tetrisBoard, thisBlock, *location, *rotation));
	for (int i = 3; i < 25; i++) {
		for (int j = 0; j < 12; j++) {
			printf("%d ", tetrisBoard[i][j]);
		}
		printf("\n");
	}
	printf("-------------------------------------------------\n");


}