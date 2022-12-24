#include<stdio.h>

int fact(int numb){
    if(numb==1){// the condition to break the loop
        return 1;
    }
    else{
        return numb*fact(numb-1);
    }
}
int main(){
    int num=6;
    fact(num);
    printf("%d",fact(num));
    return 0;
}
essay review                 