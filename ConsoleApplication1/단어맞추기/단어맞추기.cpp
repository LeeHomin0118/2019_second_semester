#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
using namespace std;
int main() {
	char tmpa[10], tmpb[10];
	printf("Word? ");
	scanf("%s", &tmpa);
	while (printf("Word? "), scanf("%s", &tmpb), strcmp(tmpb, "end")) {
		int alen, blen;
		alen = strlen(tmpa);
		blen = strlen(tmpb);
		int mka = -1, mkb = -1;
		printf("---%d %d---\n", mka, mkb);
		for (int j = 0; j < alen; j++) {
			bool ckbreak = false;
			for (int i = 0; i < blen; i++) {
				if (tmpa[i] == tmpb[j]) {
					mka = i;
					mkb = j;
					ckbreak = true;
					break;
				}
			}
			if (ckbreak) break;
		}
		printf("---%d %d---\n", mka, mkb);
		if (mka == -1 || mkb == -1) {
			printf("no cross word");
			strcpy(tmpa, tmpb);
		}
		else {
			for (int i = 0; i < alen; i++) {
				if (i == mka) {
					printf("(%c)", tmpa[i]);
				}
				else {
					printf("%c", tmpa[i]);
				}
			}
			printf(" - ");
			for (int i = 0; i < blen; i++) {
				if (i == mkb) {
					printf("(%c)", tmpb[i]);
				}
				else {
					printf("%c", tmpb[i]);
				}
			}
			strcpy(tmpa, tmpb);
		}
		printf("\n");
		mka = -1;
		mkb = -1;
	}
	return 0;
}