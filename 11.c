#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int show(int elem[]);
void main(){
    int num[23];
    num[1]=123;
    show(num);
}
int show(int elem[]){
    printf("hello there first number %d",elem[1]);
    return 0;
}