#include<stdio.h>
int thing();
int main(){
    printf("i need you to work");
    int num;
    int arr[10];
    for(int i=0; i<10;i++){
        arr[i]=12+i;
    }
    num=5;
    num=thing();
    return 0;
}
int thing(){
    printf("\n hello again");
    return 11;
}