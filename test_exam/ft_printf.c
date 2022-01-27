#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

void    ft_putchar(int c, int *count)
{
    write(1, &c, 1);
    *count += 1;
}

void    ft_printhex(unsigned int n, int *count)
{
    if (n >= 16)
    {
        ft_printhex(n / 16, count);
        ft_printhex(n % 16, count);
    }
    if (n < 16)
    {
        if (n <= 9)
            ft_putchar(n + '0', count);
        if (n > 9)
            ft_putchar(n - 10 + 'a', count);
    }
}
void    ft_puthex(unsigned int n, int *count)
{
    if (n == 0)
    {
        write(1, "0", 1);
        *count += 1;
    }
    else
        ft_printhex(n, count);
}
void    ft_printnbr(int n, int *count)
{
    if (n > 9)
    {
        ft_printnbr(n / 10, count);
        ft_printnbr(n % 10, count);
    }
    if (n < 10)
    {
        ft_putchar(n + '0', count);
    }
}

void    ft_putnbr(int n, int *count)
{

    if (n == 0)
    {
        write(1, "0", 1);
        *count += 1;
    }
    if (n < 0)
    {
        write(1, "-", 1);
        *count += 1;
        n *= -1;
    }
    if (n > 0)
        ft_printnbr(n, count);
}

void    ft_putstr(char *str, int *count)
{
    int i;

    i = 0;
    if (str == NULL)
    {
        write(1, "(null)", 6);
        *count += 6;
    }
    while (str[i])
    {
        write(1, &str[i], 1);
        *count += 1;
        i++;
    }
}

void    ft_format(va_list args, char str, int *count)
{
    if (str == 's')
        ft_putstr(va_arg(args, char *), count);
    else if (str == 'd')
        ft_putnbr(va_arg(args, int), count);
    else if (str == 'x')
        ft_puthex(va_arg(args, unsigned int), count);
}

int ft_printf(const char *str, ...)
{
    va_list args;
    int count;
    int i;

    i = 0;
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
        {
            write(1, &str[i], 1);
            count++;
        }
        i++;
    }
    va_end(args);
    return (count);
}

int main(void)
{
    ft_printf("%x", 16);
    return (0);
}