#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//in here i need to define a struct as if m dealing with linked list
struct node
{
    int value;
    char name[20];
    struct node* next;
};
typedef struct node item;
// we are trying to create a queue
item* head=0;
item* tail=0;
//it's better to declair that part globaly istead of using a pointer to pointer
// i doubt that this one will change since that it was initially created globally.
void enqueue(int X){
    item*temp=(item*)malloc(sizeof(item));//step1: create node
    temp->next=NULL;//it's the last one so it need to have NULL as next elem
    temp->value=X;//step2: give it meaning
    //strcpy(temp->name,"in here");//step2:give it meaning 
    //step3: insert the node in the list [note that here is some cases you need to take in consideration]
    if(head==NULL&& tail==NULL){
        head=temp;
        tail= temp;
        return;
    }
    else{
        tail->next=temp;//instead of it being NULL we will replace it by the new value
        tail=temp;
    }//we are just adding in here, and since that we have no limits there is no need to check. just add that item to the list just do it well
}
void displayList(item*head){
    for(item* temp=head;temp!=NULL;temp=temp->next){
        printf("\n%d", temp->value);
    }
}
int main(){
    int user_choice=0,y;
    //how about using a loop 
    // i want to make this thing more interactive
    // i want to give freedom to the user 
    printf("do you want to play the game?(yes1/no2): ");
    scanf("%d",&user_choice);
    while(user_choice==1){
        printf("\nnow give me a number: ");
        scanf("%d",&y);
        enqueue(y);
        printf("\n it's in do you wanna play again(yes1/no2): ");
        scanf("%d",&user_choice);
    }
    printf("\nthe numbers you have entered are: ");
    displayList(head);
    return 0;
}// the thing is how can i enter new elements on demand in here comes the role of using somthing interesting 