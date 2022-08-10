#include <stdio.h>
int main()
{
    int num;
    printf("please enter a number: ");
    scanf("%d", &num);
    switch (num)
    {
    case 1:
        printf("hello there m doing it ");
        break;
    case 2:
        printf("eyoo we are doing this");
        break;
    case 3:
        printf("things are going well");
        break;
    default:
        printf("bitch i did it");
    }
    return 0;
}