#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};
typedef struct node Lnode;
Lnode*head=NULL;
Lnode*tail=NULL;
Lnode*push(int value){
    Lnode*new=(Lnode*)malloc(sizeof(Lnode));
    new->data=value;
    new->next=NULL;
    if(!head&&!tail){
        head=tail=new;
    }
    else{
        Lnode*temp=head;
        head=new;
        new->next=temp;
    }
    return head;
}
Lnode*pop(){
    if(!head&&!tail){
        return head;
    }
    else{
        Lnode*temp=head;
        head=head->next;
        free(temp);
        return head;
    }
}
void printL(Lnode*head){
    for(Lnode*temp=head;temp;temp=temp->next){
        printf("%d-",temp->data);
    }
}
int main(){
    head=push(1);
    head=push(2);
    head=push(3);
    head=push(4);
    head=push(5);
    head=push(6);
    head=push(7);
    pop();
    printL(head);
    return 0;
}