/*
Authorship: Rida Allah Jaija,
ID: 98003,
Purpose: a queue of clients that want to pre-order our product. first in first out
date: october 27, 2022
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{ 
    char name[40];
    int quantity;
    struct node *next;
};
typedef struct node queue_E ;
void newClient(queue_E *head, queue_E *tail ){
    queue_E *new_client = (queue_E *)malloc(sizeof(queue_E));
    printf("please enter your name: ");
    scanf("%s",new_client->name);
    printf("please enter the quantity you want to purchase: ");
    scanf("%s",new_client->quantity);
    if(head==0&& tail ==0){
        head=tail=new_client;
    }
    else {
        new_client=tail->next;
        new_client=tail;
    }
}
void clientOut(queue_E *head, queue_E *tail ){
    queue_E *temporary=head;
    head= head->next;
    free(temporary);
}
void displaylist(queue_E *head)
{
    // i would like to loop through that list in a different way
    for (queue_E *temporary = head; temporary != NULL; temporary = temporary->next)
    {
        printf("\n%s", temporary->name);
        printf("\n%d", temporary->quantity);
        
    }
}
int main(){
// in here i will be calling head front, and tail rear since that m dealing with queue 
    queue_E *front=0;
    queue_E *rear=0;
    int userchoice=0;
    char feedBack[100];
    printf("woould you like to buy our pre-released product, you will get one as soon as it out but in cheaper price(yes1/no2):  ");
    scanf("%d",&userchoice);
    if(userchoice==1){
        newClient(front, rear);
        pritnf("thank you for your trust in our company");
    }
    else if(userchoice!=1){
        clientOut(front, rear);
        printf("can you tell us what you don't like about our product");
        fgets(feedBack,sizeof(feedBack), stdin);
    }
    displaylist(front);
    

    return 0;
}


