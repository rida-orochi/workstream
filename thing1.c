#include <stdio.h>
#include "thing2.c"
int main()
{
    int num1, num2, storage, visit_N,source,destination,counter=1;
    float grand_total;
    printf("please enter the number of destination you want to visit: ");
    scanf("%d", &num1);
    grand_total = 0;
    while (num1 > 0)
    {
        printf("\nplease choose a source and a destination respecting our flight list bellow: \n");
        printf("\nCasablanca=1,\tParis=2,\tLondon=3,\tWashington, DC=4,\tBrussels=5,\tMunich=6,\tLos Angeles, CA=7\n");
        printf("\nplease enter your %d source: ",counter);
        scanf("\n%d", &source);
        printf("\nplease enter your %d destination: ",counter);
        scanf("\n%d", &destination);
        printf("\nplease enter the number of times you want to visist this destination: ");
        scanf("%d", &num2);
        visit_N = num2;
        while (visit_N > 0)
        {
            do
            {
                storage = thing(source,destination);
                if (storage != 1)
                {
                    grand_total += storage;
                }
                printf("\nyour current total is: %.2f\n", grand_total);
            } while (storage == 1);
            visit_N--;
        }
        counter++;
        num1--;
    }
    grand_total=grand_total+(grand_total*5)/100;
    printf("your total after tax is : %.2f MAD",grand_total);
    return 0;
}