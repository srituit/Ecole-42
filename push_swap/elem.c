#include "push_swap.h"

void    remove_elem(t_stack **stack)
{
    t_elem  *to_remove;

    to_remove = (*stack)->first;
    (*stack)->first = to_remove->next;
    (*stack)->count--;
    free(to_remove);
}

void    add_elem(t_stack **stack, int n)
{
    t_elem  *new_elem;

    new_elem = malloc(sizeof(t_elem));
    new_elem->nb = n;
    new_elem->next = (*stack)->first;
    if (new_elem->nb > (*stack)->max)
        (*stack)->max = new_elem->nb;
    if (new_elem->nb < (*stack)->min)
        (*stack)->min = new_elem->nb;
    (*stack)->first = new_elem;
    (*stack)->count++;
}

void    insert_elem(t_stack **stack, int n)
{
    t_elem  *new_elem;

    new_elem = malloc(sizeof(t_elem));
    new_elem->nb = n;
    new_elem->next = (*stack)->first;
    (*stack)->first = new_elem;
    (*stack)->count++;
}