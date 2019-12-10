#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef unsigned int ui;
typedef unsigned short us;

#pragma pack(push, 1)
typedef struct END_FILE_HEADER {
	us num;
	us start;
	us rec_cnt;
	us tot_rec_cnt;
	ui central_size;
	ui offset;
	us comt_len;
} end_header;
typedef struct CENTRAL_FILE_HEADER {
	ui signature;
	us vern;
	us verm;
	us flag;
	us method;
	us tiem;
	us date;
	ui crc;
	ui compsize;
	ui uncompsize;
	us namelen;
	us exlen;
	us comtlen;
	us start;
	us ia;
	ui ea;
	ui ro;
} central_header;
#pragma pack(pop)

int main(int argc, char* argv[]) {
	FILE *fp1 = fopen(argv[1], "r");
	if (fp1 == NULL) {
		printf("fale to open file.");
		return 0;
	}
	int cnt = 1;
	int size_of_all_file = 0;
	end_header endh;
	ui sig = 0;
	int move = 0;
	while (1) {
		fseek(fp1, -move++, SEEK_END);
		fread(&sig, 1, sizeof(sig), fp1);
		if (sig == 0x06054b50) {
			fread(&endh, 1, sizeof(end_header), fp1);
			break;
		}
	}
	fseek(fp1, endh.offset, SEEK_SET);
	printf("file.zip 안에 포함된 파일은 다음과 같습니다.\n");
	while (!feof(fp1)) {
		central_header tmp;
		fread(&tmp, 1, sizeof(tmp), fp1);
		if (tmp.signature != 0x02014b50) {
			if (size_of_all_file < 1000) {
				printf("-모두 %d개의 파일(%d B) 입니다.\n", cnt - 1, size_of_all_file);
			}
			else {
				printf("-모두 %d개의 파일(%d KB) 입니다.\n", cnt - 1, size_of_all_file / 1000);
			}
			break;
		}
		char *file_name = (char*)malloc(tmp.namelen + 1);
		char *ex_data = (char*)malloc(tmp.exlen);
		char *comment = (char*)malloc(tmp.comtlen);
		fread(file_name, 1, tmp.namelen, fp1);
		fread(ex_data, 1, tmp.exlen, fp1);
		fread(comment, 1, tmp.comtlen, fp1);
		file_name[tmp.namelen] = NULL;
		if (tmp.uncompsize < 1000) {
			printf("%d. %s %d Bytes\n", cnt++, file_name, tmp.uncompsize);
		}
		else {
			printf("%d. %s %d Kbytes\n", cnt++, file_name, tmp.uncompsize / 1000);
		}
		size_of_all_file += tmp.uncompsize;
		free(file_name);
		free(ex_data);
		free(comment);
	}
	fclose(fp1);
}