#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    int data;
    struct node*right;
    struct node*left;
};
typedef struct node Tnode;
Tnode*root=NULL;
Tnode*insert(Tnode*root, int value){
    
    if(!root){
        Tnode*new=(Tnode*)malloc(sizeof(Tnode));
        new->right=new->left=NULL;
        new->data=value;
        return root=new;
    }
    else if(root->data>=value){
        root->left=insert(root->left, value);
        return root;
    }
    else if(root->data<value){
        root->right=insert(root->right,value);
        return root;
    }
    return root;
}
void printT(Tnode*root){
    if(!root){
        printf("-\n");
    }
    else{
        printf("-%d\n",root->data);
        printT(root->left);
        printT(root->right);
    }
}
void printTT(Tnode*root,int indent){
    if(!root){
        for(int i=0;i<indent;i++){
            printf(" ");
        }
        printf("-\n");
    }
    else{
        for(int i=0;i<indent;i++){
            printf(" ");
        }
        printf("-%d\n",root->data);
        printTT(root->left,indent+4);
        printTT(root->right,indent+4);
    }
}
Tnode*findMin(Tnode*root){
    if(!root){return root;}
    else if(!root->left){return root;}
    findMin(root->left);
}
Tnode*findMax(Tnode*root){
    if(!root){return root;}
    if(!root->right){return root;}
    findMax(root->right);
}
Tnode*search(Tnode*root,int value){
    if(!root){
        printf("not found or doesn't exist");
        return root;}
    else{
        if(root->data=value){
            return root;
        }
        else if(root->data>value){
            search(root->left, value);
        }
        else if(root->data<value){
            search(root->right, value);
        }
    }
}
int main(){
    root=insert(root,7);
    root=insert(root,5);
    root=insert(root,12);
    root=insert(root,3);
    root=insert(root,6);
    root=insert(root,9);
    root=insert(root,15);
    root=insert(root,1);
    root=insert(root,4);
    root=insert(root,8);
    root=insert(root,10);
    root=insert(root,13);
    root=insert(root,17);
    printf("%x",(search(root,9)));
    return 0;
}