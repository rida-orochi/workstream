#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

struct animal {
	char  name[20];
	char question[80];
	short yes;
	short no;
	};
	
struct animal animals[1000] = {{"", "Does it have wings", 1, 2}, {"stork", "", 0, 0}, {"lion", "", 0, 0}};
int nextanimal = 3;

void main() {
	short done = FALSE;
	int current = 0;
	char answer[80];
	while (!done) {
		if(animals[current].name[0] == '\0') {
			printf("%s?", animals[current].question);
			scanf("%s", answer);
			if(answer[0] == 'y')
				current = animals[current].yes;
			else
				current = animals[current].no;
		// ask question
		}
		else {
		// guess
		printf("Is your animal a(n) %s?", animals[current].name);
		scanf("%s", answer);
		if(answer[0] == 'y') {
			printf("Thanks for playing!\n");
			done = TRUE; // you guessed!
		}
		else {
			// get a new 
			printf("What is your animal? ");
			scanf("%s", answer);
			strcpy(animals[nextanimal].name, answer);
			printf("Give me a questiion that will help telk the difference between a(n) %s and a(n) %s:", animals[current].name, 
						animals[nextanimal].name);
			scanf("%s", answer);
		}
	}}
}
	