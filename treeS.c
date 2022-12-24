#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
// struct declaration
struct node
{
    int value;
    struct  node *right;
    struct node *left;
};
typedef struct node Tnode;
// creating nodes
Tnode *create(int X)
{
    Tnode *newE = (Tnode *)malloc(sizeof(Tnode));
    newE->value = X;
    newE->right = NULL;
    newE->left = NULL;
    return newE;
}
//linking element to shape a binary tree
Tnode *Insert(Tnode *root, int data)
{
    if (root == NULL)
    {
        root = create(data);
        return root;
    } // we are inserting in each part that's why we need to give it root->left or root->right
    else if (root->value >= data)
    {
        root->left = Insert(root->left, data);
        return root;
    }
    else if (root->value < data)
    {
        root->right = Insert(root->right, data);
        return root;
    }
}
// [printing a list tree]
void printT(Tnode *root)
{
    if (root == NULL)
    {
        printf("\n---<Not found>---");
    }
    else
    {
        printf("\n%d", root->value);
        printT(root->right);
        printT(root->left);
    }
}
//---[attempt to print a tree that look like a real one]
//notes regarding the methode used to print the tree in a close format to a tree 
//the more you call the functions again you add new indentation before printing the element 
//mening that elements of the same lvl wil be called with the same level of indentation taking that they when they are called they need to go trough the same number of incrementation 
//notice that the function does not return anything and that's exactly what makes nodes from the same level have the same lvl of indentation 
//the lvl does not increment
//the one i used was a way to print a tree in the shape of a list
void printTree(Tnode*root, int indent)
{
    if (root == NULL)
    {
        for (int i = 0; i < indent; i++){printf(" ");}
        printf("-\n");
    }
    else
    {
        for (int i = 0; i < indent; i++){printf(" ");}
        printf("%d",root->value);
        printf("\n");
        printTree(root->right, indent + 4);
        printTree(root->left, indent + 4);
    }
}
//---[searching a tree]
//can also be used for counting the occurence of the element in a tree with a small change
// I can write a code that allow me to search a binary list it ain't that complecated
Tnode* searchT(Tnode *root, int elem)
{
    // all i need to do is to take care of all the cases
    // notice how those two <True> & <False> are only used once and they will be an outcome of the function
    if (root == NULL)
    {
        printf("give me a real tree, m not playing in here!!!");
    }
    else if (root->value == elem)
    {
        printf("\n%d", root->value);
        return root;
    }
    else if (root->value >= elem)
    {
        printf("\nwe are now looking in the left side please stand by :)\n");
        searchT(root->left, elem);
    }
    else if (root->value < elem)
    {
        printf("\nwe are now looking in the right side please stand by :)\n");
        searchT(root->right, elem);
    }
}
//---[searching for the minimum value in a tree]---
Tnode *findMin(Tnode *root)
{
    if (root == NULL)
    {
        return root;
    }
    else if (root->left == NULL)
    {
        return root;
    }
    findMin(root->left);
}
//---[maximum value in a tree]
// same will be applied to that side but we will be looking for max instead
// in here we will be having two stoping conditions based on the case we are dealing with
Tnode *findMax(Tnode *root)
{
    if (root == NULL)
    {
        return root;
    }
    else if (root->right == NULL)
    {
        return root;
    }
    return findMax(root->right);
}
//---[deleting an item from a binary tree]-
Tnode *delete(Tnode *root, int data)    
{
    if (root == NULL)
    {
        return root; // root is null so nothing will be returned in that case
    }
    else if (root->value > data)
    { // looking in the left sub-tree
        root->left = delete (root->left, data);
    }
    else if (root->value < data)
    { // looking in the right sub-tree
        root->right = delete (root->right, data);
    }
    else if(root->value==data)
    { // in here it mean that we are right in the node we are looking for
        if (root->left == NULL && root->right == NULL)
        { // case one a leaf node
            free(root);
            root=NULL;
             // for the sake of the ones pointing to it so that they will be null
        }
        else if (root->left == NULL)
        { // the node have only on child
            Tnode *temp = root;
            root = root->right;
            free(temp);
        }
        else if (root->right == NULL)
        {
            Tnode *temp = root;
            root = root->left;
            free(temp);  
        }
        else 
        { // there is two childs
            Tnode *temp = findMax(root->left);
            root->value = temp->value;
            root->left = delete (root->left, temp->value);
        }
    }
    return root;
}
//---[attempt to know the height of a tree]---
int findHeight(Tnode*root){
    if(root==NULL){
        return -1;
    }
    else{
        if(findHeight(root->left)>=findHeight(root->right)){
            return findHeight(root->left)+1;
        }
        else if(findHeight(root->left)<findHeight(root->right)){
            return findHeight(root->right)+1;
        }
    }
}
int findDepth(Tnode*root, int value, int level){
    int lvldown;
    if(!root){
        return 0;
    }
    if(root->value==value){
        return level;
    }

    else{
        lvldown=findDepth(root->right,value,level+1);
        if(lvldown!=0){
            return lvldown;
        }
        return lvldown=findDepth(root->left,value,level+1);
    }
}   
int sumrange(Tnode*root,int min,int max,int sum){
    if (root->value>min&&root->value<max)
        {sum+=root->value;}
    else if(!root){
        return sum;
    }
    else{
        sumrange(root->left, min,max,sum);
    
        sumrange(root->right, min,max,sum);
        
    }

    return sum;
}

