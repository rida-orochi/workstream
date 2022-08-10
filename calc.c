#include<stdio.h>
float plus(float a, float b);
float minus(float a, float b);
float div(float a, float b);
float multi(float a, float b);
float selection(char i, float x, float y);
int main(){
    char O;
    float num1,num2,result;
    printf("please enter your first  number: ");
    scanf("%f",&num1);
    printf("please enter the operation you want to perform: ");
    scanf(" %c",&O);
    printf("\nplease enter your second number: ");
    scanf("%f",&num2);
    result= selection(O,num1,num2);
    printf("\n %.2f",result);
    return 0;
}
float selection(char i, float x, float y){
    if(i=='+'){return plus(x,y);}
    else if(i=='-'){return minus(x,y);}
    else if(i=='/'){return div(x,y);}
    else if(i=='*'){return multi(x,y);}
}
float plus(float a, float b){
    return a+b;
}
float minus(float a, float b){
    return a-b;
}
float div(float a, float b){
    if (b==0){
        printf("\n we can't devide by zero!!");
    }
    else{return a/b;}
}
float multi(float a, float b){
    return a*b;
}