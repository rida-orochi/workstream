// demo of the stack
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    int value;
    char name[20];
    struct node *next;
};
typedef struct node part;
part *head = 0;
void push(int Z)
{
    part *temp = (part *)malloc(sizeof(part)); // now we created the node to deal with
    // here sound like the perfect place to enter a value to the list
    temp->value = Z;
    if (head == 0)
    {                  // the case in which we are inserting a new node
        head = temp;   // since that we don't have a pointer to moniter the tail we keep it as it is
        return;        // since that we returned in here ther is no need to do a second what if
    }                  // how can i refer to the already existing node
    temp->next = head; // now we made sure that we refer to it and hold it's value
    head = temp;       // now officialy the new temporary node that i created is considered as the top of my list
}
void pop()
{
    printf("\nhello //there");
    if (head == 0)
    {
        return;
    }
    part *temp = head;
    head = head->next; // in here it's like we are saying that we need to change the header to the next element in the list
    printf("\n hello there");
    free(temp);
}
void printl(part *head)
{
    for (part *temp = head; temp != NULL; temp = temp->next)
    {
        printf("\n%d", temp->value);
    }
    return;
}
int main()
{
    push(5);  // let's try to add some content to my list
    push(4);  // let's try to add some content to my list
    push(3);  // let's try to add some content to my list
    push(2);  // let's try to add some content to my list
    push(1);  // let's try to add some content to my list
    pop();    // now let's try some poping to get rid of those unwanted items
    printl(head);
    return 0;
}
