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

/* ����� ��Ʈ���� �ǿ� ���� �Լ� */
int my_placeBlock(char tetrisBoard[25][12], int thisBlock, int location, int rotation) {
	int i, j;

	/* ����� �ٴڿ� �ε��� ������ �� �پ� ������.
	 * �ٴڿ� �ε����ٸ� �� �ڸ��� �迭�� ����� �����ϰ� �Լ��� �����Ѵ�.
	 * */
	location++;

	switch (thisBlock) {
	case 0:
		if (rotation == 0 || rotation == 2) {
			for (i = 0; i < 24; i++) {
				for (j = 0; j < 4; j++) {
					if (tetrisBoard[i + 1][location + j] != 0) {
						break;
					}
				}
				if (j != 4) {
					for (j = 0; j < 4; j++) {
						tetrisBoard[i][location + j] = 1;
					}
					return i;
				}
			}
		}
		else if (rotation == 1 || rotation == 3) {
			for (i = 0; i < 24; i++) {
				if (tetrisBoard[i + 4][location] != 0) {
					for (j = 0; j < 4; j++) {
						tetrisBoard[i + j][location] = 1;
					}
					return i;
				}
			}
		}
		break;

	case 1:
		if (rotation == 0) {
			for (i = 0; i < 24; i++) {
				for (j = 0; j < 3; j++) {
					if (tetrisBoard[i + 2][location + j] != 0) {
						break;
					}
				}
				if (j != 3) {
					for (j = 0; j < 3; j++) {
						tetrisBoard[i + 1][location + j] = 1;
					}
					tetrisBoard[i][location] = 1;
					return i;
				}
			}
		}
		else if (rotation == 1) {
			for (i = 0; i < 24; i++) {
				if (tetrisBoard[i + 3][location] != 0 || tetrisBoard[i + 1][location + 1] != 0) {
					for (j = 0; j < 3; j++) {
						tetrisBoard[i + j][location] = 1;
					}
					tetrisBoard[i][location + 1] = 1;
					return i;
				}
			}
		}
		else if (rotation == 2) {
			for (i = 0; i < 24; i++) {
				if (tetrisBoard[i + 1][location] != 0 || tetrisBoard[i + 1][location + 1] != 0 || tetrisBoard[i + 2][location + 2] != 0) {
					for (j = 0; j < 3; j++) {
						tetrisBoard[i][location + j] = 1;
					}
					tetrisBoard[i + 1][location + 2] = 1;
					return i;
				}
			}
		}
		else if (rotation == 3) {
			for (i = 0; i < 24; i++) {
				if (tetrisBoard[i + 3][location] != 0 || tetrisBoard[i + 3][location + 1] != 0) {
					for (j = 0; j < 3; j++) {
						tetrisBoard[i + j][location + 1] = 1;
					}
					tetrisBoard[i + 2][location] = 1;
					return i;
				}
			}
		}
		break;

	case 2:
		if (rotation == 0) {
			for (i = 0; i < 24; i++) {
				for (j = 0; j < 3; j++) {
					if (tetrisBoard[i + 2][location + j] != 0) {
						break;
					}
				}
				if (j != 3) {
					for (j = 0; j < 3; j++) {
						tetrisBoard[i + 1][location + j] = 1;
					}
					tetrisBoard[i][location + 2] = 1;
					return i;
				}
			}
		}
		else if (rotation == 1) {
			for (i = 0; i < 24; i++) {
				if (tetrisBoard[i + 3][location] != 0 || tetrisBoard[i + 3][location + 1] != 0) {
					for (j = 0; j < 3; j++) {
						tetrisBoard[i + j][location] = 1;
					}
					tetrisBoard[i + 2][location + 1] = 1;
					return i;
				}
			}
		}
		else if (rotation == 2) {
			for (i = 0; i < 24; i++) {
				if (tetrisBoard[i + 2][location] != 0 || tetrisBoard[i + 1][location + 1] != 0 || tetrisBoard[i + 1][location + 2] != 0) {
					for (j = 0; j < 3; j++) {
						tetrisBoard[i][location + j] = 1;
					}
					tetrisBoard[i + 1][location] = 1;
					return i;
				}
			}
		}
		else if (rotation == 3) {
			for (i = 0; i < 24; i++) {
				if (tetrisBoard[i + 1][location] != 0 || tetrisBoard[i + 3][location + 1] != 0) {
					for (j = 0; j < 3; j++) {
						tetrisBoard[i + j][location + 1] = 1;
					}
					tetrisBoard[i][location] = 1;
					return i;
				}
			}
		}
		break;

	case 3:
		for (i = 0; i < 24; i++) {
			if (tetrisBoard[i + 2][location] != 0 || tetrisBoard[i + 2][location + 1] != 0) {
				for (j = 0; j < 2; j++) {
					tetrisBoard[i + j][location] = 1;
					tetrisBoard[i + j][location + 1] = 1;
				}
				return i;
			}
		}
		break;

	case 4:
		if (rotation == 0 || rotation == 2) {
			for (i = 0; i < 24; i++) {
				if (tetrisBoard[i + 2][location] != 0 || tetrisBoard[i + 2][location + 1] != 0 || tetrisBoard[i + 1][location + 2] != 0) {
					for (j = 0; j < 2; j++) {
						tetrisBoard[i][location + j + 1] = 1;
						tetrisBoard[i + 1][location + j] = 1;
					}
					return i;
				}
			}
		}
		else if (rotation == 1 || rotation == 3) {
			for (i = 0; i < 24; i++) {
				if (tetrisBoard[i + 2][location] != 0 || tetrisBoard[i + 3][location + 1] != 0) {
					for (j = 0; j < 2; j++) {
						tetrisBoard[i + j][location] = 1;
						tetrisBoard[i + j + 1][location + 1] = 1;
					}
					return i;
				}
			}
		}
		break;

	case 5:
		if (rotation == 0) {
			for (i = 0; i < 24; i++) {
				for (j = 0; j < 3; j++) {
					if (tetrisBoard[i + 2][location + j] != 0) {
						break;
					}
				}
				if (j != 3) {
					for (j = 0; j < 3; j++) {
						tetrisBoard[i + 1][location + j] = 1;
					}
					tetrisBoard[i][location + 1] = 1;
					return i;
				}
			}
		}
		else if (rotation == 1) {
			for (i = 0; i < 24; i++) {
				if (tetrisBoard[i + 3][location] != 0 || tetrisBoard[i + 2][location + 1] != 0) {
					for (j = 0; j < 3; j++) {
						tetrisBoard[i + j][location] = 1;
					}
					tetrisBoard[i + 1][location + 1] = 1;
					return i;
				}
			}
		}
		else if (rotation == 2) {
			for (i = 0; i < 24; i++) {
				if (tetrisBoard[i + 1][location] != 0 || tetrisBoard[i + 2][location + 1] != 0 || tetrisBoard[i + 1][location + 2] != 0) {
					for (j = 0; j < 3; j++) {
						tetrisBoard[i][location + j] = 1;
					}
					tetrisBoard[i + 1][location + 1] = 1;
					return i;
				}
			}
		}
		else if (rotation == 3) {
			for (i = 0; i < 24; i++) {
				if (tetrisBoard[i + 2][location] != 0 || tetrisBoard[i + 3][location + 1] != 0) {
					for (j = 0; j < 3; j++) {
						tetrisBoard[i + j][location + 1] = 1;
					}
					tetrisBoard[i + 1][location] = 1;
					return i;
				}
			}
		}
		break;

	case 6:
		if (rotation == 0 || rotation == 2) {
			for (i = 0; i < 24; i++) {
				if (tetrisBoard[i + 1][location] != 0 || tetrisBoard[i + 2][location + 1] != 0 || tetrisBoard[i + 2][location + 2] != 0) {
					for (j = 0; j < 2; j++) {
						tetrisBoard[i][location + j] = 1;
						tetrisBoard[i + 1][location + j + 1] = 1;
					}
					return i;
				}
			}
		}
		else if (rotation == 1 || rotation == 3) {
			for (i = 0; i < 24; i++) {
				if (tetrisBoard[i + 3][location] != 0 || tetrisBoard[i + 2][location + 1] != 0) {
					for (j = 0; j < 2; j++) {
						tetrisBoard[i + j + 1][location] = 1;
						tetrisBoard[i + j][location + 1] = 1;
					}
					return i;
				}
			}
		}
		break;
	}
	return i;
}

