#include "edit.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#define VERBOSE 0
struct edit {
char op; // could be 'i', 'a', 'd', or 'r'
int start, end;
char *string;
};
Stack *undoStack;
Stack *redoStack;
// The global variable that contains the current text
char string[80];
// 
void initText(char *text) {
if(VERBOSE) printf("--> initializing to: %s\n", text);//condition for opptional print
strcpy(string, text);
undoStack = newStack();
redoStack = newStack();
if(VERBOSE) printText();
}
void printText(){
printf("%s\n", string);
}
void printStacks() {
printf("Undo stack: "); printS(undoStack);
printf("Redo stack: "); printS(redoStack);
}
void printValue(Edit *e){
printf("%c ", e->op);
} 
void insertText(int position, char *text) {
char temp[50];
Edit *rec = (Edit *) malloc(sizeof(Edit));
if(VERBOSE) printf("--> inserting at position %d: %s\n", position, text);
strcpy(temp, string+position);
strncpy(string+position, text, strlen(text));
strcpy(string+position+strlen(text), temp);
rec->op = 'd';
rec->start = position;
rec->end = position+strlen(text)-1;
pushS(undoStack, rec);
if(VERBOSE) printText();
if(VERBOSE) printStacks();
}
void appendText(char *text) {
Edit *rec = (Edit *) malloc(sizeof(Edit));
if(VERBOSE) printf("--> appending: %s\n", text);
rec->op = 'd';
rec->start = strlen(string);
rec->end = strlen(string) + strlen(text);
strcat(string, text);
pushS(undoStack, rec);
if(VERBOSE) printText();
if(VERBOSE) printStacks();
}
void deleteText(int start, int end) {
char temp1[50], temp2[50];
Edit *rec = (Edit *) malloc(sizeof(Edit));
int length = end - start + 1;
if(VERBOSE) printf("--> deleting from %d to %d\n", start, end);
strcpy(temp1, string+end+1);
strncpy(temp2, string+start, length);
temp2[length] = 0;
strcpy(string+start, temp1);
rec->op = 'i';
rec->start = start;
rec->string = (char *)malloc(strlen(temp2)+1);
strcpy(rec->string, temp2);
pushS(undoStack, rec);
if(VERBOSE) printText();
if(VERBOSE) printStacks();
}
void replaceText(int start, int end, char *text) {
char temp1[50], temp2[50];
Edit *rec = (Edit *) malloc(sizeof(Edit));
int length = end-start+1;
if(VERBOSE) printf("--> replacing from %d to %d with: %s\n", start, end, 
text);
strcpy(temp1, string+end+1);
strncpy(temp2, string+start, length);
temp2[length] = 0;
strcpy(string+start, text);
strcat(string, temp1);
rec->op = 'r';
rec->start = start;
rec->end = start+strlen(text)-1;
rec->string = (char *)malloc(strlen(temp2)+1);
strcpy(rec->string, temp2);
pushS(undoStack, rec);
if(VERBOSE) printText();
if(VERBOSE) printStacks();
}
void apply(Edit *event) {
switch(event->op) {
case 'a': appendText(event->string); break;
case 'i': insertText(event->start, event->string); break;
case 'd': deleteText(event->start, event->end); break;
case 'r': replaceText(event->start, event->end, event->string); break;
}
}
void undo() {
Edit *e = popS(undoStack);
if(e == NULL) return;
if(VERBOSE) printf("undoing last change (ignore first stack report)\n");
apply(e);
e = popS(undoStack);
pushS(redoStack, e);
if(VERBOSE) printStacks();
}
void redo() {
Edit *e = popS(redoStack);
if(e == NULL) return;
if(VERBOSE) printf("redoing last change\n");
apply(e);
}
