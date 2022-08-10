#include<stdio.h>
#include<string.h>
int main(){
    char holder[20];
    printf("please enter a text: ");
    fgets(holder,sizeof(holder),stdin);
    printf("\n%s",holder);
    char holder2[20];
    printf("please enter a text: ");
    fgets(holder2,sizeof(holder2),stdin);
    printf("\n%s",holder2);
    return 0;
}