//������ ������ ���� ������ �ظ� ����
const double A = -0.12;		//�� ������ ��
const double B = -30.7;		//�� ���̿� �ִ� �� ������ ��
const double C = -7.79;		//�� ������ �����ִ� ���� ��
const double D = 31.9;		//�ϼ��Ǵ� ���� ��
const double E = 1.2;		//���� ���� ���� ���� ��� ���� ��
const double F = 1.7;		//���� ���� �¿� ����� ��� ���� ��
const double G = 2.5;		//���� ���� �ٴڸ�� ��� ���� ��

double find_most_high_score(char tmpbrd[25][12], int block, int location, int rotation) {
	my_placeBlock(tmpbrd, block, location, rotation);
	double score=0;
	double asum = 0, bsum = 0, csum = 0, dsum = 0, esum = 0, fsum = 0, gsum = 0;
	for (int i = 3; i < 24; i++) {
		for (int j = 1; j < 11; j++) {
			if (tmpbrd[i][j] == 1 && tmpbrd[i + 1][j] == 4) gsum++;

			if (tmpbrd[i][j] == 1 && tmpbrd[i][j + 1] == 3) fsum++;
			if (tmpbrd[i][j] == 1 && tmpbrd[i][j - 1] == 3) fsum++;

			if (tmpbrd[i][j] == 1 && tmpbrd[i + 1][j] == 2) esum++;
			if (tmpbrd[i][j] == 1 && tmpbrd[i][j + 1] == 2) esum++;
			if (tmpbrd[i][j] == 1 && tmpbrd[i][j - 1] == 2) esum++;

			if (tmpbrd[i][j] == 1 || tmpbrd[i][j] == 2) {
				//A�� ������ ��
				asum += 25 - i;
				//D�ϼ��Ǵ� ���� ��
				int flag = 1;
				for (int k = 1; k < 11; k++) {
					if (tmpbrd[i][k] == 0) {
						flag = 0;
						break;
					}
				}
				if (flag) dsum++;
			}
		}
	}
	for (int j = 1; j < 11; j++) {
		for (int i = 3; i < 24; i++) {
			if (tmpbrd[i][j] != 0) {
				//B�� ���̿� �ִ� �� ������ ��
				for (int k = i; k < 24; k++)
					if (tmpbrd[k][j] == 0) bsum++;
				break;
			}
		}
		for (int i = 23; i >= 3; i--) {
			if (tmpbrd == 0) {
				//C�� ������ �����ִ� ���� ��
				for (int k = i; k >= 3; k--)
					if (tmpbrd[k][j] != 0) csum++;
				break;
			}
		}
	}
	//printf("%lf %lf %lf %lf %lf %lf %lf\n", asum, bsum, csum, dsum, esum, fsum, gsum);
	score = (asum*A) + (bsum*B) + (csum*C) + (dsum*D) + (esum*E) + (fsum*F) + (gsum*G);
	/*
	printf("\n-------------------------------------------------\n");
	printf("%d / %d\n", location, rotation);
	for (int i = 3; i < 25; i++) {
		for (int j = 0; j < 12; j++) {
			printf("%d ", tmpbrd[i][j]);
		}
		printf("\n");
	}
	printf("%lf\n", score);
	printf("-------------------------------------------------\n");
	*/
	return score;
}

