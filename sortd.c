#include<stdio.h>
#include<string.h>
int main(){
    int counter=0;
    printf("please enter a sentence: ");
    char str[100];
    fgets(str,sizeof(str) ,stdin);
    printf("\n %s", str);
    for(int i=0; i< (strlen(str)-2);i++){
        if((str[i])>64&&(str[i])<91){
            counter+=1;
        }
        else if(((str[i])>96&&(str[i])<123)){
            counter+=1;
        }
    }
    printf("\n %d", counter);
    printf("\n %d", (strlen(str)-2));
    if(counter==sizeof(str)){
        printf("\n string made only of alphabetic characters");
    }else{printf("\n string is not made only of alphabetic characters");}
    return 0;
}