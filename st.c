#include<stdio.h>
#include<string.h>
int main(){
    char sentence[10];
    printf("print somthing");
    fgets(sentence,sizeof(sentence),stdin);
    printf("\n %s",sentence);
    return 0;
}