void reset_brd(char tmpboard[25][12], char tetrisBoard[25][12]) {
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

	//���带 ������ ������ �ʱ�ȭ��Ų��.
	char tmpboard[25][12];
	reset_brd(tmpboard, tetrisBoard);
	//������ ����ġ�� ���Ѵ�
	if (thisBlock == 0) {
		int maxi, maxj;
		double maxs=-10000, tmps;
		for (int i = 0; i < 2; i++) {
			if (i == 0) {
				for (int j = 0; j < 10; j++) {
					reset_brd(tmpboard, tetrisBoard);
					tmps = find_most_high_score(tmpboard, thisBlock, j, i);
					if (tmps > maxs) { maxi = i; maxj = j; maxs = tmps; }
				}
			}
			else {
				for (int j = 0; j < 7; j++) {
					reset_brd(tmpboard, tetrisBoard);
					tmps = find_most_high_score(tmpboard, thisBlock, j, i);
					if (tmps > maxs) { maxi = i; maxj = j; maxs = tmps; }
				}
			}
		}
		(*location) = maxj; (*rotation) = maxi;
	}
	else if (thisBlock == 1) {
		int maxi, maxj;
		double maxs = -10000, tmps;
		for (int i = 0; i < 4; i++) {
			if (i == 0) {
				for (int j = 0; j < 8; j++) {
					reset_brd(tmpboard, tetrisBoard);
					tmps = find_most_high_score(tmpboard, thisBlock, j, i);
					if (tmps > maxs) { maxi = i; maxj = j; maxs = tmps; }
				}
			}
			else if(i == 1) {
				for (int j = 0; j < 9; j++) {
					reset_brd(tmpboard, tetrisBoard);
					tmps = find_most_high_score(tmpboard, thisBlock, j, i);
					if (tmps > maxs) { maxi = i; maxj = j; maxs = tmps; }
				}
			}
			else if (i == 2) {
				for (int j = 0; j < 8; j++) {
					reset_brd(tmpboard, tetrisBoard);
					tmps = find_most_high_score(tmpboard, thisBlock, j, i);
					if (tmps > maxs) { maxi = i; maxj = j; maxs = tmps; }
				}
			}
			else if (i == 3) {
				for (int j = 0; j < 9; j++) {
					reset_brd(tmpboard, tetrisBoard);
					tmps = find_most_high_score(tmpboard, thisBlock, j, i);
					if (tmps > maxs) { maxi = i; maxj = j; maxs = tmps; }
				}
			}
		}
		(*location) = maxj; (*rotation) = maxi;
	}
	else if (thisBlock == 2) {
		int maxi, maxj;
		double maxs = -10000, tmps;
		for (int i = 0; i < 4; i++) {
			if (i == 0) {
				for (int j = 0; j < 8; j++) {
					reset_brd(tmpboard, tetrisBoard);
					tmps = find_most_high_score(tmpboard, thisBlock, j, i);
					if (tmps > maxs) { maxi = i; maxj = j; maxs = tmps; }
				}
			}
			else if (i == 1) {
				for (int j = 0; j < 9; j++) {
					reset_brd(tmpboard, tetrisBoard);
					tmps = find_most_high_score(tmpboard, thisBlock, j, i);
					if (tmps > maxs) { maxi = i; maxj = j; maxs = tmps; }
				}
			}
			else if (i == 2) {
				for (int j = 0; j < 8; j++) {
					reset_brd(tmpboard, tetrisBoard);
					tmps = find_most_high_score(tmpboard, thisBlock, j, i);
					if (tmps > maxs) { maxi = i; maxj = j; maxs = tmps; }
				}
			}
			else if (i == 3) {
				for (int j = 0; j < 9; j++) {
					reset_brd(tmpboard, tetrisBoard);
					tmps = find_most_high_score(tmpboard, thisBlock, j, i);
					if (tmps > maxs) { maxi = i; maxj = j; maxs = tmps; }
				}
			}
		}
		(*location) = maxj; (*rotation) = maxi;
	}
	else if (thisBlock == 3) {
		int maxj;
		double maxs = -10000, tmps;
		for (int j = 0; j < 9; j++) {
			reset_brd(tmpboard, tetrisBoard);
			tmps = find_most_high_score(tmpboard, thisBlock, j, 0);
			if (tmps > maxs) { maxj = j; maxs = tmps; }
		}
		(*location) = maxj; (*rotation) = 0;
	}
	else if (thisBlock == 4) {
		int maxi, maxj;
		double maxs = -10000, tmps;
		for (int i = 0; i < 4; i++) {
			if (i == 0) {
				for (int j = 0; j < 8; j++) {
					reset_brd(tmpboard, tetrisBoard);
					tmps = find_most_high_score(tmpboard, thisBlock, j, i);
					if (tmps > maxs) { maxi = i; maxj = j; maxs = tmps; }
				}
			}
			else if (i == 1) {
				for (int j = 0; j < 9; j++) {
					reset_brd(tmpboard, tetrisBoard);
					tmps = find_most_high_score(tmpboard, thisBlock, j, i);
					if (tmps > maxs) { maxi = i; maxj = j; maxs = tmps; }
				}
			}
			else if (i == 2) {
				for (int j = 0; j < 8; j++) {
					reset_brd(tmpboard, tetrisBoard);
					tmps = find_most_high_score(tmpboard, thisBlock, j, i);
					if (tmps > maxs) { maxi = i; maxj = j; maxs = tmps; }
				}
			}
			else if (i == 3) {
				for (int j = 0; j < 9; j++) {
					reset_brd(tmpboard, tetrisBoard);
					tmps = find_most_high_score(tmpboard, thisBlock, j, i);
					if (tmps > maxs) { maxi = i; maxj = j; maxs = tmps; }
				}
			}
		}
		(*location) = maxj; (*rotation) = maxi;
	}
	else if (thisBlock == 5) {
		int maxi, maxj;
		double maxs = -10000, tmps;
		for (int i = 0; i < 4; i++) {
			if (i == 0) {
				for (int j = 0; j < 8; j++) {
					reset_brd(tmpboard, tetrisBoard);
					tmps = find_most_high_score(tmpboard, thisBlock, j, i);
					if (tmps > maxs) { maxi = i; maxj = j; maxs = tmps; }
				}
			}
			else if (i == 1) {
				for (int j = 0; j < 9; j++) {
					reset_brd(tmpboard, tetrisBoard);
					tmps = find_most_high_score(tmpboard, thisBlock, j, i);
					if (tmps > maxs) { maxi = i; maxj = j; maxs = tmps; }
				}
			}
			else if (i == 2) {
				for (int j = 0; j < 8; j++) {
					reset_brd(tmpboard, tetrisBoard);
					tmps = find_most_high_score(tmpboard, thisBlock, j, i);
					if (tmps > maxs) { maxi = i; maxj = j; maxs = tmps; }
				}
			}
			else if (i == 3) {
				for (int j = 0; j < 9; j++) {
					reset_brd(tmpboard, tetrisBoard);
					tmps = find_most_high_score(tmpboard, thisBlock, j, i);
					if (tmps > maxs) { maxi = i; maxj = j; maxs = tmps; }
				}
			}
		}
		(*location) = maxj;  (*rotation) = maxi;
	}
	else if (thisBlock == 6) {
		int maxi, maxj;
		double maxs = -10000, tmps;
		for (int i = 0; i < 4; i++) {
			if (i == 0) {
				for (int j = 0; j < 8; j++) {
					reset_brd(tmpboard, tetrisBoard);
					tmps = find_most_high_score(tmpboard, thisBlock, j, i);
					if (tmps > maxs) { maxi = i; maxj = j; maxs = tmps; }
				}
			}
			else if (i == 1) {
				for (int j = 0; j < 9; j++) {
					reset_brd(tmpboard, tetrisBoard);
					tmps = find_most_high_score(tmpboard, thisBlock, j, i);
					if (tmps > maxs) { maxi = i; maxj = j; maxs = tmps; }
				}
			}
			else if (i == 2) {
				for (int j = 0; j < 8; j++) {
					reset_brd(tmpboard, tetrisBoard);
					tmps = find_most_high_score(tmpboard, thisBlock, j, i);
					if (tmps > maxs) { maxi = i; maxj = j; maxs = tmps; }
				}
			}
			else if (i == 3) {
				for (int j = 0; j < 9; j++) {
					reset_brd(tmpboard, tetrisBoard);
					tmps = find_most_high_score(tmpboard, thisBlock, j, i);
					if (tmps > maxs) { maxi = i; maxj = j; maxs = tmps; }
				}
			}
		}
		(*location) = maxj;  (*rotation) = maxi;
	}
}