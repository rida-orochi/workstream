#include "tree.h"
#include <stdio.h>
void  main() {
//he create a tree called animalgame in here 
//he is just giving a name in here 
Tree *animalgame;//new tree return a pointer that's why he made it as a pointer
char answer[10];// this is just a holder for the question "do you wanna play again"
animalgame = newTree();//the one above was just a pointer now it's officially created a new tree
//under this line is a simple loop to keep the game going until that the player decides to quit 
do {
play(animalgame);
printf("Play again? ");
scanf("%s", answer);
}
while(answer[0] == 'y');
}