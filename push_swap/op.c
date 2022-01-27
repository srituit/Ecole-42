#include "push_swap.h"

void    swap(t_stack **stack)
{
    int     n;

    if ((*stack)->count <= 1)
        return ;
    else
    {
        n = (*stack)->first->nb;
        (*stack)->first->nb = (*stack)->first->next->nb;
        (*stack)->first->next->nb = n;
    }
}

void    push_b(t_stack **stack_a, t_stack **stack_b)
{
    int n;

    if ((*stack_a)->count == 0)
        return ;
    n = (*stack_a)->first->nb;
    add_elem(stack_b, n);
    remove_elem(stack_a);
//    write(1, "pb\n", 3);
}

void    push_a(t_stack **stack_a, t_stack **stack_b)
{
    int n;

    if ((*stack_b)->count == 0)
        return ;
    n = (*stack_b)->first->nb;
    add_elem(stack_a, n);
    remove_elem(stack_b);
//    write(1, "pa\n", 3);
}

void    rotate(t_stack **stack)
{
    t_elem  *first;
    t_elem  *last;

    if ((*stack)->count <= 1)
        return ;
    last = (*stack)->first;
    while (last->next)
        last = last->next;
    first = (*stack)->first;
    (*stack)->first = (*stack)->first->next;
    first->next = NULL;
    last->next = first;
}

void    reverse_rotate(t_stack **stack)
{
    t_elem  *last;
    t_elem  *new_last;

    if ((*stack)->count <= 1)
        return ;
    last = (*stack)->first;
    while (last->next)
    {
        if (!last->next->next)
            new_last = last;
        last = last->next;
    }
    new_last->next = NULL;
    last->next = (*stack)->first;
    (*stack)->first = last;
}