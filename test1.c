// Test 1, Fall 2022, CSC 2302 01

// 1. Write C type definitions to represent Restaurants.  

// A Menu can have 
//		up to 30 different items, each of which has 
//			an item number, 
//			a description 
//			and a price. 

typedef struct {
	int itemNumber;
	char description[30];
	int price;
} MenuItem;

typedef struct  {
	MenuItem items[30];
	int numItems; // not specified, but useful to have
} Menu;

// A Restaurant has 
//		a name, 
//		a unique ID (just a number to tell the restaurants apart), 
//		an address, 
//		and a Menu. 
typedef struct {
	char name[20];
	int ID;
	char address[30];
	Menu menu;
} Restaurant;
	

// You can assume there will be a global variable “restaurants” 
// which contains an array of Restaurants, sorted by Restaurant ID.
#define MAXRESTAURANTS 20
Restaurant restaurants[MAXRESTAURANTS];

// 2. Write C type definitions to represent Clients. 

// An Order has 
//		an order id (in case the Client wants to order the same thing again tomorrow), 
//		Restaurant ID, 
//		and from 1 to 20 Items, each of which has 
//			an item number from that Restaurant’s Menu, 
//			and a quantity (how many of them did they order).

typedef struct orderitem OrderItem;
typedef struct order Order;	
struct orderitem {
	int itemNumber;
	int quantity;
};
struct order {
	int orderID;
	int restaurantID;
	OrderItem items[20];
	int numItems; // not specified but useful to have
};

// A Client has 
//		a first name, 
//		last name, 
//		address, 
//		and a set of Orders. 
typedef struct client Client;
struct client{
	char firstName[15];
	char lastName[15];
	char address[30];
	Order orders[20];
	int numOrders; // not specified, but useful to have
};

// 3. Write a function called saveclient that will take as parameters 
//		a filename 
//		and a Client; 
// it will write the data for that Client as text into the file specified.
void saveclient(char *filename, Client client){
	// This function is tedious, but not hard. 
	// Go through every element of the client, and print it in the file.
	FILE *file = fopen(filename, "w");
	int i, j;
	fprintf(file, "%s\n", Client.firstName);
	fprintf(file, "%s\n", Client.lastName);
	fprintf(file, "%s\n", Client.address);
	fprintf(file, "%d\n", Client.numOrders);
	// Print each order separately.
	for(i = 0; i < client.numOrders; i++){ // If you didn't have a "numOrders", print the whole array
		fprintf(file, "%s\n", Client.orders[i].orderID);
		fprintf(file, "%s\n", Client.orders[i].restaurantID);
		fprintf(file, "%d\n", Client.orders[i].numItems);
		// Print each item in this order.
		for(j = 0; j < client.orders[i].numItems; j++) { // If you did't have a "numItems", print the whole array
			fprintf(file, "%d %d\n", Client.orders[i].items[j].itemNumber,
									 Client.orders[i].items[j].quantity);
			}
		}
	fclose(file);
}


// 4. Write a function called gettotal that takes as parameters 
//		a pointer to a Client, 
//		and an order id. 
// It will look in the Orders for that client, find the Order specified, 
// and calculate and return the total cost of that order. 
int gettotal(Client *client, int orderID) {
	// This function is conceptually simple for a person to do, 
	// but more complicated to program.
	int i, cost = 0;
	Order *theOrder = NULL;
	Restaurant *theRestaurant = NULL;
	
	// Find the correct order, from the Client record.
	for(i = 0; i < client->numOrders; i++) 
		if(client->orders[i].orderID == orderID)
			theOrder = &client->orders[i];

	// Find the correct restaurant, from the global list of restaurants
	for(i = 0; i < MAXRESTAURANTS; i++) 
		if(restaurants[i].ID == theOrder->restaurantID)
			theRestaurant = &restaurants[i];

	// For each item in the order, find the quantity and the price.
	// The price needs to come from the corresponding item in the menu of the restaurant.
	for(i = 0; i < theOrder->numItems; i++) {
		int k, price;
		int quantity = theOrder->items[i].quantity;
		int menuItem = theOrder->items[i].itemNumber;
		for(k = 0; k < theRestaurant->menu.numItems; k++)
			if(theRestaurant->menu.items[k].itemNumber == menuItem)
				price = theRestaurant->menu.items[k].price;
		cost += quantity * price;
		}
		
	return cost;
}

// 5. Restaurant records are too large to write out as text data. 
// Write a function called getrestaurants that will take as parameter 
//		a filename 
//		and a number. 
// It will open a binary file by that name, and read the specified number of 
// Restaurant records into the global “restaurants” array, starting with “restaurants[0]” 
// and filling the array sequentially.
void getrestaurants(char *filename, int number){
	// This function is very, very simple!
	FILE *file = fopen(filename, "rb");
	fread(restaurants, sizeof(Restaurant), number, file);
	fclose(file);
}
