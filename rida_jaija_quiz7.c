#include<stdio.h>
#include<string.h>
/*
Authorship: Rida ALlah Jaija
Date: 14/07/2022
Purpose: allows users to enter text and then automatically count how many times and count the occurence of A U I lower or upper case
*/
int main(){
    char text[200];
    int A=0,U=0,I=0;
    printf("please enter a text in the provided space: ");
    fgets(text,sizeof(text),stdin);
    for(int i=0;i<200;i++){
        if(text[i]=='a'||text[i]=='A'){
            A++;
        }else if(text[i]=='u'||text[i]=='U'){
            U++;
        }else if(text[i]=='i'||text[i]=='I'){
            I++;
        }
    }
    printf("\nthe text you have entered contain %d A, %d U, %d I.",A,U,I);
    return 0;
}