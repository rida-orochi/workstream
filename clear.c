#include<stdio.h>
#include<string.h>
int main(){
    char email[30];
    char password[20];
    char membership[10];
    short paid;
    char variable[130];
    FILE*reference;
    reference=fopen("note1-1.txt","r");
    char* piece=strtok(variable," ");
    while(fgets(variable,sizeof(variable),reference)){
        char* piece=strtok(variable," ");
        printf("\n%s",piece);
        piece=strtok(NULL," ");
        printf("--%s",piece);
        piece=strtok(NULL," ");
        printf("--%s",piece);
        piece=strtok(NULL," ");
        printf("--%s",piece);
    }
    fclose(reference);



    return 0;
}