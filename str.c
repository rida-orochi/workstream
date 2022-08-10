#include<stdio.h>
#include<string.h>
int main(){
    char sentence[200];
    int number[26],holder;
    printf("please enter a sentence: ");
    fgets(sentence,sizeof(sentence),stdin);
    for(int i=0;i<200;i++){
        if(sentence[i]<'a'&&sentence[i]>='z'){
            for(int j=0;j<26;j++){
                if(sentence[i]=(97+j)){
                    number[j]+=1;
                }
            }
        }
    }
    for(int i=0;i<25;i++){
        if(number[i]>number[i+1]){
            holder=number[i];
        }
    }
    printf("\n%d",holder);
    return 0;
}