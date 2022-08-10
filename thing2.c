#include <stdio.h>
float thing(int x,int y){
    float price, total;
    int tickets;
    int Casablanca=1,Paris=2,London=3,Washington_DC=4,Brussels=5,Munich=6,Los_Angeles_CA=7;
    int destination, source;
    printf("\nplease enter the number of tickets you want to purchase this time: ");
    scanf("\n%d",&tickets);
    source=x;
    destination=y;
    if(source ==1){
        if (destination==2)
        {
            price=tickets*1500;
        }
        else if (destination==3)
        {
            price=tickets*3000;
        }
        else if (destination==4)
        {
            price=tickets*9500;
        }
        else if (destination==5)
        {
            price=tickets*1700;
        }
        else{
            printf("\n\t\tinvalid destination!!");
            printf("\nthe only possible destinations for this source are: \nparis=>2\tLondon=>3\tWashington, DC=>4\tBrussels=>5");
            return 1;
        }
    }
    else if (source ==3)  
    {
        if (destination==1)
        {
            price=tickets*1200;
        }
        else if (destination==2)
        {
            price=tickets*700;
        }
        else if (destination==6)
        {
            price=tickets*2300;
        }
        else{
            printf("\n\t\tinvalid destination!!");
            printf("\nthe only possible destinations for this source are: \nCasablanca=>1\tParis=>2\tMunich=>6");
            return 1;
        }
    }
    else if (source ==4)
    {
        if (destination==7)
        {
            price=tickets*2500;
        }
        else if (destination==1)
        {
            price=tickets*6500;
        }
        else{
            printf("\n\t\tinvalid destination!!");
            printf("\nthe only possible destinations for this source are: \nLos Angeles, CA=>7\tCasablanca=>1");
            return 1;
        }
    }
    else if (source ==2)
    {
        if (destination==1)
        {
            price=tickets*2400;
        }
        else if (destination==6)
        {
            price=tickets*450;
        }
        else{
            printf("\n\t\tinvalid destination!!");
            printf("\nthe only possible destinations for this source are: \nCasablanca=>1\tMunich=>6");
            return 1;
        }
    }
    else if (source<0|| source>4){
        printf("\n it seems like you have choosed an invalid source, please choose another one.");
        return 1;
    }
    total=price;
    return total;
}
