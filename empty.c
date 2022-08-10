#include<stdio.h>
#include<string.h>
int main(){
    char thing[2][7];
    fgets(thing[0],sizeof(thing[0]),stdin);
    getchar();
    fgets(thing[1],sizeof(thing[1]),stdin);
    printf("_____________________");
    printf("\n_____________________");
    for(int i=0;i<2;i++){
        for(int j=0;j<7;j++){
            if(j==6){
                continue;
            }
            printf("\n%c",thing[i][j]);
            
        }
    }
    return 0;
}