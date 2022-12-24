#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
//first structure(inner one)
typedef struct{
	int number;
	float holder;
	char sentence[30];
}example;
//second structure(outer one)
typedef struct 
{
    int display;
    example bottle;
}outer;
//function declaration
outer*book(outer*item);
example* present(example*thing );
example* show(example*indicator);
//main function
void main(){
    outer pen;
    //making a pointer out of the outer struct
    outer *arrow=&pen;
    //defining one of the structs
	example sample={999,3.99,"lorem ipsum"};
    //making a pointer out of the inner struct
	example *Sptr=&sample;
    //calling the functions
    present(Sptr);
    show(Sptr);
    book(arrow);
    //juat a simple print
    printf("\n %d",pen.bottle.number);
}
//definition of the previously declared function 
example* present(example*thing ){
    thing->number=777;
    thing->holder=9.999;
    strcpy(thing->sentence,"hello there");
	return thing;
}
example* show(example*indicator){
    printf("%d %.2f %s", indicator->number,indicator->holder,indicator->sentence);
}
outer*book(outer*item){
    item->bottle.number=6666;
}