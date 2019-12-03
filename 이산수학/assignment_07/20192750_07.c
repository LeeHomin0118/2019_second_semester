#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define SWAP(a, b, t){t=a; a=b; b=t;}
void print_I(){
    printf("\n************************************************************\n");
    printf("02f375aba0dda3d768a2efb984a6492381dd03da\n");
    printf("its initial commit of discrete_assignment_03\n");
    printf("made by LeeHomin0118\n");
    printf("Name : LeeHomin\n");
    printf("student ID : 20192750\n");
    printf("************************************************************\n\n");
    printf("ooooo                               ooooo   ooooo                              o8o\n`888'                               `888'   `888'                              `\"'\n 888          .ooooo.   .ooooo.      888     888   .ooooo.  ooo. .oo.  .oo.   oooo  ooo. .oo.\n 888         d88' `88b d88' `88b     888ooooo888  d88' `88b `888P\"Y88bP\"Y88b  `888  `888P\"Y88b\n 888         888ooo888 888ooo888     888     888  888   888  888   888   888   888   888   888\n 888       o 888    .o 888    .o     888     888  888   888  888   888   888   888   888   888\no888ooooood8 `Y8bod8P' `Y8bod8P'    o888o   o888o `Y8bod8P' o888o o888o o888o o888o o888o o888o\n");
}

char *arr[50000];
int cnt[50000]={0};

int main(int argc, char* argv[]){

    FILE *fp1,*fp2;
    char str[2600];

    if((fp1 = fopen(argv[1], "r")) == NULL){    //fail to open file for read
        printf("fale to open file.");
        return 0;
    }
    if((fp2 = fopen(argv[2], "wt")) == NULL){   //fail to open file for write
        printf("fail to create file for write.");
        return 0;
    }

    int arrlen=0;
    int max=100000;
    int sum=0;
    const char delimiters[]=" \n,.\?/\\\"\';:()[]{}_-+=`~!@#$%%^&*<>|\t";
    
    while(fgets(str, sizeof(str), fp1)){   // read a file and write to another file line by line
        //printf("%s\n", str);
        char *token = strtok(str, delimiters);
        while(token!=NULL){
            sum++;
            strlwr(token);
            //printf("%s\n", token);
            int flag=1;
            for(int i=0; i<arrlen; i++){
                if(!strcmp(token, arr[i])){
                    //printf("+++\n");
                    cnt[i]++;
                    flag=0;
                    break;
                }
            }
            if(flag){
                int len=strlen(token)+1;
                //printf("%d / len\n", len);
                char *newptr=(char*)malloc(sizeof(char)*len);
                strcpy(newptr, token);
                arr[arrlen]=newptr;
                cnt[arrlen]++;
                arrlen++;
            }
            
            token=strtok(NULL, delimiters);
        }
    }

    for(int i=0; i<arrlen; i++){
        char tmp[100];
        /*
        for(int j=0; j<strlen(arr[i]); j++){
            if(!((arr[i][j]>=48&&arr[i][j]<=57)||(arr[i][j]>=97&&arr[i][j]<=122))){
                sprintf(tmp, "error : %s (%d)\n", arr[i], i);
                fputs(tmp, fp2);
                printf("error : %d / %s\n", i, arr[i]);
            }
        }
        */
        sprintf(tmp, "[%05d] %s (%d)\n", i+1, arr[i], cnt[i]);
        fputs(tmp, fp2);
        printf("[%05d] %s (%d)\n", i+1, arr[i], cnt[i]);
    }
    char tmp[100];
    sprintf(tmp, "[total] %d\n", sum);
    fputs(tmp, fp2);
    printf("[total] %d\n", sum);
    
    fgets(str, 0, fp2);
    fputs("************************************************************\n", fp2);
    fputs("made by LeeHomin0118\n", fp2);
    fputs("Name : LeeHomin\n", fp2);
    fputs("student ID : 20192750\n", fp2);
    fputs("************************************************************\n", fp2);
    fputs("ooooo                               ooooo   ooooo                              o8o\n`888'                               `888'   `888'                              `\"'\n 888          .ooooo.   .ooooo.      888     888   .ooooo.  ooo. .oo.  .oo.   oooo  ooo. .oo.\n 888         d88' `88b d88' `88b     888ooooo888  d88' `88b `888P\"Y88bP\"Y88b  `888  `888P\"Y88b\n 888         888ooo888 888ooo888     888     888  888   888  888   888   888   888   888   888\n 888       o 888    .o 888    .o     888     888  888   888  888   888   888   888   888   888\no888ooooood8 `Y8bod8P' `Y8bod8P'    o888o   o888o `Y8bod8P' o888o o888o o888o o888o o888o o888o\n", fp2);
    print_I();

    fclose(fp1);
    fclose(fp2);
    return 0;
}