int main()
{
    int counter=0;
    int*p=&counter;
    Tnode *root = NULL;
    {//the insertion part 
        root = Insert(root, 7);
        root = Insert(root, 10);
        root = Insert(root, 3);
        root = Insert(root, 5);
        root = Insert(root, 2);
        root = Insert(root, 12);
    }
    printT(root);
    //searchT(root,2222);
    //printf("%d",(findMin(root))->value);
    delete(root,3);
    printT(root);
    return 0;
}








































/*
--------[finding the minimum value in a tree]---------------
Tnode*findMin(Tnode*root){
    if(root==NULL){
        return root;
    }
    else if(root->left==NULL){
        return root;
    }
    return findMin(root->left);
}
*/

/*
--------[finding the maximum value in a tree]---------------
Tnode*findMax(Tnode*root){
    if(root==NULL){
        return root;
    }
    else if(root->right==NULL){
        return root;
    }
    return findMax(root->right);
}
*/
/*
------------------------------------------[core idea of deleting a node]-------------------------------------
<Note>
===>while dealing with the element that will replace the node to be deleteted we need to use that rule of SH-&-HS
===>since that we can only keep on going on one direction we give the start point to be the highest and we search for the lowest using findMin
===>or we give the start point to be the lowest and we search for the highest using findMax
===>we replace our the value of our node with the value of the one in the end of tree
===>we remove the last one that is being repeated
===>upon deleting the last one i guess we will only call the delete function again with
===>with the value that we will recieve from the min value we can simply recal delete on it so get rid of it
Tnode*delete(Tnode*root, int data){
    if(root==NULL){
        return root;
    }
    else if(root->value>=data){
        root->left=delete(root->left,data);
    }
    else if(root->value<data){
        root->right=delete(root->right,data);
    }
    else{
        if(root->right==NULL&&root->left==NULL){
            free(root);
            root=NULL;
            return root;
        }
        else if(root->right==NULL){
            Tnode*temp=root;
            root=root->left;
            free(temp);
            return root;
        }
        else if(root->left==NULL){
            Tnode*temp=root;
            root=root->right;
            free(temp);
            return root;
        }
        else{
            Tnode*temp=findMin(root->right);
            root->value=temp->value;
            root->right=delete(root->right,temp);
        }
    }
//cause we may encounter multiple cases, it is best to use the delete function again to deal with the leaf node that contain a repetetive value
//also notice that we are passing the temporary value to be deleted from the subtree

}
*/
/*
since that i still have time i will rewrite it
Tnode*delete(Tnode*root,int data);
    if(root==NULL){
        return root;

    }

*/