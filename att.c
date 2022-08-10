#include<stdio.h>
int prime(int x);
int main(){
    int num,result;
    printf("please enter a number: ");
    scanf("%d",&num);
    result= prime(num);
    printf("\n %d", result);
    return 0;
}
int prime(int x){
    int holder,container,accumulator;
    holder=x;
    while(x>3){
        container=holder%(holder-(x-1));
        printf("\n %d ",container);
        accumulator+=holder%(holder-(x-1));
        printf("\n %d ",accumulator);
        if(container==0){
            break;
            return 777;
        }
        x--;
    }if (accumulator==0){
        return 111;
    }
}