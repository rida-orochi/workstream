/*
Authorship: Rida Allah Jaija,
ID: 98003,
Purpose: A queue of client that are waiting for a liver to be transplanted. This code manage the waiting list of the hospital on a first in first out basis.
date: october 27, 2022
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// client creating
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

// queue functions
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

int main()
{
    int userChoice, userAge, flag = -1;
    char userName[30];
    printf("\nwould you like to sign in the waitlist of people waiting for a liver donner(yes1/no2): ");
    scanf("%d", &userChoice);
    do
    {
        if (userChoice == 1)
        {
            flag=1;
            printf("please enter your name: ");
            getchar();
            fgets(userName, sizeof(userName), stdin);
            printf("please enter your age: ");
            scanf("%d", &userAge);
            enqueue(userAge, userName);
        }
        else if (userChoice != 1)
        {
            flag=0;
            printf("stay safe!!");
        }
        printf("\nis there any other client who want to sign in to the waiting list(yes1/no2): "); // adding mew memebers to the queue
        scanf("%d", &userChoice);
    } while (userChoice == 1);
    if (flag == 1)
    {
        printf("how many new possible livers for the patients in the waiting list? ");
        scanf("%d", &userChoice);
        for (int i = 0; i < userChoice; i++)
        {
            dequeue();
        }
    }
    displayList(front);
    return 0;
}