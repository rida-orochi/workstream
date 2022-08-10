#include<stdio.h>
int main(){
    int arr1[20], holder=0,index,avg;
    float arr2[20];
    printf("please enter the id and the gpa of each student: ");
    for(int i=0; i<20; i++){
        scanf("%d\n", &arr1[i]);
        scanf(" %d",&arr2[i]);
    }
    for(int t=0; t<20;t++){
        printf("\n %d - %d", arr1[t], arr2[t]);
    }
    for(int n; n<20; n++){
        if(holder<arr2[n]){
            holder=arr2[n];
            if(holder==arr2[n]){
                index=n;
            }
        }
    }
    printf("\n the student with the highest gpa %d", arr1[index]);
    avg+=arr2[index];
    for(int n; n<20; n++){
        if(holder>arr2[n]){
            holder=arr2[n];
            if(holder==arr2[n]){
                index=n;
            }
        }
    }
    printf("\n the student with the lowest gpa %d", arr1[index]);
    avg+=arr2[index];
    avg/=2;
    printf("\n the class average is: %d", avg);
    return 0;
}
//i think that it's all about the run time that needs to be minimised
