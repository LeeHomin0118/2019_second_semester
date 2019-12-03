#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
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
    int size_of_pow_set=pow(2, argc-1);
    int cnt=1;
    for(int i=0; i<size_of_pow_set; i++){
        printf("[%04d] ", cnt);
        if(cnt==1){
            printf("\u00f8");
        }
        cnt++;
        int chk=0;
        for(int j=0; j<argc-1; j++){
            if(i&(1<<j)){
                if(chk>0){
                    printf(", ");
                }
                printf("%s", argv[j+1]);
                chk++;
            }
        }
        printf("\n");
    }
    print_I();
    return 0;
}
