/*
Authorship: Rida Allah Jaija,
ID: 98003,
Purpose: A queue of client that are waiting for a liver to be transplanted. This code manage the waiting list of the hospital on a first in first out basis.
date: october 27, 2022
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"reference.h"

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