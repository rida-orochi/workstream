#include<stdio.h>
#include<string.h>
int main(){
    char string[5]="hllo";
    for(int i=0;i<7;i++){
        printf("\n hellow count");
        printf("%d",i);
        if(string[i]=='\0'){
            break;
        }
    }
    return 0;
}