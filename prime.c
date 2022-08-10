#include<stdio.h>
int power(int x, int y);
int main(){
    int num1,num2, result;
    printf("please enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    printf("\n %d %d ", num1, num2);
    result=power(num1, num2);
    printf("\n %d", result);
    return 0;
}
int power(int x, int y){
    int holder=1;
    while(y>0){
        holder*=x;
        y--;
    }
    return holder;
}