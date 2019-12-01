#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef unsigned int uint;
typedef unsigned short ushort;

#pragma pack(push, 1)
typedef struct LOCAL_FILE_HEADER {
	uint signature;
	ushort ver;
	ushort bitflag;
	ushort comp_method;
	ushort last_mod_time;
	ushort last_mod_date;
	uint crc_32;
	uint comp_size;
	uint uncomp_size;
	ushort name_len;
	ushort ex_len;
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
	while (1) {
		local_header tmp;
		fread(&tmp, sizeof(tmp), 1, fp1);
		if (tmp.signature != 0x04034b50) {
			printf("%d %d\n", cnt - 1, size_of_all_file);
			break;
		}
		char *file_name = (char*)malloc(tmp.name_len + 1);
		char *ex_data = (char*)malloc(tmp.ex_len);
		fread(file_name, 1, tmp.name_len, fp1);
		file_name[tmp.name_len] = NULL;
		printf("%d. %s %d \n", cnt++, file_name, tmp.uncomp_size);
		size_of_all_file += tmp.uncomp_size;
	}
	fclose(fp1);
	char *key[34] = { 
		"auto", 
		"break", 
		"case", 
		"char", 
		"const", 
		"continue", 
		"default", 
		"do", 
		"double", 
		"else", 
		"enum", 
		"extern", 
		"float", 
		"for", 
		"goto", 
		"if", 
		"inline", 
		"int", 
		"long", 
		"register", 
		"restrict", 
		"return", 
		"short", 
		"signed", 
		"sizeof", 
		"static", 
		"struct", 
		"switch", 
		"typedef", 
		"union", 
		"unsigned", 
		"void", 
		"volatile", 
		"while", 
	};
}