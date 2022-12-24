#include <stdio.h>
typedef struct
{
    int kilometers;
    int meters;
} distance;
void main()
{
    distance D1, D2,sum;
    printf("please enter a distance in the following format : ");
    printf("\nKM: ");
    scanf("%d", &D1.kilometers);
    printf("M: ");
    scanf("%d", &D1.meters);

    printf("pleasee enter a second distance to be added to the first one: ");
    printf("\nKM: ");
    scanf("%d", &D2.kilometers);
    printf("M: ");
    scanf("%d", &D2.meters);
    sum.kilometers=D1.kilometers+D2.kilometers;
    sum.meters=D1.meters+D2.meters;
    if(sum.meters>999){
        sum.kilometers+=(sum.meters/1000);
        sum.meters=sum.meters%1000;
    }
    printf("%dKM%dM + %dKM%dM = %dKM%dM",D1.kilometers, D1.meters,D2.kilometers, D2.meters,sum.kilometers, sum.meters );
}