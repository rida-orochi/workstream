#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// defining the strcut that will form the list
//  we need to create the struct by giving it a name first to refer to it
struct node
{ /*
==>note:
that in here we mentioned the name of the struct so that we can refere to it and creat the pointer that will point to the next node
while creating a list it's necessairy to declare the name of the name of the type before definning it
*/
    int value;
    struct node *next;
};
typedef struct node list;
void displaylist(list *head)
{
    // i would like to loop through that list in a different way
    for (list *temporary = head; temporary != NULL; temporary = temporary->next)
    {
        printf("\n%d", temporary->value);
    }
}
void occurence(list *head)
{
    int counter; // to tell the number of the occurence of that item
    for (list *temporary = head; temporary != NULL; temporary = temporary->next)
    {
        if (temporary->value == 1111)
        {
            counter++;
        }
    }
    printf("\n%d", counter);
}
void isOrdered(list *head)
{
    int flag = 0;
    for (list *temporary = head; temporary != NULL; temporary = temporary->next)
    {
        list *following = temporary->next;
        if (temporary->value > following->value)
        {
            flag++;
        }
        if (flag == 0)
        {
            printf("\ntrue");
        }
        else if (flag != 0)
        {
            printf("\nfalse");
        }
    }
}
void insertAfter(list *head, list *oldItem, list *newItem)
{
    // in here we don't need to assign a value to the node all we need to do is to create a node in a predefined place
    // first allocate memory to the new item
    list *holder;
    // swape addresses
    for (list *tempo = head; tempo != NULL; tempo = tempo->next)
    {
        if (tempo == oldItem)
        {
            holder = oldItem->next;
            tempo->next = newItem;
            newItem->next = holder;
        }
    }
    // link nodes
}
void insertBeforeLast(list *head, list *oldItem, list *newItem)
{
    // loop until you find the new item
    list *holder;
    for (list *temp = head; temp != NULL; temp = temp->next)
    {
        if ((temp->next)->next == NULL)
        {
            holder = temp->next;
            temp->next = newItem;
            newItem->next = holder;
            printf("\n%d\n", temp->value);
            printf("\n%d\n", (temp->next)->value);
            break;
        }
    }
}
list* readList(FILE*pointer){
    pointer=fopen("listFile.txt","r");
    list*nextList=(list*)malloc(sizeof(list));
    while(fgets(nextList,sizeof(nextList),pointer)){
    }
    fclose(pointer);
    return nextList;
} 
int main()
{
    list n1, n2, n3, n4;
    // notice that this part is the responsible of calling the other function cause it represent the head of the list
    list *head;
    // assigning values
    n1.value = 1111;
    n2.value = 1112;
    n3.value = 1111;
    n4.value = 1111;
    // linking the lists
    head = &n1;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    // hold on at this part the compiler don't get it cause at this point we didn't assign n5 yet
    // let's create a new element in here via memory allocation
    // but isn't memory allocation should be used for a reason
    // i can't see that in here
    // i don't really get the idea behind it well since it works let's take it as a rule
    list *n5 = (list *)malloc(sizeof(list));
    n4.next = n5; // now it makes sense
    n5->next = NULL;
    n5->value = 1115;
    // occurence(head);
    // isOrdered(head);
    list *oldItem = &n4;
    list *n4_1 = (list *)malloc(sizeof(list));
    n4_1->value = 1116;
    insertAfter(head, oldItem, n4_1);
    list *n5_1 = (list *)malloc(sizeof(list));
    n5_1->value = 1117;
    insertBeforeLast(head, n5, n5_1);

    // hard reset
    n1.value = 0;
    n2.value = 0;
    n3.value = 0;
    n4.value = 0;
    n5->value = 0;
    n5_1->value = 0;
    n4_1->value = 0;
    FILE*fptr;
    displaylist(readList(fptr));
    return 0;
}