#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    char    *statut;

    statut = "oui\0";
    printf("%s", statut);
    printf("%d", -1 % 15);
    if (argc == 2)
    {
        write(2, "error\n", 6);
    }
    if (argc == 1)
        write(1,"good\n", 5);
    else if (argc == 3)
        write(2, "error1\n", 7);
    else if (argc == 4)
        write(2, "error2\n", 7);
    else
        write(2,"Hello\n", 7);
    return (0);
}