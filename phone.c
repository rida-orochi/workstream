/*
Author: Rida Allah Jaija
Date: 08/07/2022
*/
#include <stdio.h>
#include <string.h>
int main()
{
//creating two dimentional array
    char grid[16][13];
//index of the last sentence entered by the user to sop the loop
    int index_marker;
//askingt the user for input
    printf("please enter a sentence in here: \n");
//nested loop to fill the two dimentional array
    for(int i=0;i<16;i++){
//getting user input
        fgets(grid[i],sizeof(grid[i]),stdin);
//break if the user stoped entering data
        if(grid[i][0]=='\n'){
            break;
        }
        index_marker=i;
    }
//loop to detect E in beginning of the sentence and replace it
    for(int i=0;i<16; i++){
        if(grid[i][0]=='E'){
            grid[i][0]=' ';
        }
// there is no need to check the whole array
        if(sizeof(grid[i])==0){
            break;
        }
    }
//printing the grid in form of characters
// there is no need to print the array if it is empty
    for(int i=0;i<index_marker;i++){
        for(int j=0;j<13;j++){
            printf("%c",grid[i][j]);
        }
    }
    return 0;
}