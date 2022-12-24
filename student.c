#include<stdio.h>
#include<string.h>
typedef struct{
    char name[20];
    int ID;
    float GPA;
}student;
void main(){
    student student1;    
    student student2;

    strcpy(student2.name,"Jacob");
    student2.ID=98004;
    student2.GPA=3.8;

    printf("please enter the name of your student: ");
    scanf("%s",student1.name);
    printf("please enter the ID of your student: ");
    scanf("%d",&student1.ID);
    printf("please enter the GPA of your student: ");
    scanf("%f",&student1.GPA);
    if(student1.GPA>student2.GPA){
        printf("-%d-%s: has the higher gpa",student1.ID,student1.name);
    }
    else printf("-%d-%s: has the higher gpa",student2.ID,student2.name);
}