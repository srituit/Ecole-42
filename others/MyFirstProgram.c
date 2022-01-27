#include <stdio.h>

int main(void)
{
    char    name[15];
    int     age;
    char    answer[4];
    char    is_yes[4] = "yes";

    printf("\nwhat is your name?");
    scanf("%s", name);

    printf("\nYour name is %s? [y] / [n]", name);
    scanf("%s", answer);
    printf("%s", answer);
    if (answer[0] == is_yes[0])
        printf("ok");
    else if (answer == "no")
        printf("try again");
    printf("\nWhat is your age?");
    scanf("%d", age);

    if (age > 17)
    {
        printf("what is your age?\n");
        scanf("%d", age);
        printf("Your age is %d?", age);
    }
    else if (age < 19)
    {
        printf("what is your name?\n");
        scanf("%s", name);
    }

    return (0);
}