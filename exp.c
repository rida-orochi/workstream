#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 5
int main(){
    int matrix[5][5];
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            matrix[i][j]=1;
        }
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            printf("%d",matrix[i][j]);
        }
        printf("\n");
    }
    int new_matrix[10][10];
    int**temp=matrix;
    matrix=(&new_matrix);
    return 0;
}
