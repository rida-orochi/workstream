#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    int value;
    struct node* next;
};
typedef struct node list;
list* header=0;
//printing the list
void printl(list*head){
    for(list*temp=head;temp!=NULL;temp=temp->next){
        printf("%d\n",temp->value);
    }
}
//adding element to the end of the list
void addEnd(list*head,int X){
    for(list*temp=head;temp!=NULL;temp=temp->next){
        if(temp->next==NULL){
            list*elem=(list*)malloc(sizeof(list));
            temp->next=elem;
            elem->next=NULL;
            elem->value=X;
            break;
        }
    }
}
int main(){
    list n1,n2,n3,n4,n5,n6,n7;
    header=&n1;
    n1.next=&n2;
    n2.next=&n3;
    n3.next=&n4;
    n4.next=&n5;
    n5.next=&n6;
    n6.next=&n7;
    n7.next=NULL;
    n1.value=1111;
    n2.value=2222;
    n3.value=3333;
    n4.value=4444;
    n5.value=5555;
    n6.value=6666;
    n7.value=7777;
    addEnd(header,8888);
    printl(header);
    return 0;
}