#include "push_swap.h"

void    free_stack(t_stack **stack)
{
    t_elem  *cur;
    t_elem  *aux;

    cur = (*stack)->first;
    while (cur)
    {
        aux = cur;
        cur = cur->next;
        free(aux);
    }
    (*stack)->first = NULL;
    free(stack);
}

void    ft_exit(int n, t_stack **stack_a, t_stack **stack_b)
{

    if (n >= 1)
        free_stack(stack_a);
    if (n >= 2)
        free_stack(stack_b);
    if (n <= 2)
    {
        write(2, "Error\n", 6);
        exit(EXIT_FAILURE);
    }
    if (n == 3)
        exit(EXIT_SUCCESS);
}