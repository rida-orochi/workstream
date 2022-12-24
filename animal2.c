#include <stdio.h>
#include <string.h>
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

int current = 0;
int lastquestion = 0;
short lastchoiceyes = 0;
char answer[80];
	
void ask_question() {
	printf("%s?", animals[current].question);
	scanf("%s", answer);
	lastquestion = current;
	if(*answer == 'y') {
		current = animals[current].yes;
		lastchoiceyes = TRUE;
	}
	else {
		current = animals[current].no;
		lastchoiceyes = FALSE;
	}
}

void guess() {
		printf("Is your animal a(n) %s?", animals[current].name);
		scanf("%s", answer);
		if(*answer == 'y') {
			printf("Thanks for playing!\n");
			// you guessed!
		}
		else {
			// get a new question. We need to know:
			//	1. The previous question, which led us to the current animal: lastquestion
			//		Whether the previous answer that led here was "yes" or "no": lastchoiceyes
			//	2. The old (incorrect) animal: current
			int oldanimal = current;
			//	3. The name of the new animal: to be put in animals[nextanimal]
			int newanimal = nextanimal++;
				// Get the name of the new animal.
			printf("What is your animal? ");
			scanf("%s", answer);
			strcpy(animals[newanimal].name, answer);
			
			//  4. The new question: to be put in animals[nextanimal+1]
			int newquestion = nextanimal++;
			animals[newquestion].name[0] = '\0';
			
				// (link the last question asked to this new question)
			if(lastchoiceyes) 	
				animals[lastquestion].yes = newquestion;
			else
				animals[lastquestion].no = newquestion;
			
				// (read the new question)
			printf("Give me a question that will help tell the difference between a(n) %s and a(n) %s:", 
				animals[oldanimal].name, animals[newanimal].name);
			getchar();	// Read the previous newline character.
			gets(answer); // Note: input is a line of text, not just one word!
			strcpy(animals[newquestion].question, answer);
			
			//  5. Whether a "yes" or "no" answer to the new question will lead us to the new animal
			printf("Will the answer to your question be YES for a %s?", animals[newanimal].name);
			scanf("%s", answer);
			if(*answer == 'y') {
				animals[newquestion].yes = newanimal;
				animals[newquestion].no = oldanimal;
			}
			else {
				animals[newquestion].yes = oldanimal;
				animals[newquestion].no = newanimal;
			}
			
		}
}

void main() {
	short done = FALSE;

	while (!done) {
		if(animals[current].name[0] == '\0') 
			// The current record is a question, not an animal.
			ask_question();
		else {
			// This is an animal, so guess that it is right.
			// If it isn't get the new animal and question.
			guess();
			
			// After guessing, either end the game or start over at the beginning, with the first question.
			printf("Do you want to play again? ");
			scanf("%s", answer);
			if(*answer == 'y') current = 0;
			else
				done = TRUE;
		}
	}
}
	