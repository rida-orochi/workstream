
#include<stdio.h>
int prime(int x);
int main(){
    int num,result;
    printf("please enter a number: ");
    scanf(" %d", &num);
    result= prime(num);
    if (result== 777){
        printf("\n the number you enterd is odd!!");
    }
    else if (result== 666){
        printf("\n the number you enterd is prim!!");
    }
    printf("\n %d", result);
    return 0;
}
int prime(int x){
    int num2, holder,counter,result=0;
    num2=x;
    counter=1;
    while(x>2){
        holder=num2%(num2-counter);
        result+=num2%(num2-counter);
        printf("\n %d ", holder);
        counter++;
        x--;
        if (holder==0){
            return 777;
        }
    }return 666;
}