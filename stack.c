#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"
#define STACKSIZE 35
struct stack {
Stackable item[STACKSIZE];
int top;
};
Stack *newStack() {
Stack *s = (Stack *) malloc (sizeof(Stack));
s->top = -1;
return s;
}
int isEmptyS(Stack *s) {
return s->top == -1;
}
int isFullS(Stack *s) {
return s->top == STACKSIZE - 1;
}
void pushS(Stack *s, Stackable item) {
if(isFullS(s)) return;
s->item[++(s->top)] = item;
}
Stackable popS(Stack *s) {
Stackable item;
if(isEmptyS(s)) return 0;
item = s->item[(s->top)--];
return item;
}
Stackable topS(Stack *s) {
Stackable item;
if(isEmptyS(s)) return 0;
item = s->item[s->top];
return item;
}
void printS(Stack *s){
int i;
//printf("Queue contains: ");
for(i = 0; i <= s->top; i++ )
printValue(s->item[i]);
printf("\n");
}