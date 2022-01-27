#include "my_first_prog.h"

char    *str_cut(char *str, int s)
{

}

int ft_atoi(char *s)
{
    int i;
    int res;

    res = 0;
    i = 0;
    while (s[i])
    {
        res = res * 10 + (s[i] - '0');
        i++;
    }
    return (res);
}

char    *str_cpy(char *str, int i)
{
    char    *nom;
    int     j;
    int     k;

    j = i;
    k = 0;
    while (str[i] && str[i] != '\n')
    {
        k++;
        i++;
    }
    nom = malloc(sizeof(char) * k + 1);
    k = 0;
    while (str[j] && str[j] != '\n')
    {
        nom[k] = str[j];
        j++;
        k++;
    }
    nom[k] = '\0';
    return (nom);
}
int     str_str(char *str, char *to_find)
{
    int i;
    int j;

    i = str_len(str);
    while (i >= 0)
    {
        j = 0;
        while (str[i + j] == to_find[j])
        {
            if (to_find[j + 1] == '\0')
                return (i);
            j++;
        }
        i--;
    }
    return (0);
}

void    ft_printnbr(long int n, int fd)
{
    int nbr;

    if (n > 9)
    {
        ft_printnbr(n / 10, fd);
        ft_printnbr(n % 10, fd);
    }
    else if (n <= 9)
    {
        nbr = n + '0';
        write(fd, &nbr, 1);
    }

}

void    ft_putnbr(int n, int fd)
{
    long int nbr;

    nbr = n;
    if (nbr == 0)
        write(fd, "0", 1);
    if (nbr < 0)
    {
        write(fd, "-", 1);
        nbr *= -1;
    }
    if (nbr > 0)
        ft_printnbr(nbr, fd);
}

int str_len(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}