//this part is allocated to define the functions taht are to be used in the code 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    char name[30];
    int age;
    struct node *next;
};
typedef struct node client;

// global pointers
client *front = 0;
client *rear = 0;


void enqueue(int age, char name[])
{
    client *temp = (client *)malloc(sizeof(client));
    // taking that we are adding element to the queue from the rear then the last element's next must be NULL
    temp->next = NULL;
    temp->age = age;
    strcpy(temp->name, name);
    if (front == NULL && rear == NULL)
    {
        front = rear = temp;
    }
    else
    {
        rear->next = temp;
        rear = temp;
    }
}
void dequeue()
{
    client *temp = front;
    if (front == NULL)
    {
        return;
    }
    if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        front = front->next;
    }
}
void displayList(client *front)
{
    printf("\nclients that are waiting in the list are: ");
    printf("\n---------------------------");
    for (client *temp = front; temp != NULL; temp = temp->next)
    {

        printf("\nName: %s", temp->name);
        printf("Age: %d", temp->age);
        printf("\n---------------------------");
    }
}