#include<stdio.h>
#include<string.h>
int main(){
    char sentence[200];
    char sentence2[200];
    printf("please enter a sentence: ");
    fgets(sentence,sizeof(sentence),stdin);
    strcpy(sentence,sentence2);
    printf("\n%s",sentence2);
    strrev(sentence2);
    printf("\n%s",sentence);
    if(strcmp(sentence, sentence2)==0){
        printf("\n yeah it's true");
    }else if(strcmp(sentence, sentence2)!=0){
        printf("\n yeah it's false");
    }
    return 0;
}