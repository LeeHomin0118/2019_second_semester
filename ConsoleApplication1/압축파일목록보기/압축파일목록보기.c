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
typedef struct LOCAL_FILE_HEADER {
	ui signature;
	us ver;
	us bitflag;
	us comp_method;
	us last_mod_time;
	us last_mod_date;
	ui crc_32;
	ui comp_size;
	ui uncomp_size;
	us name_len;
	us ex_len;
} local_header;
#pragma pack(pop)

int main(int argc, char* argv[]) {
	FILE *fp1 = fopen("file.zip", "r");
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
	while (!feof(fp1)) {
		central_header tmp;
		fread(&tmp, 1, sizeof(tmp), fp1);
		if (tmp.signature != 0x02014b50) {
			if (size_of_all_file < 1000) {
				printf("-모두 %d개의 파일(%d B) 입니다.\n", cnt - 1, size_of_all_file);
			}
			else {
				printf("-모두 %d개의 파일(%d KB) 입니다.\n", cnt - 1, size_of_all_file/1000);
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
			printf("%d. %s %d Kbytes\n", cnt++, file_name, tmp.uncompsize/1000);
		}
		size_of_all_file += tmp.uncompsize;
		free(file_name);
		free(ex_data);
		free(comment);
	}
	/*
	이 코드는 로컬 헤더들 사이에 있는 데이터들의 값을 고려하지 못했음
	while (1) {
		local_header tmp;
		fread(&tmp, 1, sizeof(tmp), fp1);
		if (tmp.signature != 0x04034b50) {
			printf("-모두 %d개의 파일(%d) 입니다.\n", cnt - 1, size_of_all_file);
			break;
		}
		//파일 이름과 추가항목의 길이가 있는데 읽지 않으면 다음 시그니처를 읽을 때 값이 달라 오류가 날 수 있음.
		char *file_name = (char*)malloc(tmp.name_len + 1);
		char *ex_data = (char*)malloc(tmp.ex_len);
		char *data = (char*)malloc(tmp.comp_size);
		fread(file_name, 1, tmp.name_len, fp1);
		fread(ex_data, 1, tmp.ex_len, fp1);
		file_name[tmp.name_len] = NULL;
		printf("%d. %s %d\n", cnt++, file_name, tmp.uncomp_size);
		size_of_all_file += tmp.uncomp_size;
	}
	*/
	fclose(fp1);
}