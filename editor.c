
// Editing operations: 
// initText(char *text);
// insertText(int position, char *text)
// appendText(char *text)
// deleteText(int start, int end)
// replaceText(int start, int end, char *text)
#include <stdio.h>
#include <string.h>
#include "edit.h"
void main() {
initText("123456789");
printf("Initial text is: ");
printText();
insertText(3, "abc");
appendText("end");
deleteText(4, 8);
replaceText(2, 3, "new");
printf("Text after all modifications is: ");
printText();
undo();
undo();
undo();
undo();
printf("Text after undoing all modifications is: ");
printText();
redo();
undo();
printf("Text after redoing and undoing one modification is: ");
printText();
redo();
redo();
redo();
redo();
printf("Text after redoing all modifications is: ");
printText();
}
void play() {
printf("What action? ");
// select location -> enter a number
// insert -> type text at current location
// block -> delete, copy, replace, cut
// (saved text) -> insert
}
