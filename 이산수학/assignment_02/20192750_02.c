#include <stdio.h>
#include <stdlib.h>
void print_I(){
    printf("************************************************************\n");
    printf("4008db57ef6a1ea24b6581583b267fe058877fa1\n");
    printf("its initial commit of discrete_assignment_01\n");
    printf("made by LeeHomin0118\n");
    printf("student ID : 20192750\n");
    printf("************************************************************\n");
}
int main(int argc, char* argv[]){
    if(argc>202){
        printf("The maximum number of (symbol, number) pairs is over 100\n");
        print_I();
        return 0;
    }
    int sum=0;
    for(int i=1; i<argc; i+=2){
        if(argv[i][0]==43) sum+=atoi(argv[i+1]);
        else if(argv[i][0]==45) sum-=atoi(argv[i+1]);
    }
    printf("%d\n", sum);
    print_I();
    return 0;
}
