#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    int data;
    struct node *right;
    struct node *left;
};
typedef struct node Tnode;
// creating the tree
Tnode *create(int data)
{
    Tnode *elem = (Tnode *)malloc(sizeof(Tnode));
    elem->data = data;
    elem->left = elem->right = NULL;
    return elem;
}
// inserting the node to the tree
Tnode *insertion(Tnode *root, int data)
{
    if (!root)
    {
        root = create(data);
        return root;
    }
    else if (root->data >= data)
    {
        root->left = insertion(root->left, data);
        return root;
    }
    else if (root->data < data)
    {
        root->right = insertion(root->right, data);
        return root;
    }
}
/*[COMMENT]
after creating the tree now i need to test the traversal and see the order and roots that i can follow
it's like that we are undertanding or getting accustome to the tools that we need to use in the midterm
it ain't about getting the answet right it's all about being able to defind your approach and demonstrate your understanding of the topic

*/
void treePrint(Tnode *root)
{
    if (!root)
    {
        printf("<no value>\n");
    }
    else
    {
        treePrint(root->left);
        treePrint(root->right);
        printf("%d\n", root->data);
    }
}
/*[COMMENT]
in here we will be experimenting the traversal of the that we are supposed to go trough
i will be shifting between inorder postorder and preorder taking that we need to be aware of the course of our code
for the moment i will just run the code and see the output from it i need to deduce the result that are to be followed
*/
/*[COMMENT]
attempt to solve the last question in that previous midterm
*/
int summrange(Tnode *root, int min, int max)
{
    static int sum = 0;
    if (!root)
    {
        return sum;
    }

    summrange(root->left, min, max);
    summrange(root->right, min, max);
    if (root->data > min && root->data < max)
    {
        sum += root->data;
    }
    return sum;
}
/*[COMMENT]
i need to be able to travers the tree but only the part that matters to find the thing that i am looking for. then do the thing with that node and quite the recursion an example that will help me with that will be the deletion function since that it work with the same concept search for a node then do the thing with it and exit using return since that going trough all the tree is meaningless

*/
Tnode *findMin(Tnode *root)
{
    if (!root)
    {
        return root;
    }
    if (root->left == NULL)
    {
        return root;
    }
    findMin(root->left);
}
Tnode*findMax(Tnode*root){
    if(!root){
        return root;
    }
    else if(!root->right) {
        return root;
    }
    findMax(root->right);


}
Tnode*locate(Tnode*root, int data){
    if(!root){
        return root;
    }
    else{
        if(root->data>data){
            locate(root->left,data);
        }
        else if(root->data<data){
            locate(root->right,data);
        }
        else{
            return root;
        }
    }
}
Tnode *delete (Tnode *root, int data)
{
    if (!root)
    {
        return root;
    }
    if (root->data > data)
    {
        root->left = delete (root->left, data);
    }
    else if (root->data < data)
    {
        root->right = delete (root->right, data);
    }
    else
    {
        if (!root->right && !root->left)
        {
            free(root);
            root = NULL;
        }
        else if (!root->right)
        {
            Tnode *temp = root;
            root = root->left;
            free(temp);
        }
        else if (!root->left)
        {
            Tnode *temp = root;
            root = root->right;
            free(temp);
        }
        else
        {
            Tnode *temp = findMin(root->right);
            root->data = temp->data;
            root->right = delete (root->right, temp->data);
        }
    }
    return root;
}
/*[COMMENT]
now i get we kkep on going until we find the value we want and we return it
there was no need to return the function since that we need only to return the smallest node the part that included return function was supposed to call the function only so that we can have that recursive effect rely basicly on the devide and conquer approach since that the prof want us to use it that way u need to work your brain
it ain't a big problem since that the only mistake was that i was dealing with a different else
what if we wanted to delete all the elements in a range
*/
Tnode *deleteRange(Tnode *root, int min, int max)
{
    if (!root){return root;}
    root->right = deleteRange(root->right, min, max);
    root->left = deleteRange(root->left, min, max);
    if (root->data > min && root->data < max){
        if (!root->right && !root->left){
            free(root);
            root = NULL;
        }
        else if (!root->right){
            Tnode *temp = root;
            root = root->left;
            free(temp);
        }
        else if (!root->left){
            Tnode *temp = root;
            root = root->right;
            free(temp);
        }
        else{
            Tnode *temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteRange (root->right, min,max);
        }
    }
    return root;
}
void printRange(Tnode*root,int min,int max){
    if(!root){
        printf("");
    }
    else{
            printRange(root->left,min,max);
            if(root->data>min&&root->data<max){
                printf("%d\n",root->data);
            }
            printRange(root->right,min,max);

    }
    
}
int findHeight(Tnode*root){
    if(!root){
        return -1;
    }
    else{
        int a= findHeight(root->right), b=findHeight(root->left);
        if(a>=b){
            return a+1;
        }
        else{
            return b+1;
        }
    }

}
int findDepth(Tnode*root,int data,int lvl){
    if(!root){
        return 0;
    }
    if(root->data==data){
        return lvl;
    }
    else{
        int lvldown=findDepth(root->left,data,lvl+1);
        if(lvldown!=0){//this one is to get rid of the values that we get we reach the end of the tree since that those will ruin the outcome we are waiting for othre than that they are just doing a simple inorder traversal and and each time they go down they add a number to the counter-in that case i wanted the next iteration to be seperate from the control of the selection
            return lvldown;
        }
        return lvldown=findDepth(root->right,data,lvl+1);
    }
}
/*[COMMENT]
in here they kind of reversed the order 
*/
//-------------------------------------------------------//
/*
if i got any conclusion from the code that i just wrote is that the order matters the most taking that we are supposed to traverse the tree based on the selected order and do variant operation on the trees
understanding the traversal will make dealing with the recursion less easier taking that we will be able to know what node we are visiting at a certain momment

*/
int main()
{
    Tnode *root = NULL;
    root = insertion(root, 15);
    root = insertion(root, 10);
    root = insertion(root, 20);
    root = insertion(root, 8);
    root = insertion(root, 12);
    root = insertion(root, 11);
    root = insertion(root, 13);
    root = insertion(root, 17);
    root = insertion(root, 25);
    root = insertion(root, 19);
    root = insertion(root, 23);
    root = insertion(root, 26);
    root = insertion(root, 22);
    root = insertion(root, 21);
    // summrange(root, 10, 20);
    // printf("%d", summrange(root, 10, 20));
    //deleteRange(root, 7, 12);
    //treePrint(root);
    //printRange(root,12,22);
    printf("%d",findDepth(root,21,0));
    return 0;
}