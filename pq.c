#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    int data;
    struct node*next;
};
typedef struct node Lnode;
Lnode*head=NULL;
Lnode*tail=NULL;
Lnode*enqueue(int value){
    Lnode*new=(Lnode*)malloc(sizeof(Lnode));
    new->data=value;
    new->next=NULL;
    if(!tail&&!head){
        head=tail=new;
    }
    else{
        Lnode*temp=tail;
        tail->next=new;
        tail=new;
    }
    return head;
}
Lnode*dequeue(){
    if(!head&&!tail){
    }
    else if(head==tail){
        head=tail=NULL;
    }
    else{
        Lnode*temp=(Lnode*)malloc(sizeof(Lnode));
        temp=head;
        head=head->next;
        free(temp);
    }
    return head;
}
void printl(Lnode*head){
    for(Lnode*temp=head;temp!=NULL;temp=temp->next){
        printf("-%d",temp->data);
    }
}
int main(){
    head=enqueue(5);
    head=enqueue(4);
    head=enqueue(3);
    head=enqueue(2);
    head=enqueue(1);
    dequeue();
    printl(head);
    return 0;
}
//for the search from a linked linst we need to keep on traversing the nodes and add a condition to verifiy if the current value is equal to the one we are looking for it's easy 
//since that i am on it i will add some another part where i will be create a linked list and search it for a value 
//i would like also to do some code that will look up the linked list and delete the values that are in a certain range 
//the implementation of the last one is kind of easy i will simply go troigh the list if the next node value is inside the range i will simply assign the value of the after next to be next hence deleting the node that i want to be off