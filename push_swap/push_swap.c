#include "push_swap.h"

t_insert    find_best_elem(t_stack **stack_a, t_stack **stack_b)
{
    t_elem      *cur;
    t_insert    best;
    t_insert    tmp;
    int         i;

    i = 1;
    cur = (*stack_a)->first;
    while (cur->nb == (*stack_a)->max || cur->nb == (*stack_a)->max1 || cur->nb == (*stack_a)->max2)
        cur = cur->next;
    best = fill_insert(cur, stack_a, stack_b);
    cur = (*stack_a)->first;
    while (i++ < (*stack_a)->count)
    {
        cur = cur->next;
        tmp = fill_insert(cur, stack_a, stack_b);
        if (tmp.nb_op < best.nb_op && cur->nb != (*stack_a)->max && cur->nb != (*stack_a)->max1 && cur->nb != (*stack_a)->max2)
            best = tmp;
    } 
    return (best);
}

int count_rb(t_stack **stack_b)
{
    t_elem  *cur;
    int     res;

    cur = (*stack_b)->first;
    res = 0;
    while (cur->nb != (*stack_b)->max)
    {
        cur = cur->next;
        res++;
    }
    return (res);
}

void    insertion_sort(t_stack **stack_a, t_stack **stack_b)
{
    t_insert    insert;
    int         nb;

    while ((*stack_a)->count > 3)
    {
        insert = find_best_elem(stack_a, stack_b);
        do_op(insert, stack_a, stack_b);        push_b(stack_a, stack_b);
        write(1, "pb\n", 3);
    }
    nb = count_rb(stack_b);
    if (nb < (*stack_b)->count - nb)
        while ((*stack_b)->first->nb != (*stack_b)->max)
            do_print_rb(stack_b);
    else
        while ((*stack_b)->first->nb != (*stack_b)->max)
            do_print_rrb(stack_b);
    sort_three(stack_a);
    while ((*stack_b)->first)
    {
        push_a(stack_a, stack_b);
        write(1, "pa\n", 3);
    } 
}

void    sort(t_stack **stack_a, t_stack **stack_b)
{

    if ((*stack_a)->count == 1)
        return ;
    else if ((*stack_a)->count == 2)
        sort_two(stack_a);
    else if ((*stack_a)->count == 3)
        sort_three(stack_a);
    else if ((*stack_a)->count > 3)
    {
        find_max(stack_a);
        insertion_sort(stack_a, stack_b);
    }
}

int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;

    if (argc == 1)
        exit(EXIT_SUCCESS);
/*    if (check_arg(argc, argv))
    {
        write(2, "Error\n", 6);
        exit(EXIT_FAILURE);
    }
*/
    fill_stack(&stack_a, argc, argv);
    stack_b = init_empty_stack();
    printlists(&stack_a, &stack_b);
    if (!(check_double(&stack_a)))
        ft_exit(2, &stack_a, &stack_b);
    if (is_sorted(&stack_a, &stack_b) == 1)
        ft_exit(3, &stack_a, &stack_b);
    sort(&stack_a, &stack_b);
    printlists(&stack_a, &stack_b);
    ft_exit(3, &stack_a, &stack_b);
}