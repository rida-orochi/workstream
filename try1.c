#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    //variable initialisation
    char sentence[22]={"the need for sentence"};
    //file creation
    FILE*fptr;
    fptr=fopen("hat.bin","Wb");
    fclose(fptr);
    return 0;
}