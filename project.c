#include <stdio.h>
#include <string.h>
void get_sentence();
int main()
{
    get_sentence();
    return 0;
}
void get_sentence()
{
    char para[20][200];
    char sample[200];
    int holder=0;
    printf("please enter a sentence here: \n");
    fgets(sample, sizeof(sample), stdin);
    for(int i=0;i<20;i++){
        for(int j=0;j<200;j++){
            para[i][j]=sample[holder];
            holder++;
            if(sample[holder]=='.'){
                break;
            }
        }
    }

    printf("\n%s", para[0]);
    printf("\n%s", para[1]);
    printf("\n%s", para[2]);
    printf("\n%s", sample);

}
