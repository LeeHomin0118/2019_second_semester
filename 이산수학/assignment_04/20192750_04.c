#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>

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

int main(int argc, char* argv[]){

    FILE *fp;
    char str[100];   // change the number appropriately to your program

    // see the usage of r, rt, w, wt, r+, w+
    if((fp = fopen(argv[1], "r")) == NULL){ //fail to open file for read
        fp = fopen(argv[1], "w");
    }
    else{
        fp = fopen(argv[1], "w");   //기존 파일에 추가하고 싶으면 a로 바꾸면 된다.
    }
    
    int size_of_pow_set=pow(2, argc-2);
    int cnt=1;
    for(int i=0; i<size_of_pow_set; i++){
        char tmp[10];
        for(int i=0; i<100; i++){
            str[i]='\0';
        }
        fgets(str, 0, fp);
        sprintf(tmp, "[%04d] ", cnt);
        strcat(str, tmp);
        printf("[%04d] ", cnt);
        if(cnt==1){
            strcat(str, "\u00f8");
            printf("\u00f8");
        }
        cnt++;
        int chk=0;
        for(int j=0; j<argc-2; j++){
            if(i&(1<<j)){
                if(chk>0){
                    strcat(str, ", ");
                    printf(", ");
                }
                strcat(str, argv[j+2]);
                printf("%s", argv[j+2]);
                chk++;
            }
        }
        strcat(str, "\n");
        fputs(str, fp);
        printf("\n");
    }
    fgets(str, 0, fp);
    fputs("\n************************************************************\n", fp);
    fputs("309fa3077669836af00feb7174109b3eec1afb73\n", fp);
    fputs("its initial commit of discrete_assignment_04\n", fp);
    fputs("made by LeeHomin0118\n", fp);
    fputs("Name : LeeHomin\n", fp);
    fputs("student ID : 20192750\n", fp);
    fputs("************************************************************\n", fp);
    print_I();

    fclose(fp);
    return 0;
}
