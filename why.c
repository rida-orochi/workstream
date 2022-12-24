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
void treePrint(Tnode *root)
{
    if (!root)
    {
        printf("<no value>\n");
    }
    else
    {
        printf("%d\n", root->data);
        treePrint(root->left);
        treePrint(root->right);
    }
}
int mirror(Tnode *root1, Tnode *root2)
{
    static int result=1;
    if (!root1 && !root2)
    {
        return result;
    }
    else
    {
        mirror(root1->right, root2->left);
        mirror(root1->left, root2->right);
        if (root1->data != root2->data)
        {
            return result*0;
        }
    }
}
int main()
{

    Tnode *n1 = (Tnode *)malloc(sizeof(Tnode));
    Tnode *n2 = (Tnode *)malloc(sizeof(Tnode));
    Tnode *n3 = (Tnode *)malloc(sizeof(Tnode));
    Tnode *n4 = (Tnode *)malloc(sizeof(Tnode));
    Tnode *n5 = (Tnode *)malloc(sizeof(Tnode));
    n1->data = 1;
    n2->data = 2;
    n3->data = 35;
    n4->data = 4;
    n5->data = 5;
    n1->right = n3;
    n1->left = n2;
    n2->right = n5;
    n2->left = n4;
    n3->right = NULL;
    n4->right = NULL;
    n5->right = NULL;
    n3->left = NULL;
    n4->left = NULL;
    n5->left = NULL;
    Tnode *root1 = n1;
    Tnode *n10 = (Tnode *)malloc(sizeof(Tnode));
    Tnode *n20 = (Tnode *)malloc(sizeof(Tnode));
    Tnode *n30 = (Tnode *)malloc(sizeof(Tnode));
    Tnode *n40 = (Tnode *)malloc(sizeof(Tnode));
    Tnode *n50 = (Tnode *)malloc(sizeof(Tnode));
    n10->data = 1;
    n20->data = 2;
    n30->data = 3;
    n40->data = 4;
    n50->data = 5;
    n10->left = n30;
    n10->right = n20;
    n20->left = n50;
    n20->right = n40;
    n30->right = NULL;
    n40->right = NULL;
    n50->right = NULL;
    n30->left = NULL;
    n40->left = NULL;
    n50->left = NULL;
    Tnode *root2 = n10;
    //treePrint(root1);
    // treePrint(root2);
    printf("%d", mirror(root1, root2));
    return 0;
}