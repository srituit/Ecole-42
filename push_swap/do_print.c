#include "push_swap.h"

void    do_print_ra(t_stack **stack_a)
{
    rotate(stack_a);
    write(1, "ra\n", 3);
}
void    do_print_rra(t_stack **stack_a)
{
    reverse_rotate(stack_a);
    write(1, "rra\n", 4);
}
void    do_print_rb(t_stack **stack_b)
{
    rotate(stack_b);
    write(1, "rb\n", 3);
}
void    do_print_rrb(t_stack **stack_b)
{
    reverse_rotate(stack_b);
    write(1, "rrb\n", 4);
}
void    do_print_sa(t_stack **stack_a)
{
    swap(stack_a);
    write(1, "sa\n", 3);
}