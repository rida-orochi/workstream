#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    char thing;
    struct node*right;
    struct node*left;
};
typedef struct node Tnode;
Tnode*create(char data){
    Tnode*temp=(Tnode*)malloc(sizeof(Tnode));
    temp->thing=data;
    temp->left=temp->right=NULL;
    return temp;
}
Tnode*Balancedtree(char arr[], int start, int end){
    Tnode*root;
    int length=end-start+1;
    int mid=start+(length/2);
    if(length==0){
        return NULL;
    }
    root=create(arr[mid]);
    root->left=Balancedtree(arr,start,mid-1);
    root->right=Balancedtree(arr,mid+1,end);
    return root;
}
void printTree(Tnode*root){
    if(!root){
        printf("\n<No value>");
    }
    else{
        printf("\n%c",root->thing);
        printTree(root->left);
        printTree(root->right);
    }
}

int main(){
    Tnode*root=NULL;
    char array[]="abcdefghijklmonp";
    int length=strlen(array)-1;
    printf("\n%d\n",length);
    root =Balancedtree(array,0,length-1);
    printf("\n%X",root);
    printTree(root);
    return 0;
}