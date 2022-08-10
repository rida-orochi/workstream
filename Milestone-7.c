#include <stdio.h>
#include <string.h>

void show_source(int *a, int *b);
void show_destination(int *b, int *c);
void get_item_cost(float *e, int *f,int* c_s,int* c_d,float* c_p);
void total_cost(int d);
void print_bill(int w,float T ,float j,int c_s[], int c_d[], float c_p[]);
int main()
{
    int num;
    printf("plaese enter the number of places you want to visit: ");
    scanf("%d", &num);
    total_cost(num);
    return 0;
}
void show_source(int *a, int *b)
{
    int counter, source;
    printf("\nplease choose a source respecting our flight list bellow: \n");
    printf("\nCasablanca=1, \tParis=2,\tLondon=3,\tWashington, DC=4");
    printf("\n\n-source: ");
    scanf("%d", &source);
    *a = source;
    show_destination(a, b);
}
void show_destination(int *b, int *c)
{
    int destination;
    if (*b == 1)
    {
        printf("\nplesae select one of the available destinations for the source you have selected: ");
        printf(" \n\nparis=>2    London=>3    Washington, DC=>4    Brussels=>5");
    }
    else if (*b == 2)
    {
        printf("\nplesae select one of the available destinations for the source you have selected: ");
        printf(" \n\nCasablanca=>1      Munich=>6");
    }
    else if (*b == 3)
    {
        printf("\nplesae select one of the available destinations for the source you have selected: ");
        printf(" \n\nCasablanca=>1    paris=>2    Munich=>6");
    }
    else if (*b == 4)
    {
        printf("\nplesae select one of the available destinations for the source you have selected: ");
        printf(" \n\nCasablanca=>1    Los Angeles, CA=7");
    }
    printf("\n\n-destination: ");
    scanf(" %d", &destination);
    *c = destination;
}
void get_item_cost(float *e, int *f,int* c_s,int* c_d,float* c_p)
{
    *f = 0;
    int c, d;
    int *source_p = &c;
    int *destination_p = &d;
    show_source(source_p, destination_p);
    float price;
    int tickets;
    printf("\n please enter the number of tickts you want to purchase for this flight: ");
    scanf(" %d", &tickets);
    if (c == 1)
    {
        if (d == 2)
        {
            price = tickets * 1500;
        }
        else if (d == 3)
        {
            price = tickets * 3000;
        }
        else if (d == 4)
        {
            price = tickets * 9500;
        }
        else if (d == 5)
        {
            price = tickets * 1700;
        }
        else
        {
            printf("\n\t\tinvalid destination!!");
            printf("\nthe only possible destinations for this source are: \nparis=>2\tLondon=>3\tWashington, DC=>4,Brussels=>5");
            *f = 1;
        }
    }
    else if (c == 3)
    {
        if (d == 1)
        {
            price = tickets * 1200;
        }
        else if (d == 2)
        {
            price = tickets * 700;
        }
        else if (d == 6)
        {
            price = tickets * 2300;
        }
        else
        {
            printf("\n\t\tinvalid destination!!");
            printf("\nthe only possible destinations for this source are: \nCasablanca=>1\tParis=>2\tMunich=>6");
            *f = 1;
        }
    }
    else if (c == 4)
    {
        if (d == 7)
        {
            price = tickets * 2500;
        }
        else if (d == 1)
        {
            price = tickets * 6500;
        }
        else
        {
            printf("\n\t\tinvalid destination!!");
            printf("\nthe only possible destinations for this source are: \nLos Angeles, CA=>7\tCasablanca=>1");
            *f = 1;
        }
    }
    else if (c == 2)
    {
        if (d == 1)
        {
            price = tickets * 2400;
        }
        else if (d == 6)
        {
            price = tickets * 450;
        }
        else
        {
            printf("\n\t\tinvalid destination!!");
            printf("\nthe only possible destinations for this source are: \nCasablanca=>1\tMunich=>6");
            *f = 1;
        }
    }
    else if (c < 0 || c > 4)
    {
        printf("\n it seems like you have choosed an invalid source, please choose another one.");
        *f = 2;
    }
    *c_s=c;
    *c_d=d;
    *c_p=price;
    *e += price;

}
void total_cost(int d)
{
    int red_flag, counter = 1,current_source,current_destination,loop_holder=d;
    int *red_flag_P = &red_flag;
    int* current_source_P=&current_source;
    int* current_destination_P=&current_destination;
    float flights_sum = 0,current_price,Total=0;
    float *flights_sum_P = &flights_sum;
    float* current_price_P=&current_price;
    int source[100],destination[100];
    float price[50];

    while (d > 0)
    {
        printf("\n\t\t\t\t \\\\%d flight\\\\", counter);
        do
        {
            get_item_cost(flights_sum_P, red_flag_P,current_source_P,current_destination_P,current_price_P);
        } while (red_flag == 1 || red_flag == 2);
        red_flag = 0;
        source[(counter)-1]=current_source;
        destination[(counter)-1]=current_destination;
        price[((counter)-1)]=current_price;
        counter++;
        d--;
        
    }
    Total=flights_sum;
    if (flights_sum > 1500)
    {
        flights_sum = flights_sum - (flights_sum * 10) / 100;
        flights_sum = flights_sum + (flights_sum * 5) / 100;
    }
    else
    {
        flights_sum = flights_sum+(flights_sum * 5) / 100;
    }
    
    print_bill(loop_holder,Total,flights_sum,source,destination,price);
}
void print_bill(int w,float T ,float j,int c_s[], int c_d[], float c_p[])
{
    printf("\n-------------------- Items Purchased ---------------------------\n");
    printf("+Source\t\t\t+Destination\t\t+Price\n\n");
    for(int i=0;i<w;i++){
        printf("-source city: %d \t-destination: %d \t-cost: %.2f \n",c_s[i],c_d[i],c_p[i]);
    }
    printf("\n----------------------------------------------------------------\n");
    printf("\n-Total: %.2f MAD\n", T);
    printf("\n-Final Cost: %.2f MAD\n\n", j);
}