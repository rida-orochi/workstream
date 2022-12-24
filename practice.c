#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};
typedef struct node Tnode;
Tnode* create(Tnode*head,int data){
    if(!head){
        Tnode*new=(Tnode*)malloc(sizeof(Tnode));
        new->data=data;
        new->next=NULL;
        head=new;
        return head;
    }
    for(Tnode*temp=head;temp!=NULL;temp=temp->next){
        if(temp->next==NULL){
            Tnode*new=(Tnode*)malloc(sizeof(Tnode));
            new->data=data;
            new->next=NULL;
            temp->next=new;
            return head;
        }
    }
}
void printL(Tnode*head){
    for(Tnode*temp=head;temp!=NULL;temp=temp->next){
        printf("%d\n",temp->data);
    }
}
Tnode*delete(Tnode*head,int position){
    if(position==1){
        head=NULL;
        return head;
    }
    int counter=0;
    for(Tnode*temp=head;temp!=NULL;temp=temp->next){
        counter++;
        if(counter==position){
            Tnode*holder=temp->next;    
            temp->data=(temp->next)->data;
            temp->next=(temp->next)->next;
            free(holder);
        }
    }
}
int main(){
    Tnode*head=NULL;
    head=create(head,5);
    head=create(head,6);
    head=create(head,7);
    head=create(head,8);
    head=create(head,9);
    head=create(head,10);
    delete(head,3);
    printL(head);
    return 0;
}