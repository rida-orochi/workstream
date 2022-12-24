#include <stddef.h>
#include "edit.h"
typedef struct edit *Stackable;
#define STACKFORMAT "%c "
// void printValue(Stackable item) {printf(STACKFORMAT, item);}
typedef struct stack Stack;
Stack *newStack();
int isEmptyS(Stack *s);
int isFullS(Stack *s);
void pushS(Stack *s, Stackable item);
Stackable popS(Stack *s);
Stackable topS(Stack *s);
void printS(Stack *s);