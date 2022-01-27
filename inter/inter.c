#include <unistd.h>

int main(int argc, char **argv)
{
    int alpha[128];
    int j;
    int i;
    int s;

    if (argc == 3)
    {
        i = 0;
        while (i < 128)
            alpha[i++] = 0;
        i = 2;
        while (i > 0)
        {
            j = 0;
            while (argv[i][j])
            {
                s = argv[i][j];
                if (i == 2 && alpha[s] == 0)
                    alpha[s] = 1;
                else if (i == 1 && alpha[s] == 1)
                {
                    write(1, &argv[i][j], 1);
                    alpha[s] = 0;
                }
                j++;

            }
            i--;
        }
    }
    write (1, "\n", 1);
    return (0);
}