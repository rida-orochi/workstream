/*
Author": 98003, 100799
Date: 07-14-2022
pupose: performing a set of modifications on entered sentences depending on user choice(decryption-encryption... )
*/
#include<stdio.h>
#include<string.h>
int get_sentence();
void display_sentences(char* Pointer_1[]);
int select_sentence(char* Pointer_2[]);
void Encrypt_decrypt_all(char* Pointer_3[]);
int sentence_to_file(char* Pointer_4[]);
void sentence_from_file(char* Pointer_5[]);
int main(){ 
//creating file that will hold data later
    int flag;
    FILE*fptr;
    fptr=fopen("sentences.txt","w");
    fclose(fptr);
    get_sentence();
    return 0;
    }
int get_sentence(){
    int user_choice,flag;
    char para[20][200];
//resetting the array to length 0

    for(int i=0;i<=20;i++){
        strcpy(para[i],"");
    }
//getting data from user (filling the two dimentional array with sentences)
    
//creating pointer to be used later
    char* para_p=para[0];
    do{
        printf("\n\t-main menu:");
        printf("\nplease choose your operation: ");
        printf("\n1-enter sentences\n2-display sentnces\n3-work on selected sentence\n4-work on the whole entered paragraph\n5-save sentence to file\n6-load sentence from file\n7-quit the program\n");
        scanf("%d",&user_choice);
//enter sentence
        if(user_choice==1){
            for(int i=0;i<=20;i++){
                strcpy(para[i],"");
            }
            getchar();
            printf("\nplease enter the sentences you want to perform operation on: \n");
            printf("\nafter entering all your sentences press 'enter' twice\n");
            for(int i=0;i<20;i++){
                fgets(para[i],sizeof(para[i]),stdin);
                if(strlen(para[i])==1){
                    break;
                }
            }
        }
//display sentences
        else if(user_choice==2){
            display_sentences(&para_p);
        }
//work on selected sentences
        else if(user_choice==3){
            select_sentence(&para_p);
        }
//work on the whole paragraph at once
        else if(user_choice==4){
            Encrypt_decrypt_all(&para_p);
        }
//store data into file
        else if(user_choice==5){
            sentence_to_file(&para_p);
        }
//read the content of a file
        else if(user_choice==6){
            sentence_from_file(&para_p);
        }
//quit the program
        else if(user_choice==7){
        }
    }while(user_choice!=7);
    return 5;
}
void display_sentences(char* Pointer_1[]){  
    printf("\n\t-the sentences you have entered are: \n\n");
//loop too display each sentence in a new line
    for (int i = 0; i <= 20; i++)
    {
//condition to print sentence:
        if(strlen(Pointer_1[0]+(i*200))!=1){
            printf("\n%s",Pointer_1[0]+(i*200));
        }
//when to stop and break the loop:
        if(strlen(Pointer_1[0]+(i*200))==1){
            break;
        }
    }
    printf("\n\n");
}
int select_sentence(char* Pointer_2[]){
    printf("\nplease enter the number of the sentence you want to work on: \n");
    int sentence_number,container;
    scanf("%d",&sentence_number);
//case in which the sentence selected by the user is empty
    if(strlen(Pointer_2[0]+(sentence_number*200))<2){
        printf("\n it seems like the corresponding sentence for that number don't exist.");
        return 6;
    }
//case in which the sentence selected by the user isn't empty and ready to perform one of the given operations
    else if(strlen(Pointer_2[0]+(sentence_number*200))>1){
//leting the user select what kind of operation to be performed
        printf("\n\t-submenu:");
        printf("\nplease choose one of the following operations: ");
        printf("\n1-Display sentence\n2-Modify sentence\n3-Encrypt sentence\n4-Decrypt sentence\n5-Go back to the main menu\n");
        int user_choice;
        scanf("%d",&user_choice);
//Display sentence
        if(user_choice==1){
            sentence_number-=1;
            printf("\n-the sentences you have entered so far are: ");
            printf("\n%s",Pointer_2[0]+(sentence_number*200));
        }
//modify sentence
        else if(user_choice==2){ 
            char sentence_r[200];
            getchar();
            int reference=(sentence_number-1)*200;
            sentence_number-=1;
            printf("\n-the sentence you are now working on is: ");
            printf("\n%s",Pointer_2[0]+(sentence_number*200));
            printf("\nplease enter the new sentence: \n");
            fgets(sentence_r,sizeof(sentence_r),stdin);
            for(int i=0;i<strlen(sentence_r);i++){
                *(*(Pointer_2)+reference+i)=sentence_r[i];
            }
            printf("\n%s",Pointer_2[0]+(sentence_number*200));
        }
//Encrypt sentene
        else if(user_choice==3){
            int reference,sentence_length,shift_size,holder_2,flag;
            reference=(sentence_number-1)*200;
            sentence_length=strlen(Pointer_2[0]+reference);
//we need to know the sentence we are dealing with
            printf("\n-the sentence you are now working on is: ");
            printf("\n%s",Pointer_2[0]+reference);
//getting shift size from user
            printf("\n-please enter the encryption shift size: ");
            scanf("%d",&shift_size);
            if(shift_size>25||shift_size<1){
                printf("\ninvalid choice!!");
                printf("\nplease choose a size between 1 and 25 included:");
                return 5;
            }
//loop to go through all the characters
            for(int i=0;i<sentence_length;i++){
                holder_2=0;
//selecting alphabetic characters only 
                if((*(*(Pointer_2)+reference+i)>=97&&*(*(Pointer_2)+reference+i)<=122)||(*(*(Pointer_2)+reference+i)>=65&&*(*(Pointer_2)+reference+i)<=90)){
//flag to determine if the character is lower or upper
                    flag=*(*(Pointer_2)+reference+i);
                    *(*(Pointer_2)+reference+i)+=shift_size;
//upper-case characters
                    if(*(*(Pointer_2)+reference+i)>90&&flag<=90){
                        holder_2=*(*(Pointer_2)+reference+i)-90;
                        *(*(Pointer_2)+reference+i)=64+holder_2;
                    }
//lower-case characters
                    else if(*(*(Pointer_2)+reference+i)>122&&flag>=97){
                        holder_2=*(*(Pointer_2)+reference+i)-122;
                        *(*(Pointer_2)+reference+i)=96+holder_2;
                    }
                }
            }
            printf("\n%s\n",Pointer_2[0]+reference);
            
        }
//Decrypt sentence
        else if(user_choice==4){
            int reference,sentence_length,shift_size,holder_2,flag;
            reference=(sentence_number-1)*200;
            sentence_length=strlen(Pointer_2[0]+reference);
//we need to know the sentence we are dealing with
            printf("\n-the sentence you are now working on is: ");
            printf("\n%s",Pointer_2[0]+reference);
//getting shift size from user
            printf("\n-please enter the encryption shift size: ");
            scanf("%d",&shift_size);
            if(shift_size>25||shift_size<1){
                printf("\ninvalid choice!!");
                printf("\nplease choose a size between 1 and 25 included:");
                return 5;
            }
//reversing the encryption
            shift_size*=-1;
//loop to go through all the characters
            for(int i=0;i<sentence_length;i++){
                holder_2=0;
//selecting alphabetic characters only 
                if((*(*(Pointer_2)+reference+i)>=97&&*(*(Pointer_2)+reference+i)<=122)||(*(*(Pointer_2)+reference+i)>=65&&*(*(Pointer_2)+reference+i)<=90)){
//flag to determine if the character is lower or upper
                    flag=*(*(Pointer_2)+reference+i);
                    *(*(Pointer_2)+reference+i)+=shift_size;
//upper-case characters
                    if(*(*(Pointer_2)+reference+i)<65&&flag<=90){
                        holder_2=65-*(*(Pointer_2)+reference+i);
                        *(*(Pointer_2)+reference+i)=91-holder_2;
                    }
                    else if(*(*(Pointer_2)+reference+i)>122){
                                container=*(*(Pointer_2)+reference+i)-122;
                                *(*(Pointer_2)+reference+i)=96+container;
                    }
//lower-case characters
                    else if(*(*(Pointer_2)+reference+i)<97&&flag>=97){
                        holder_2=97-*(*(Pointer_2)+reference+i);
                        *(*(Pointer_2)+reference+i)=123-holder_2;  
                    }
                }
            }
//printing the decrypted sentence
            printf("\n%s\n",Pointer_2[0]+reference);
            
        }
//Go back to main menu
        else if(user_choice==5){
            get_sentence();
        }
    }
    
}
void Encrypt_decrypt_all(char* Pointer_3[]){
    int reference,shift_size,sentence_length,holder,flag,user_choice,container;
//setting value to created variables
//replace the values with i
    reference=1*200;
//getting input from user
    printf("\nwhat kind of operation do you want to perform on the text: ");
    printf("\n1-encrypt\n2-decrypt\n");
    scanf("%d",&user_choice);
    printf("\nplease enter the shift size: ");
    scanf("%d",&shift_size);
    if(shift_size>25||shift_size<1){
        printf("\ninvalid choice!!");
        printf("\nplease choose a size between 1 and 25 included:");
        return 5;
    }
//encrypt the wwhole paragraph
    if(user_choice==1){
        for(int i=0;i<=20;i++){
            reference=i*200;
            sentence_length=strlen(Pointer_3[0]+reference);
//print only the sentences entered by the user
            if(sentence_length>1){
//go through all the characters in an array
                for(int i=0;i<sentence_length;i++){
                    holder=0;
//sellect only the alphabetic characters to work on using ASCII NUMBER
                    if(((*(*(Pointer_3)+reference+i))>=97&&(*(*(Pointer_3)+reference+i))<=122)||((*(*(Pointer_3)+reference+i))>=65&&(*(*(Pointer_3)+reference+i))<=90)){
//serves to determine later if the character is upper or lower case
                        flag=*(*(Pointer_3)+reference+i);
//character chifting
                        *(*(Pointer_3)+reference+i)+=shift_size;
//upper-case characters over limit
                        if(*(*(Pointer_3)+reference+i)>90&&flag<=90){
                            holder=*(*(Pointer_3)+reference+i)-90;
                            *(*(Pointer_3)+reference+i)=64+holder;
                        }
//lower-case characters over limit
                        else if(*(*(Pointer_3)+reference+i)>122&&flag<=122){
                            holder=*(*(Pointer_3)+reference+i)-122;
                            *(*(Pointer_3)+reference+i)=96+holder;
                        }
                    }
                }
            }
        }
    }
//decrypt the wwhole paragraph
    else if(user_choice==2){
        for(int i=0;i<=20;i++){
            reference=i*200;
            sentence_length=strlen(Pointer_3[0]+reference);
            shift_size*=-1;
//print only the sentences entered by the user
            if(sentence_length>1){
//go through all the characters in an array
                for(int i=0;i<sentence_length;i++){
                    holder=0;
//sellect only the alphabetic characters to work on using ASCII NUMBER
                    if(((*(*(Pointer_3)+reference+i))>=97&&(*(*(Pointer_3)+reference+i))<=122)||((*(*(Pointer_3)+reference+i))>=65&&(*(*(Pointer_3)+reference+i))<=90)){
//serves to determine later if the character is upper or lower case
                        flag=*(*(Pointer_3)+reference+i);
//character chifting
                        *(*(Pointer_3)+reference+i)+=shift_size;
//upper-case characters over limit
                        if(*(*(Pointer_3)+reference+i)<65&&flag<=90){
                            holder= 65-*(*(Pointer_3)+reference+i);
                            *(*(Pointer_3)+reference+i)=91-holder;
                        }
//lower-case characters over limit
                        else if(*(*(Pointer_3)+reference+i)>122){
                                container=*(*(Pointer_3)+reference+i)-122;
                                *(*(Pointer_3)+reference+i)=96+container;
                            }
                        else if(*(*(Pointer_3)+reference+i)<97&&flag>=97){
                            
                            holder=97-*(*(Pointer_3)+reference+i);
                            *(*(Pointer_3)+reference+i)=123-holder;
                        }
                    }
                }
            }
        }
    }
    //print the final format
    for(int i=0;i<=20;i++){
        reference=i*200;
        if((strlen(Pointer_3[0]+reference))==1){
            break;
        }
        printf("\n%d-%s",i,Pointer_3[0]+reference);
        }
}
int sentence_to_file(char* Pointer_4[]){
    int position,sentence_L,reference,user_choice;
//file pointer
    FILE*fptr;
    fptr=fopen("sentences.txt","r");
    fclose(fptr);
//creating the file
    if(fptr==NULL){
        fptr=fopen("sentences.txt","r");
//closing so that i can see changes
        fclose(fptr);
    }
    fptr=fopen("sentences.txt","r");
    if(fptr!=NULL){
//allow writting in the file
        fptr=fopen("sentences.txt","r");
        fseek(fptr, 0,SEEK_END);
        position= ftell(fptr);
        fclose(fptr);
//if the file contain no content
        if(position==0){
            fptr=fopen("sentences.txt","w");
            for(int i=0;i<20;i++){
                reference=i*200;
                sentence_L=strlen(Pointer_4[0]+reference);
                if(sentence_L>1){
                    fprintf(fptr,"%s",Pointer_4[0]+reference);
                }
            }
//closing the file so that i can see changes
            position= ftell(fptr);
            fclose(fptr);
            fptr=fopen("sentences.txt","r");
            fseek(fptr, 0,SEEK_END);
            position= ftell(fptr);
            fclose(fptr);
            return 5;
        }

        if(position>0){
            printf("\n-it seems like your file already contain data\n-do you agree to overwriting it:\n1-Yes\n2-No\n ");
            scanf("%d",&user_choice);
            if(user_choice==1){
                fptr=fopen("sentences.txt","w");
                for(int i=0;i<20;i++){
                    reference=i*200;
                    sentence_L=strlen(Pointer_4[0]+reference);
                    if(sentence_L>1){
                        fprintf(fptr,"%s",Pointer_4[0]+reference);
                    }
                }
                position= ftell(fptr);
                fclose(fptr);
                return 5;
            }
            else if(user_choice==2){
                printf("\nnice choice");
            }
        }
    }
}
void sentence_from_file(char* Pointer_5[]){
    char display_screen[20][200];
    FILE*fptr;
    getchar();
    fptr=fopen("sentences.txt","r");
    for(int i=0;i<20;i++){
        fgets(display_screen[i], sizeof(display_screen[i]),fptr);
    }
    fclose(fptr);
    printf("\n\t-this is the content of the file: \n");
    for (int i=0;i<20;i++)
    {
        printf("%s",display_screen[i]);
        if(sizeof(display_screen[i])<1){
            break;
        }
    }
    
}
