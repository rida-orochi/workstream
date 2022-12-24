#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//dealingt with linked lists 
//creating the list
struct node{
    int value;
    struct node*next;
};
typedef struct node list;// the type of struct so that it won't be repeated 
list *header=0;
//reverse a linked lsit 
list* Rprint(list* head){
    if(head==NULL){
        return head;
    }
    else{
        Rprint(head->next);
        printf("%d\n",head->value);
    }
}
//printing list in the normal order
void printl(list*head){
    for(list*temp=head;temp!=NULL; temp=temp->next){
        printf("%d\n",temp->value);
    }
}
// i will try to check if a list is ordered by using recursion
//i will try doing it my way
int isOrdered(list*head){
    int flag=0;
    if(head==NULL){
        printf("\nthe lsit is orderd\n");
    }
    else{
        if(head->value>(head->next)->value){
            flag=1;
            printf("\n not ordered");
            return 0;
        }
        isOrdered(head->next);//to keep the loop going // that one is even easier than the ones before
    }
}
void searchL(list*head, int x){
    for(list*temp=head;temp!=NULL;temp=temp->next){
        if(temp->value==x){
            printf("we got it the ID:%d is here",temp->value);
        }
    }
}
//inserting elements in the beguinning of the list 
list* binsert(list*head,int x){
    list*temp=head;
    printf("%d\n",temp->value);
    list*new=(list*)malloc(sizeof(list));
    new->value=x;
    new->next=temp;
    return head=new;    
    printf("%d\n",new->value);
    printf("hello there");
    //the thing is that i return only changes that i made in that place
    //those were no globsal changes
}
//inserting element in the end of the list 
void insertE(list* head,int X){
    for(list*temp=head;temp!=NULL;temp=temp->next){
        if(temp->next==NULL){
            list*new=(list*)malloc(sizeof(list));
            temp->next=new;
            new->next=NULL;
            new->value=X;
            break;
        }
    }
}
//inserting an element before the last one
// inserting an element after a certain position
//insertion an element before an elemnt 

int main(){
    int userchoice=0;
    //creating nodes and linking them together
    list n1,n2,n3,n4,n5;
    header=&n1;
    n1.next=&n2;
    n2.next=&n3;
    n3.next=&n4;
    n4.next=&n5;
    n5.next=NULL;
    n1.value=1111;
    n2.value=1112;
    n3.value=1113;
    n4.value=1114;
    n5.value=1115;
    printf("\nthis is the list reversed: \n");
    Rprint(header);
    printf("\nthis is the list not reversed: \n");
    printl(header);
    printf("\nis the list ordered: \n");
    printf("tell me the ID of the node and i will get it: ");
    scanf("%d",&userchoice);
    searchL(header,userchoice);

    return 0;
}