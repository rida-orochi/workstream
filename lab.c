#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int max(int a, int b){
    if(a<=b){
        return b;
    }
    else if(b<a){
        return a;
    }
}
int main(){
    printf("%d",max(15,9));
    return 0;
}