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

int sumNumbers(int *pNumbers, int nIndex){   
    if(nIndex <= 1){
        return *pNumbers;
    }
    else{
        *pNumbers+=sumNumbers(pNumbers+1, nIndex-1);
    }
}

int main(int argc, char* argv[]){

    FILE *fp1,*fp2;
    char str[64];   // change the number appropriately to your program
    // read_file = argv[1]
    // write_file = argv[2]

    // see the usage of r, rt, w, wt, r+, w+
    if((fp1 = fopen(argv[1], "r")) == NULL){    //fail to open file for read
        printf("fale to open file.");
        return 0;
    }
    if((fp2 = fopen(argv[2], "wt")) == NULL){   //fail to open file for write
        printf("fail to create file for write.");
        return 0;
    }

    int arr[101], cnt=0;

    while(fgets(str, sizeof(str), fp1)){   // read a file and write to another file line by line
        arr[cnt++]=atoi(str);
    }

    sumNumbers(&arr[1], arr[0]);
    
    for(int i=arr[0]; i>0; i--){
        char tmp[15];
        sprintf(tmp, "[%03d] %d\n", i, arr[i]);
        printf("%s", tmp);
        fputs(tmp, fp2);
    }

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
