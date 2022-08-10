#include <stdio.h>
int Show_sources();
int show_destination(int x);
float get_item_cost(int a, int b);
float get_total_cost(int i);
int print_bill(float j);
int main()
{
    int places, source, destination;
    float total;
    printf("please enter the number of destination you want to visit: ");
    scanf(" %d", &places);
    print_bill(get_total_cost(places));
    return 0;
}
int Show_sources()
{
    int counter, source;
    printf("\nplease choose a source respecting our flight list bellow: \n");
    printf("\nCasablanca=1, \tParis=2,\tLondon=3,\tWashington, DC=4");
    printf("\n\n-source: ");
    scanf("\n%d", &source);
    return source;
}
int show_destination(int x)
{
    int destination;
    if (x == 1)
    {
        printf("\nplesae select one of the available destinations for the source you have selected: ");
        printf(" \n\nparis=>2    London=>3    Washington, DC=>4    Brussels=>5");
    }
    else if (x == 2)
    {
        printf("\nplesae select one of the available destinations for the source you have selected: ");
        printf(" \n\nCasablanca=>1      Munich=>6");
    }
    else if (x == 3)
    {
        printf("\nplesae select one of the available destinations for the source you have selected: ");
        printf(" \n\nCasablanca=>1    paris=>2    Munich=>6");
    }
    else if (x == 4)
    {
        printf("\nplesae select one of the available destinations for the source you have selected: ");
        printf(" \n\nCasablanca=>1    Los Angeles, CA=7");
    }
    printf("\n\n-destination: ");
    scanf(" %d", &destination);
    return destination;
}
float get_item_cost(int a, int b)
{
    float price;
    int tickets;
    printf("\n please enter the number of tickts you want to purchase for this flight: ");
    scanf(" %d", &tickets);
    if (a == 1)
    {
        if (b == 2)
        {
            price = tickets * 1500;
        }
        else if (b == 3)
        {
            price = tickets * 3000;
        }
        else if (b == 4)
        {
            price = tickets * 9500;
        }
        else if (b == 5)
        {
            price = tickets * 1700;
        }
        else
        {
            printf("\n\t\tinvalid destination!!");
            printf("\nthe only possible destinations for this source are: \nparis=>2\tLondon=>3\tWashington, DC=>4,Brussels=>5");
            return 1;
        }
    }
    else if (a == 3)
    {
        if (b == 1)
        {
            price = tickets * 1200;
        }
        else if (b == 2)
        {
            price = tickets * 700;
        }
        else if (b == 6)
        {
            price = tickets * 2300;
        }
        else
        {
            printf("\n\t\tinvalid destination!!");
            printf("\nthe only possible destinations for this source are: \nCasablanca=>1\tParis=>2\tMunich=>6");
            return 1;
        }
    }
    else if (a == 4)
    {
        if (b == 7)
        {
            price = tickets * 2500;
        }
        else if (b == 1)
        {
            price = tickets * 6500;
        }
        else
        {
            printf("\n\t\tinvalid destination!!");
            printf("\nthe only possible destinations for this source are: \nLos Angeles, CA=>7\tCasablanca=>1");
            return 1;
        }
    }
    else if (a == 2)
    {
        if (b == 1)
        {
            price = tickets * 2400;
        }
        else if (b == 6)
        {
            price = tickets * 450;
        }
        else
        {
            printf("\n\t\tinvalid destination!!");
            printf("\nthe only possible destinations for this source are: \nCasablanca=>1\tMunich=>6");
            return 1;
        }
    }
    else if (a < 0 || a > 4)
    {
        printf("\n it seems like you have choosed an invalid source, please choose another one.");
        return 2;
    }
    return price;
}
float get_total_cost(int i)
{
    float flights_sum = 0, red_flag; 
    int c, d,counter=1;
    while (i > 0)
    {
        printf("\n\t\t\t\t \\\\%d flight\\\\",counter);
        do
        {
            c = Show_sources();
            d = show_destination(c);
            red_flag = get_item_cost(c, d);
            
        } while (red_flag==1||red_flag==2);
        flights_sum += red_flag;
        counter++;
        i--;
    }
    if (flights_sum > 1500)
    {
        flights_sum = flights_sum - (flights_sum * 10) / 100;
        flights_sum = flights_sum + (flights_sum * 5) / 100;
    }
    else
    {
        flights_sum = (flights_sum * 5) / 100;
    }
    return flights_sum;
}
int print_bill(float j)
{
    printf("\n the amount you must pay is: %.2f", j);
    return 0;
}