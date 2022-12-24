/*
Authorship: Rida Allah Jaija,
Purpose: Retrieving determined record from a binary file 
date: september 27, 2022
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct 
{
    char entrance[8];
    char back_door[8];
    int num;
}reader;
reader phrase[10];
int main(){
    FILE*fptr;
    if((fptr=fopen("98003.bin","rb"))==NULL){
        printf("error");
        return 0;
    }
    fseek(fptr,0,SEEK_SET);
    for(int i=0;i<=11;i++){
        fread(phrase->entrance,8,1,fptr);// we are using the array notation cause fread take pointer as parameter that's why we got to use the address symbole to read the number written in binary 
        fread(phrase->back_door,8,1,fptr);
        fread(&(phrase->num),4,1,fptr);
        if(i==9){
            printf("-First string: %s\n-Second string: %s\n-An integer: %d",phrase->entrance,phrase->back_door,phrase->num);
        }
    }
    fclose(fptr);
    return 0;
}
/*
freed(&rec,sizeof(record),1,fptr)
what does rec refer to

rec is just one element record is the struct definition 
record is just to get the size of the struct to read based on 
rec is a single place to store it 
well he just created one and used it there is no array

que fifo
stack lifo

char*seller
char sellet[30]
nested struct

pointers with struct








order* neworder(char*name){
    Ordor*order=(order*)malloc(sizeof(Order));
    strcpy(order->name,name);
    order->ordersize=0;
    return 0;
}

















*/