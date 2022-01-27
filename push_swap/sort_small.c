#include "push_swap.h"

void    sort_two(t_stack **stack)
{
    if ((*stack)->first->nb > (*stack)->first->next->nb)
    {
        swap(stack);
        write(1,"sa\n", 3);
    }
}

void    sort_three(t_stack **stack)
{
    int first;
    int second;
    int third;

    first = (*stack)->first->nb;
    second = (*stack)->first->next->nb;
    third = (*stack)->first->next->next->nb;
    if (first > second && second > third && first > third)
    {
        do_print_sa(stack);
        do_print_rra(stack);
    }
    else if (first < second && second > third && first < third)
    {
        do_print_rra(stack);
        do_print_sa(stack);
    }
    else if (first > second && second < third && first < third)
        do_print_sa(stack);
    else if (first < second && second > third && first > third)
        do_print_rra(stack);
    else if (first > second && second < third && first > third)
        do_print_ra(stack);
}