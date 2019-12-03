#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
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

FILE *fp1,*fp2;
char str[64];
int allcnt=1, N;

void move_end(char *arr, int b, int e){
    char tmp=arr[e];
    for(int i=e; i>b; i--) arr[i]=arr[i-1];
    arr[b]=tmp;
}

void move_begin(char *arr, int b, int e){
    char tmp=arr[b];
    for(int i=b; i<e; i++) arr[i]=arr[i+1];
    arr[e]=tmp;
}

void permutation(char *arr, int n){
    if(n==N){
        char tmp[6];
        sprintf(tmp, "[%03d] ", allcnt);
        fputs(tmp, fp2);
        printf("[%03d] ", allcnt);
        for(int i=1; i<=N; i++){
            sprintf(tmp, "%c ", arr[i]);
            fputs(tmp, fp2);
            printf("%c ", arr[i]);
        }
        fputs("\n", fp2);
        printf("\n");
        allcnt++;
        return;
    }
    for(int i=n; i<=N; i++){
        char tmp;
        move_end(arr, n, i);
        permutation(arr, n+1);
        move_begin(arr, n, i);
    }
}

int main(int argc, char* argv[]){

    if((fp1 = fopen(argv[1], "r")) == NULL){    //fail to open file for read
        printf("fale to open file.");
        return 0;
    }
    if((fp2 = fopen(argv[2], "wt")) == NULL){   //fail to open file for write
        printf("fail to create file for write.");
        return 0;
    }

    char arr[50];
    int cnt=0;

    while(fgets(str, sizeof(str), fp1)){   // read a file and write to another file line by line
        arr[cnt++]=str[0];
        if(cnt==arr[0]-'0'+1) break;
    }

    N=arr[0]-'0';
    fgets(str, 0, fp2);
    permutation(arr, 1);

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
