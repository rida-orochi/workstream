#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};
typedef struct node Lnode;
Lnode*head;

Lnode*create(Lnode*head,int data){
    if(!head){
        Lnode*new=(Lnode*)malloc(sizeof(Lnode));
        new->data=data;
        new->next=NULL;
        head=new;
    }
    for(Lnode*temp=head;temp!=NULL;temp=temp->next){
        if(temp->next==NULL){
            Lnode*new=(Lnode*)malloc(sizeof(Lnode));
            new->data=data;
            new->next=NULL;
            temp->next=new;
            return head;
        }//i created one then i need to stop or that i will create an infinite loop 
    }
    return head;
}
Lnode*push(Lnode*head,int data){
    if(!head){
        Lnode*new=(Lnode*)malloc(sizeof(Lnode));
        new->data=data;
        new->next=NULL;
        head=new;
        return head;
    }
    
    Lnode*new=(Lnode*)malloc(sizeof(Lnode));
    new->data=data;
    new->next=head;
    head=new;
    return head;
}
void printlist(Lnode*head){
    for(Lnode*temp=(head->next);temp!=NULL;temp=temp->next){
        printf("%d->",temp->data);
    }
}
Lnode*delete(Lnode*head,int data){
    if(!head){
        return head;
    }
    else if(!(head->next)->next){
        head=NULL;
        return head;
    }
    else{
        for(Lnode*temp=head;temp!=NULL;temp=temp->next){
            if((temp->next)->data==data){
                Lnode*holder=temp->next;
                temp->next=(temp->next)->next;
                free(holder);
                return head;
            }
        }
    }
}
Lnode*reversel(Lnode*head){
    if(!head){return head;}
    else if(!(head->next)->next){return head=head->next;}
    else{ 
        Lnode*current=head;
        Lnode*previous=NULL;
        while(current!=NULL){
            Lnode*Onext=current->next;
            current->next=previous;
            previous=current;
            current=Onext;
        }
        return previous;

    }
}
int main(){
    head=NULL;
    head=create(head, 5);
    head=create(head, 4);
    head=create(head, 3);
    head=create(head, 7);
    head=create(head, 1);
    head=create(head, 2);
    head=create(head, 6);
    head=create(head, 9);
    //delete(head,7);
    printlist(push(head,20));
    return 0;
}