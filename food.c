
typedef enum ingredients { flour, sugar, salt, eggs, oil, bakingpowder, water} ingredient;
#define MAXINGREDIENTS 10

typedef insttype {
	char line[30];
} instructiontype;

typedef struct {
	ingredient in[MAXINGREDIENTS];
	float amount[MAXINGREDIENTS];
	int temperature;
	int cooktime;
	instructiontype instructions;
	char *origin;
	} recipe;

recipe book[5];

recipe * read_recipe(){
	recipe *rec = (recipe *) malloc(sizeof(recipe));
	rec->temperature = temp;
	rec->cooktime = time;
	return rec;
}



void main() {
	int i;
	for(i = 0; i< 5; i++) 
		read_recipe(&book[i]);
	
}