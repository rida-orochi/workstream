#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct tree
{// here he created the nodes for the tree
    char question[90];//value 1
    char animal[15];//value 2
    Tree *yes, *no;//the pointers to the right and left child nodes 
};
//{{"", "Does it have wings", 1, 2}, {"stork", "", 0, 0}, {"lion", "", 0, 0}};//here he is trying to explain stuff
Tree *newTree()//what does this part do 
{
    Tree *root = (Tree *)malloc(sizeof(Tree));
    Tree *yes, *no;
    strcpy(root->question, "Does it have wings");
    strcpy(root->animal, "");
    root->yes = yes = (Tree *)malloc(sizeof(Tree));
    strcpy(yes->question, "");
    strcpy(yes->animal, "stork");
    yes->yes = NULL;
    yes->no = NULL;
    root->no = no = (Tree *)malloc(sizeof(Tree));
    strcpy(no->question, "");
    strcpy(no->animal, "lion");
    no->yes = NULL;
    no->no = NULL;
    return root;//this one returns the root that's why he created the function as a pointer 
}
Tree *play(Tree *root)
{
    char answer[10];//this is just a holder for the user's answer   
//this was a way to say that there is no question in that place holder
    if (root->question[0] == 0)
    {
        printf("Is your animal a(n) %s?", root->animal);//we just ask the fucking question
//we always have the following format {{"", "Does it have wings", 1, 2}, {"stork", "", 0, 0}, {"lion", "", 0, 0}};
// the way we created the game was that we only initiated it the first index have no animal that's why we ask from the second
        scanf("%s", answer);//=>that answer that upon which we will be acting 
//if the answer we got from the player was correct from the first time we directly quit cause the game is over and we ask the user if he wanna play again
        if (answer[0] == 'y')
        {
            printf("Thanks for playing!\n");
            return root;
        }//for this part there will be no use of trees 
//^this is the simplest conclusion and the shortest path the player guessed correctly from the first time
        else
        {
//carefully notice that part, cause from here we start extending the tree 
//we are now creating new node that will be considered as sub tree on it own so we will give it root a name 
            Tree *temp = root;//i don't understand this moove 
            Tree *question = (Tree *)malloc(sizeof(Tree));
            Tree *newLeaf = (Tree *)malloc(sizeof(Tree));
            printf("What is your animal? ");
            scanf("%s", newLeaf->animal);
            getchar();//to avoid scanning the line return 
            printf("Please tell me a question that distinguishes a %s from a % s: ",newLeaf->animal,root->animal);
            gets(question->question);
            printf("Is the answer 'yes' for a %s? ", newLeaf->animal);
            scanf("%s", answer);
            if (answer[0] == 'y')
            {
                question->yes = newLeaf;
                question->no = root;//what does he mean by this part
            }
            else
            {
                question->yes = root;
                question->no = newLeaf;
            }
            newLeaf->yes = NULL;
            newLeaf->no = NULL;
            strcpy(question->animal, "");
            strcpy(newLeaf->question, "");
            return question;
        }
        // guess!
    }
    else
    { // ask question
        printf("%s? ", root->question);
        scanf("%s", answer);
        if (answer[0] == 'y')
            return root->yes = play(root->yes);
        else
            return root->no = play(root->no);
    }
}