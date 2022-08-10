#include<stdio.h>
int prime(int x);
int main(){
    int num;
    printf("please enter a number: ");
    scanf("%d", &num);
    printf("\n%d ",prime(num));
    return 0;
}
int prime(int x){
    float holder;
    int counter;
    counter=x;
    while(counter>=3){
        holder=(x%(counter-1));
        counter--;
        printf("\n %.2f  %d", holder,(counter-1));
        if (holder==0){
            break;
            return 0;
        }
    }
    return 1;
}