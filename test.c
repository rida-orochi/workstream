#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// definning struct
typedef struct
{
    int number;
    char description[50];
    // supposing that the price is not an integer
    float price;
} items;
typedef struct
{
    char name[20];
    int ID;
    items Menu[30];
    // supposing that the address is a mixture of int and characters
    char address[40];
} restaurant;
restaurant restaurants[restaurants.ID];
typedef struct
{
    int I_number;
    int quantity;
} client_item;
typedef struct
{
    // supposing that the order id is an integer
    int order_id;
    int restaurant_id;
    client_item ordered_items[19];
} order;
typedef struct
{
    char first_name[20], last_name[20], address[40];
} clients;
void saveclient(FILE *fptr, clients *client);
// supposing that returned total won't be an integer
float gettotal(clients *client, order client_order);
void getrestaurants(FILE *fptr, int num);
int main()          
{
    return 0;
}
void saveclient(FILE *fptr, clients *client)
{
    if (!fptr)
    {
        fptr = fopen("specified.txt", "W");
        fclose(fptr);
    }
    fptr = fopen("specified.txt", "a");
    fprintf(fptr, "%s %s %S", client->first_name, client->last_name, client->address);
    fclose(fptr);
}
float gettotal(clients *client, order client_order)
{
    float total_cost;
    total_cost = ordered_items[client_order.order_id];
    return total_cost;
}
void getrestaurants(FILE *fptr, int num)
{
    if (!fptr)
    {
        fptr = fopen("specified.txt", "W");
        fclose(fptr);
    }
    fptr = fopen("specified.txt", "ab");
    fread(&restaurants,sizeof(restaurant),1,fptr);
}