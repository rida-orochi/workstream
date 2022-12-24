#include <stdio.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

typedef struct animal animalrec;

struct animal {
	char  name[20];
	char question[80];
	animalrec *yes;
	animalrec *no;
	};
	
struct animal animals[1000] = {{"", "Does it have wings", &animals[1], &animals[2]}, {"stork"}, {"lion"}};
int nextanimal = 3;

animalrec * current = animals;
animalrec * lastquestion = NULL;
short lastchoiceyes = 0;
char answer[80];
	
void ask_question() {
	printf("%s? ", current->question);
	scanf("%s", answer);
	lastquestion = current;
	if(*answer == 'y') {
		current = current->yes;
		lastchoiceyes = TRUE;
	}
	else {
		current = current->no;
		lastchoiceyes = FALSE;
	}
}

void guess() {
		printf("Is your animal a(n) %s?", current->name);
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
			animalrec *oldanimal = current;
			//	3. The name of the new animal: to be put in animals[nextanimal]
			animalrec *newanimal = &animals[nextanimal++];
				// Get the name of the new animal.
			printf("What is your animal? ");
			scanf("%s", answer);
			strcpy(newanimal->name, answer);
			
			//  4. The new question: to be put in animals[nextanimal+1]
			animalrec *newquestion = &animals[nextanimal++];
			newquestion->name[0] = '\0';
			
				// (link the last question asked to this new question)
			if(lastchoiceyes) 	
				lastquestion->yes = newquestion;
			else
				lastquestion->no = newquestion;
			
				// (read the new question)
			printf("Give me a question that will help tell the difference between a(n) %s and a(n) %s: ", 
				oldanimal->name, newanimal->name);
			getchar();	// Read the previous newline character.
			gets(answer); // Note: input is a line of text, not just one word!
			strcpy(newquestion->question, answer);
			
			//  5. Whether a "yes" or "no" answer to the new question will lead us to the new animal
			printf("Will the answer to your question be YES for a %s? ", newanimal->name);
			scanf("%s", answer);
			if(*answer == 'y') {
				newquestion->yes = newanimal;
				newquestion->no = oldanimal;
			}
			else {
				newquestion->yes = oldanimal;
				newquestion->no = newanimal;
			}
			
		}
}

void main() {
	short done = FALSE;

	while (!done) {
		if(current->name[0] == '\0') 
			// The current record is a question, not an animal.
			ask_question();
		else {
			// This is an animal, so guess that it is right.
			// If it isn't get the new animal and question.
			guess();
			
			// After guessing, either end the game or start over at the beginning, with the first question.
			printf("Do you want to play again? ");
			scanf("%s", answer);
			if(*answer == 'y') current = animals;
			else
				done = TRUE;
		}
	}
}
	