/*
Authorship:
    Rida Allah Jaija,
Purpose:
    We take data from users(email-password). we store it in a separate file. if you already have an account in our little system you can log in directly, otherwise, you need to creat an account that will be stored in a file so that it can be used again to recognize the dear users 
date: 
    september 23, 2022
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char email[30];
    char password[20];
    char membership[10];
    char paid[4];
} users;

const char* format="\n%s%30s%30s%30s  ";
users user[100];
int main()
{
    // variable declaration
    int position;
    int flag = 1;
    int counter = 0;
    int current = 0;
    int user_choice;
    char line[130];
    char T_email[30];
    char T_password[20];
    // file creation
    FILE *fptr;
    fptr = fopen("D-base.txt", "r");
    if (!fptr)
    {
        printf("file does not exist");
        fptr = fopen("D-base.txt", "w");
        fclose(fptr);
    }
    fclose(fptr);
    // reading from file
    fopen("D-base.txt", "r");
    char *piece = strtok(line, " ");
    // importing previous data from file
    while (fgets(line, sizeof(line), fptr))
    {
        char *piece = strtok(line, " "); 
        strcpy(user[current].email, piece);
        piece = strtok(NULL, " "); 
        strcpy(user[current].password, piece);
        piece = strtok(NULL, " "); 
        strcpy(user[current].membership, piece);
        piece = strtok(NULL, " "); 
        strcpy(user[current].paid, piece);
        current += 1;
    }
    fclose(fptr);
    printf("\nchoose an option (1-log in /2-sign up): ");
    scanf("%d", &user_choice);
    if (user_choice == 1)
    {
        // checking if the email address exists
        do
        {
            printf("\nplease enter your email: ");
            getchar();
            flag = 0;
            fgets(T_email, sizeof(T_email), stdin);
            T_email[strlen(T_email) - 1] = '\0';
            for (int i = 1; i <= current; i++)
            {
                counter = strcmp(user[i].email, T_email);
                if (counter == 0)
                {
                    position = i;
                    break;
                }
            }
            if (counter != 0)
            {
                printf("\nthat email account does not exist!!\nwould you like to try again(1-yes/2-no): ");
                scanf("%d", &user_choice);
                if (user_choice == 2)
                {
                    break;
                }
            }
        } while (counter != 0);
        if (user_choice != 2)
        {
            do
            {
                printf("please enter your password: ");
                scanf("%s", T_password);
                if (strcmp(user[position].password, T_password) != 0)
                {
                    printf("\nwrong password !!\nwould you like to try again(1-yes/2-no): ");
                    scanf("%d", &user_choice);
                    if (user_choice == 2)
                    {
                        break;
                    }
                }
                printf("\ndetails of your account: \n-current membership: %s\n-paid: %s",user[position].membership,user[position].paid);
            } while (strcmp(user[position].password, T_password) != 0);
        }
    }
    else if (user_choice == 2)
    {
        current += 1;
        printf("please enter your new email address: ");
        getchar();
        fgets(user[current].email, sizeof(user[current].email), stdin);
        user[current].email[strlen(user[current].email) - 1] = '\0';
        printf("\nplease enter your new password: ");
        scanf("%s", user[current].password);
        printf("\nplease select your membership: \n1-free\n2-basic\n3-standard\n4-premium\n5-gold\n=> ");
        scanf("%d", &user_choice);
        if (user_choice == 1)
        {
            strcpy(user[current].membership, "free");
        }
        else if (user_choice == 2)
        {
            strcpy(user[current].membership, "basic");
        }
        else if (user_choice == 3)
        {
            strcpy(user[current].membership, "standard");
        }
        else if (user_choice == 4)
        {
            strcpy(user[current].membership, "premium");
        }
        else if (user_choice == 5)
        {
            strcpy(user[current].membership, "gold");
        }
        //they just purchased the service they have free trial for the moment
        strcpy(user[current].paid, "yes");
        printf("\nyour account has been created successfuly!!");
        fopen("D-base.txt", "a");
        fseek(fptr,0,SEEK_END);
        fprintf(fptr,format,user[current].email,user[current].password,user[current].membership,user[current].paid);
        fclose(fptr);
    }

    return 0;
}