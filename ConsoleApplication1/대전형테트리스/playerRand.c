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
		printf("학번 : 00000000\tVer 1.0\n");
		return;
	}

	(*location) = nextBlock;
	(*rotation) = nextBlock / 2;

//	printf("placeblock %d\n", placeBlock(tetrisBoard, thisBlock, *location, *rotation));

}

void player_20192750(char tetrisBoard[25][12], int thisBlock, int nextBlock, int stage, int* location, int* rotation) {
	if (tetrisBoard == NULL) {
		printf("학번 : 20192750\tVer 1.0\n");
		return;
	}
	//아이디어 : 각 상황에 대해서 가중치를 주고 가중치에 대한 score를 계산해서 score가 높은 곳에 블럭을 두는 것 으로 한다.
	//블럭 0의 경우 경우의 수는 10 + 7가지
	//블럭 1의 경우 경우의 수는 8 + 9 + 8 + 9가지
	//블럭 2의 경우 경우의 수는 8 + 9 + 8 + 9가지
	//블럭 3의 경우 경우의 수는 9가지
	//블럭 4의 경우 경우의 수는 8 + 9 + 8 + 9가지
	//블럭 5의 경우 경우의 수는 8 + 9 + 8 + 9가지
	//블럭 6의 경우 경우의 수는 8 + 9 + 8 + 9가지
	
	//블럭 0의 경우 수직 수평 두가지 경우만 계산하면 됨
	//블럭 3의 경우 회전할 필요 없음 + 경우 9가지만 따지면 됨
	//나머지 블럭들은 가로가 2일때는 9가지 3일때는 9가지 경우를 고려하게 된다.
	
	//값들의 조정을 통해 최적의 해를 구함
	const double A = -3.78;		//블럭 높이의 합
	const double B = -8.8;		//블럭 사이에 있는 빈 공간의 수
	const double C = -0.59;		//빈 공간을 막고있는 블럭의 수
	const double D = 8.2;		//완성되는 줄의 수
	const double E = 3.7;		//현재 블럭이 기존 블럭과 닿는 면의 수
	const double F = 2.5;		//현재 블럭이 좌우 벽면과 닿는 면의 수
	const double G = 4.0;		//현재 블럭이 바닥면과 닿는 면의 수

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