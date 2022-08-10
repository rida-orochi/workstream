#include<stdio.h>
int main(){
    int arr[50];
    for (int i=0;i<50;i++){
        arr[i]=i+12;
    }
    for(int j=0;j<50; j++){
        printf("\t %d", arr[j]);
    }
    return 0;
}