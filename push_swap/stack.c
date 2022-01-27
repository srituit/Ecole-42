#include "push_swap.h"

void    fill_stack(t_stack **stack, int argc, char **argv)
{
    int i;

    i = argc - 1;
    *stack = init_empty_stack();
    while (i > 0)
    {
        add_elem(stack, ft_atoi(argv[i]));
        i--;
    }
}

t_stack *init_empty_stack()
{
    t_stack *stack;

    stack = (t_stack*)malloc(sizeof(t_stack));
    stack->first = NULL;
    stack->count = 0;
    stack->min = 2147483647;
    stack->max = -2147483648;
    stack->max1 = -2147483648;
    stack->max2 = -2147483648;

    return (stack);
}

void    printlists(t_stack **stack_a, t_stack **stack_b)
{
    t_elem  *cur_a;
    t_elem  *cur_b;

    cur_a = (*stack_a)->first;
    cur_b = (*stack_b)->first;
    while (cur_a != NULL)
    {
        printf("stack a : %d\t", cur_a->nb);
        cur_a = cur_a->next;
        if (cur_b != NULL)
        {
            printf("stack b : %d", cur_b->nb);
            cur_b = cur_b->next;
        }
        printf("\n");
    }
    while (cur_b != NULL)
    {
        printf("\t\tstack b : %d\n", cur_b->nb);
        cur_b = cur_b->next;
    }
    printf("------------------------\n");
}

int     is_sorted(t_stack **stack_a, t_stack **stack_b)
{
    t_elem *cur;

    if (!(*stack_a)->first)
        return (0);
    cur = (*stack_a)->first;
    while (cur->next)
    {
        if (cur->nb > cur->next->nb)
            return (0);
        cur = cur->next;
    }
    if ((*stack_b)->first != NULL)
        return (0);
    return (1);
}

int     check_double(t_stack **stack_a)
{
    t_elem  *base;
    t_elem  *cur;

    base = (*stack_a)->first;
    while (base)
    {
        cur = base->next;
        while (cur)
        {
            if (cur->nb == base->nb)
                return (0);
            cur = cur->next;
        }
        base = base->next;
    }
    return (1);
}