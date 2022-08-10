#include<stdio.h>
#include<string.h>
void display(char game[][4]);
void mooves(char thing[][4]);
int main(){
    char game[3][4];
    for(int i=0;i<3;i++){
        strcpy(game[i],"   ");
    }
    display(game);
    mooves(game);
    display(game);
    return 0;
}
void display(char game[][4]){
    printf("\t\t\t\t _ _ _\n");
    for(int i=0;i<3;i++){
        printf("\t\t\t\t");
        for(int j=0;j<3;j++){
            printf("|%c",game[i][j]);
        }
        printf("|");
        printf("\n\t\t\t\t _ _ _\n");
    }
}
void mooves(char thing[][4]){
    int turn=1,selection,position1,position2,state;
    for(int i=0;i<9;i++){
        printf("player%d please make you moove: ",turn);
        scanf("%d",&selection);
        selection--;
        position1=selection/3;
        if(selection<3){
            position2=selection;
        }else if(selection>2){
            position2=selection%3;
        }
        if(turn==1){
            *(*(thing+position1)+position2)='X';
        }else if(turn==2){
            *(*(thing+position1)+position2)='O';
        }
        switch (turn)
        {
        case 1:
            turn++;
            break;
        
        case 2:
            turn--;
            break;
        }
        if(*(*(thing+0)+0)=='X'&&*(*(thing+0)+1)=='X'&&*(*(thing+0)+2)=='X'){
            *(*(thing+0)+0)='-';
            *(*(thing+0)+1)='-';
            *(*(thing+0)+2)='-';
            printf("\nplayer 1 wins!!!\n");
            break;
        }else if(*(*(thing+1)+0)=='X'&&*(*(thing+1)+1)=='X'&&*(*(thing+1)+2)=='X'){
            *(*(thing+0)+0)='-';
            *(*(thing+0)+1)='-';
            *(*(thing+0)+2)='-';
            printf("\nplayer 1 wins!!!\n");
            break;
        }else if(*(*(thing+2)+0)=='X'&&*(*(thing+2)+1)=='X'&&*(*(thing+2)+2)=='X'){
            *(*(thing+0)+0)='-';
            *(*(thing+0)+1)='-';
            *(*(thing+0)+2)='-';
            printf("\nplayer 1 wins!!!\n");
            break;
        }else if(*(*(thing+0)+2)=='X'&&*(*(thing+1)+2)=='X'&&*(*(thing+2)+2)=='X'){
            *(*(thing+0)+0)='|';
            *(*(thing+0)+1)='|';
            *(*(thing+0)+2)='|';
            printf("\nplayer 1 wins!!!\n");
            break;
        }else if(*(*(thing+0)+3)=='X'&&*(*(thing+1)+3)=='X'&&*(*(thing+2)+3)=='X'){
            *(*(thing+0)+0)='|';
            *(*(thing+0)+1)='|';
            *(*(thing+0)+2)='|';
            printf("\nplayer 1 wins!!!\n");
            break;
        }else if(*(*(thing+0)+0)=='X'&&*(*(thing+1)+0)=='X'&&*(*(thing+2)+0)=='X'){
            *(*(thing+0)+0)='|';
            *(*(thing+0)+1)='|';
            *(*(thing+0)+2)='|';
            printf("\nplayer 1 wins!!!\n");
            break;
        }else if(*(*(thing+0)+0)=='X'&&*(*(thing+1)+2)=='X'&&*(*(thing+2)+2)=='X'){
            *(*(thing+0)+0)='/';
            *(*(thing+0)+1)='/';
            *(*(thing+0)+2)='/';
            printf("\nplayer 1 wins!!!\n");
            break;
        }else if(*(*(thing+0)+2)=='X'&&*(*(thing+1)+2)=='X'&&*(*(thing+2)+0)=='X'){
            *(*(thing+0)+0)='/';
            *(*(thing+0)+1)='/';
            *(*(thing+0)+2)='/';
            printf("\nplayer 1 wins!!!\n");
            break;
        }
        if(*(*(thing+0)+0)=='O'&&*(*(thing+0)+1)=='O'&&*(*(thing+0)+2)=='O'){
            *(*(thing+0)+0)='-';
            *(*(thing+0)+1)='-';
            *(*(thing+0)+2)='-';
            printf("\nplayer 1 wins!!!\n");
            break;
        }else if(*(*(thing+1)+0)=='O'&&*(*(thing+1)+1)=='O'&&*(*(thing+1)+2)=='O'){
            *(*(thing+0)+0)='-';
            *(*(thing+0)+1)='-';
            *(*(thing+0)+2)='-';
            printf("\nplayer 1 wins!!!\n");
            break;
        }else if(*(*(thing+2)+0)=='O'&&*(*(thing+2)+1)=='O'&&*(*(thing+2)+2)=='O'){
            *(*(thing+0)+0)='-';
            *(*(thing+0)+1)='-';
            *(*(thing+0)+2)='-';
            printf("\nplayer 1 wins!!!\n");
            break;
        }else if(*(*(thing+0)+2)=='O'&&*(*(thing+1)+2)=='O'&&*(*(thing+2)+2)=='O'){
            *(*(thing+0)+0)='|';
            *(*(thing+0)+1)='|';
            *(*(thing+0)+2)='|';
            printf("\nplayer 1 wins!!!\n");
            break;
        }else if(*(*(thing+0)+3)=='O'&&*(*(thing+1)+3)=='O'&&*(*(thing+2)+3)=='O'){
            *(*(thing+0)+0)='|';
            *(*(thing+0)+1)='|';
            *(*(thing+0)+2)='|';
            printf("\nplayer 1 wins!!!\n");
            break;
        }else if(*(*(thing+0)+0)=='O'&&*(*(thing+1)+0)=='O'&&*(*(thing+2)+0)=='O'){
            *(*(thing+0)+0)='|';
            *(*(thing+0)+1)='|';
            *(*(thing+0)+2)='|';
            printf("\nplayer 1 wins!!!\n");
            break;
        }else if(*(*(thing+0)+0)=='O'&&*(*(thing+1)+2)=='O'&&*(*(thing+2)+2)=='O'){
            *(*(thing+0)+0)='/';
            *(*(thing+0)+1)='/';
            *(*(thing+0)+2)='/';
            printf("\nplayer 1 wins!!!\n");
            break;
        }else if(*(*(thing+0)+2)=='O'&&*(*(thing+1)+2)=='O'&&*(*(thing+2)+0)=='O'){
            *(*(thing+0)+0)='/';
            *(*(thing+0)+1)='/';
            *(*(thing+0)+2)='/';
            printf("\nplayer 1 wins!!!\n");
            break;
        }
        display(thing);
    }
    
}