#include<stdio.h>
#include<string.h>
int main(){
    int n=456;
    int num;
    char thing[10]="hello";
    FILE*fptr;
    fptr=fopen("holder.txt","w");
    fprintf(fptr,"%d",n);
    fprintf(fptr,"%s",thing);
    fclose(fptr);
    printf("\nplease enter something: ");
    scanf("%d",&num);
    return 0;
}