#include "push_swap.h"

int ft_min(int a, int b)
{
    return (a < b ? a : b);
}

int ft_max(int a, int b)
{
    return (a > b ? a : b);
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

void    find_max(t_stack **stack)
{
    t_elem  *cur;

    cur = (*stack)->first;
    while (cur != NULL)//max
    {
        if (cur->nb > (*stack)->max)
            (*stack)->max = cur->nb;
        cur = cur->next;
    }
    cur = (*stack)->first;
    while (cur != NULL)//max1
    {
        if (cur->nb > (*stack)->max1 && cur->nb != (*stack)->max)
            (*stack)->max1 = cur->nb;
        cur = cur->next;
    }
    cur = (*stack)->first;
    while (cur != NULL)//max2
    {
        if (cur->nb > (*stack)->max2 && cur->nb != (*stack)->max && cur->nb != (*stack)->max1)
            (*stack)->max2 = cur->nb;
        cur = cur->next;
    }
}