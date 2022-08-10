#include <stdio.h>
int sequence(int x);
int main()
{
    int n;
    printf("please enter a number: ");
    scanf("%d", &n);
    sequence(n);
    

    return 0;
}
int sequence(int x){
    int num1, num2, result;
    num1 = 1;
    num2 = 1;
    printf("\n 1  1 ");
    while (x > 0)
    {
        result = num1 + num2;
        printf(" %d ", result);
        num1 = num2;
        num2 = result;
        x--;
    }
}