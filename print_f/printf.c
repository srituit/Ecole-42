#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
//#define va_arg(v,l) __builtin_va_arg(v,l)

//void    ft_printchar(char c, int *count);

/*void    ft_putnbr(unsigned int n, int *count)
{
    if (n > 9)
    {
        ft_putnbr(n / 10, count);
        ft_putnbr(n % 10, count);
    }
    if (n <= 9)
    {
        ft_printchar(n + '0', count);
    }
}

void    ft_printnbr(int n, int *count)
{
    unsigned int    nbr;

    nbr = n;
    if (nbr == 0)
        ft_printchar('0', count);
    if (nbr < 0)
    {
        ft_printchar('-', count);
        nbr *= -1;
    }
    if (nbr > 0)
    {
        ft_putnbr(nbr, count);
    }
}
*/
void    ft_printchar(int c, int *count)
{
    write(1, &c, 1);
    *count += 1;
}

void    ft_printstr(char *s, int *count)
{
    int i;

    i = 0;
    if (!s)
    {
        write(1, "(null)", 6);
        *count += 6;
    }
    while (s[i])
    {
        ft_printchar(s[i], count);
        i++;
    }
}

void    ft_format(va_list args, const char type, int *count)
{
    if (type == 's')
        ft_printstr(va_arg(args, char *), count);
//    else if (type == 'd')
//        ft_printnbr(va_arg(args, int), count);
//    else if (type == 'x')
//        ft_printhex(va_arg(args, unsigned int), count);
}

int     ft_printf(const char *str, ...)
{
    int i;
    va_list args;
    int count;

    i = 0 ;
    count = 0;
    va_start(args, str);
    while (str[i])
    {
        if (str[i] == '%')
        {
            ft_format(args, str[i + 1], &count);
            i++;
        }
        else
            ft_printchar(str[i], &count);
        i++;
    }
    va_end(args);
    return (count);
}

int main(void)
{
    printf("%s %d %s %s\n", "salut", 0, "Bonjour", "Rebonjour");
    ft_printf("%s %s %s %s\n", "sal", "tututu", "tatata", "kokoko");

    return (0);
}