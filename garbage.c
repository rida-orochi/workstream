#include <stdio.h>
void welcome();
void fctjean(float* ptr_totalP);
void fctTSH(float* ptr_totalP);
void fctcoat(float* ptr_totalP);
void fctdress(float* ptr_totalP);
void fctsneakers(float* ptr_totalP);
int menu();


int main()
{ // displaying a welcome message
    welcome();
   
    // loop
    do
    {
        int jeanP = 400, tshirtsP = 250, coatsP = 800, sneakersP = 550, dressesP = 600, quantity, choice;
        float ptr_totalP, sum=0;

        // assigning a integer to the menu
        choice = menu();
        switch (choice)
        {
        case 1:
            fctjean(&ptr_totalP);
            sum = sum + ptr_totalP;
            break;
        case 2:
            fctTSH(&ptr_totalP);
            sum = sum + ptr_totalP;
            break;
        case 3:
            fctcoat(&ptr_totalP);
            sum = sum + ptr_totalP;
            break;
        case 4:
            fctsneakers(&ptr_totalP);
            sum = sum + ptr_totalP;
            break;
        case 5:
            fctdress(&ptr_totalP);
            sum = sum + ptr_totalP;
            break;

        default:
            printf("you have to choose either 1,2,3,4,or 5\n");
            break;
        }

        printf("\npress 1 to stop or any other value to continue\n");
        scanf("%d", &try);
    } while (try != 1);
    printf("the total price is:%.2f", sum);

    return 0;
} // welcome message
void welcome()
{
    printf("welcome to our store! Your satisfaction is our priority\n ");
}
// the menu
int menu()
{
    int choice;

    printf("this is our menu:\n"
           "1 - jean\n"
           "2 - tshirts\n"
           "3 - coats\n"
           "4 - sneakers\n"
           "5 - dresses\n enter your choice\n");
    scanf("%d", &choice);

    return choice;
}
// fonction for t-shirt

void fctjean(float* ptr_totalP)
{
    int quantity, jeanP = 400, doubleQ;

    printf("please enter the quantity that you'd like to buy\n");
    scanf("%d", &quantity);
    *ptr_totalP = (float)quantity * jeanP;
    printf("press 1 to double the quantity or any other value to not do so\n");
    scanf("%d", &doubleQ);
    if (doubleQ == 1)
    {
        *ptr_totalP = ((float)quantity * jeanP) + (0.5 * quantity * jeanP);
    }
    else if (doubleQ != 1)
    {
        *ptr_totalP = *ptr_totalP;
    }
}
void fctTSH(float* ptr_totalP)
{
    int quantity, tshirtsP = 250;

    printf("please enter the quantity that you'd like to buy\n");
    scanf("%d", &quantity);
    *ptr_totalP = (float)quantity * tshirtsP;
}
void fctcoat(float* ptr_totalP)
{
    int quantity, offer, coatsP = 800;
    printf("please enter the quantity that you'd like to buy\n");
    scanf("%d", &quantity);
    offer = quantity / 3;
    printf("%d pair of sneakers is offered\n", offer);
    *ptr_totalP = (float)quantity * coatsP;
    if (quantity > 2)
    {
        *ptr_totalP = *ptr_totalP - (quantity * coatsP * 0.1);
    }
}
void fctdress(float* ptr_totalP)
{
    int card, quantity, choice, dressesP = 600;
    printf("please enter the quantity that you'd like to buy\n");
    scanf("%d", &quantity);
    *ptr_totalP = (float)quantity * dressesP;
    printf("press 1 if you have the loyalty card  or any other value if you don't\n");
    scanf("%d", &card);
    if (card == 1)
    {
        int Y, M, D;
        printf("please enter the date of your card in 3 terms first year,month, and day\n");
        scanf("%d%d%d", &Y, &M, &D);
        if (Y == 2022)
        {
            *ptr_totalP = (quantity * dressesP) - (quantity * dressesP * 0.1);
        }
        else if (Y < 2020)
        {
            printf("press 1 if you want to renew/reorder or any other value if you don't want to \n");
            scanf("%d", &choice);
            if (choice == 1)
            {
                *ptr_totalP = (quantity * dressesP) - (quantity * dressesP * 0.1) + 500;
            }
            else if (choice != 1)
            {
                *ptr_totalP = (quantity * dressesP);
            }
        }
        if (Y == 2021)
        {

            if (M < 10)
            {

                printf("press 1 if you want to renew/reorder or any other value if you don't want to \n");
                scanf("%d", &choice);
                if (choice == 1)
                {
                    *ptr_totalP = (quantity * dressesP) - (quantity * dressesP * 0.1) + 500;
                }
                else if (choice != 1)
                {
                    *ptr_totalP = (quantity * dressesP);
                }
            }
            if (M == 12)
            {
                *ptr_totalP = (quantity * dressesP) - (quantity * dressesP * 0.1);
            }
            if (M == 11)
            {

                if (D >= 12)
                {
                    *ptr_totalP = (quantity * dressesP) - (quantity * dressesP * 0.1);
                }
                else
                {
                    printf("press 1 if you want to renew/reorder or any other value if you don't want to \n");
                    scanf("%d", &choice);
                    if (choice == 1)
                    {
                        *ptr_totalP = (quantity * dressesP) - (quantity * dressesP * 0.1) + 500;
                    }
                    else if (choice != 1)
                    {
                        *ptr_totalP = (quantity * dressesP);
                    }
                }
            }
        }
    }
    else if (card != 1)
    {
        int order;
        printf("press 1 if you want to order a loyalty card  or any other value if you don't\n");
        scanf("%d", &order);
        if (order == 1)
        {
            *ptr_totalP = (quantity * dressesP) - (quantity * dressesP * 0.1) + 500;
        }
        else
        {
            *ptr_totalP = (quantity * dressesP);
            printf("okay\n");
        }
    }
    if (quantity > 2)
    {
        *ptr_totalP = *ptr_totalP - *ptr_totalP * 0.1;
    }
    else
    {
        *ptr_totalP = *ptr_totalP;
    }
}

void fctsneakers(float* ptr_totalP)
{
    int type, Scount, quantity, sneakersP = 550;
    printf("please enter the quantity that you'd like to buy\n");
    scanf("%d", &quantity);
    printf(" press 1 if you're a wholsaler or any other value if you are individual buyer\n");
    scanf("%d", &type);
    *ptr_totalP = (float)sneakersP * quantity;
    if (type == 1)
    {
        printf("you have unlimited quantity \n");
        *ptr_totalP = (float)sneakersP * quantity;
    }
    else if (type != 1)
    {
        Scount += quantity;
        if (Scount <= 5)
        {
            *ptr_totalP = (float)sneakersP * Scount;
        }
        else
        {
            *ptr_totalP = (float)5 * sneakersP;
        }
    }
}