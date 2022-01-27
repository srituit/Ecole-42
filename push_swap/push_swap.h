#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
typedef struct s_elem
{
    int nb;
    struct s_elem   *next;
}t_elem;

typedef struct s_stack
{
    t_elem  *first;
    int     count;
    int     min;
    int     max;
    int     max1;
    int     max2;
}t_stack;

typedef struct s_insert
{
    int ra;
    int rb;
    int rra;
    int rrb;
    int nb_op;
    int op;
}t_insert;

void        do_print_ra(t_stack **stack_a);
void        do_print_rra(t_stack **stack_a);
void        do_print_rb(t_stack **stack_b);
void        do_print_rrb(t_stack **stack_b);
void        do_print_sa(t_stack **stack_a);
void        swap(t_stack **stack);
void        push_b(t_stack **stack_a, t_stack **stack_b);
void        push_a(t_stack **stack_a, t_stack **stack_b);
void        rotate(t_stack **stack);
void        reverse_rotate(t_stack **stack);
void        sort_two(t_stack **stack);
void        sort_three(t_stack **stack);
void        insert_elem(t_stack **stack, int n);
void        remove_elem(t_stack **stack);
void        add_elem(t_stack **stack, int n);
void        ft_exit(int q, t_stack **stack_a, t_stack **stack_b);
void        free_stack(t_stack **stack);
int         ft_min(int a, int b);
int         ft_max(int a, int b);
int         check_double(t_stack **stack_a);
int         ft_atoi(char *s);
int         is_sorted(t_stack **stack_a, t_stack **stack_b);
void    nb_rb(t_insert *insert, t_elem *elem, t_stack **stack_b);
void    do_op(t_insert insert, t_stack **stack_a, t_stack **stack_b);
void    insert_rrr(t_insert insert, t_stack **stack_a, t_stack **stack_b);
void    insert_rr(t_insert insert, t_stack **stack_a, t_stack **stack_b);
void    insert_min(t_insert insert, t_stack **stack_a, t_stack **stack_b);
void        fill_stack(t_stack **stack, int argc, char **argv);
void        find_max(t_stack **stack);
void        printlists(t_stack **stack_a, t_stack **stack_b);
t_insert    fill_insert(t_elem *elem, t_stack **stack_a, t_stack **stack_b);
t_stack     *init_empty_stack();

#endif