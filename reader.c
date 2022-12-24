#include<stdio.h>
#include<string.h>
int main(){
    //creating the characters that will store the  data
    char phrase1[8], phrase2[9];
    int number;
    //we need to open the file to read forom it 
    FILE*task;
    task=fopen("98003.bin","rb");
    //setting the pointer to read from the beginning
    //were will we put that data that need to be read
    fread(&phrase1,sizeof(phrase1),1,task);
    fclose(task);
    printf("==> %s",phrase1);
    return 0;
}