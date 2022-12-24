typedef struct edit Edit;
// Editing operations: 
void initText(char *text);
void printText();
void printStacks();
void insertText(int position, char *text);
void appendText(char *text);
void deleteText(int start, int end);
void replaceText(int start, int end, char *text);
void undo();
void redo();
void printValue(Edit *);