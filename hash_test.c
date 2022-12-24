/*
Authorship: Rida Allah Jaija,
Purpose: Start with a fixed set of data from your name.
-- Create a hash function that will insert each of these values into a different place in an array of 15 strings.
-- Use your hash function to insert your strings into an array, printing the array after each insertion, using the hashtest.c program given in Canvas.
-- You are providing the functions insertTable, printTable, and findTable. insertTable and findTable should print a message every time there is a collision.
Date: December 11, 2022
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tableSize 15
#define stringsize 4
char hash_table[tableSize][stringsize];
int hash=0;
char *mystrings[] = {"rid","ida","daa","aal","all","lla","lah","ahj","hjr","jri"}; // add your strings here
void insertTable(char *s){
    hash=0;
    int prob_num=0;
    /*
    -I kept on trying multiple different hashing functions, but the nember of
    collisions was high beacuse i have multiple strings with the same combinition 
    of letters.
    -since that we need to minimise the number of collisions to make the hash table more efficient, i chose the one that gave me the least amount of collisions.
    -that's the reason why I am using the following hashing function 
    =>[hash+=(((((int)s[1])*2302)/9)^(i*(int)s[2]))^(5+i);]
    */
    for(int i=0;i<strlen(s);i++){
        hash+=(((((int)s[1])*2302)/9)^(i*(int)s[2]))^(5+i);
    }
    hash=hash%tableSize;
    while(strlen(hash_table[hash])!=0&& prob_num<tableSize){
        hash=(hash+1)%tableSize;
        printf("\na collision is happening while inserting the string!!\n");
        prob_num++;
    }
    if(prob_num<tableSize&&hash<tableSize){
        strcpy(hash_table[hash],s);
    }
    else printf("\nsomething went wrong");
}
void printTable(){
    printf("\n");
    hash=0;
    int prob_num=0,location;
    for(int i=0;i<stringsize;i++){
        hash+=(((((int)(**mystrings+1))*2302)/9)^(i*(int)(**mystrings+2)))^(5+i);
        hash=hash%tableSize;
    }
    for(int i=0;i<tableSize;i++){
        if((strcmp(hash_table[hash],*mystrings+((i+1)*i))!=0&&prob_num<tableSize)){
            hash=(hash+1)%tableSize;
            prob_num++;
        }
        printf("-%s ",hash_table[hash]);
    }
    printf("\n");
}
int findTable(char *s){
    hash=0;
    int prob_num=0;
    for(int i=0;i<strlen(s);i++){
        hash+=(((((int)s[1])*2302)/9)^(i*(int)s[2]))^(5+i);
    }
    hash=hash%tableSize;
    while((strcmp(hash_table[hash],s))!=0&& prob_num<tableSize){
        hash=(hash+1)%tableSize;
        printf("\na collision is happening while looking for the string!!\n");
        prob_num++;
    }
    if(prob_num<tableSize&&hash<tableSize){
        return hash;
    }
}
void main()
{
    int i;
    for (i = 0; i < 10; i++)    
    {
        
        insertTable(mystrings[i]);
        printTable();
    }
    printf("%s is at location %d\n", mystrings[0], findTable(mystrings[0])); 
    printf("%s is at location %d\n", mystrings[1], findTable(mystrings[1]));
    printf("%s is at location %d\n", mystrings[2], findTable(mystrings[2]));  
    printf("%s is at location %d\n", mystrings[3], findTable(mystrings[3]));  
    printf("%s is at location %d\n", mystrings[4], findTable(mystrings[4]));  
    printf("%s is at location %d\n", mystrings[5], findTable(mystrings[5]));
    printf("%s is at location %d\n", mystrings[6], findTable(mystrings[6]));  
    printf("%s is at location %d\n", mystrings[7], findTable(mystrings[7]));  
    printf("%s is at location %d\n", mystrings[8], findTable(mystrings[8]));
    printf("%s is at location %d\n", mystrings[9], findTable(mystrings[9]));
}
