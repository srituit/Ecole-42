#include <stdio.h>

int main(int argc, char **argv)
{
    int i;

    i = 0;
    while (argv[1][i])
    {
        if (argv[1][i] == "\n")
            argv[1][i] = " ";
    }
    return (0);
}