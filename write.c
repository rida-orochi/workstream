#include<stdio.h>
int main(){
    char storage[83];
    char holder[]={"this is the holder that will contain all the data that need to be stored in binary"};
    //creat a binary file:
    FILE*key=fopen("B_file.bin","wb");
    //write into it 
    fwrite(holder,1,sizeof(holder),key);
    fclose(key);
    //read from it 
    key=fopen("B_file.bin","rb");
    fread(storage,sizeof(storage),1,key);
    printf("\n%s",storage);
    fclose(key);
    return 0;
}