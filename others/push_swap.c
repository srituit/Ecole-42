#include "push_swap.h"

void    free_elem(t_stack **stack)
{
    t_elem  *cur;
    t_elem  *del;

    cur = (*stack)->first;

    while (cur != NULL)
    {
        del = cur;
        cur = cur->next;
        free(del);
    }
    (*stack)->first = NULL;
}

void    add_elem(t_stack **stack, int nb)
{
    t_elem  *new_elem;
    t_elem  *cur;

    new_elem = malloc(sizeof(t_elem));
    new_elem->next = NULL;
    new_elem->nb = nb;
    if ((*stack)->first == NULL)
    {
        (*stack)->first = new_elem;
        return;
    }
    cur = (*stack)->first;
    while (cur->next != NULL)
        cur = cur->next;
    cur->next = new_elem;
}

t_stack *init_empty_stack()
{
    t_stack *stack;

    if (!(stack = malloc(sizeof(t_stack))));
        return (NULL);
    stack->first = NULL;
    return (stack);
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

void    fill_stack(t_stack **stack, int argc, char **argv)
{
    int     i;

    i = 1;
    *stack = init_empty_stack();
    while (i < argc)
    {
        add_elem(stack, ft_atoi(argv[i]));
        i++;
    }
}

void    remove_elem(t_stack **stack)
{
    t_elem *to_remove;

    to_remove = (*stack)->first;
    (*stack)->first = (*stack)->first->next;
    free(to_remove);
}

void    push_b(t_stack **stack_a, t_stack **stack_b)
{
    int nb;

    nb = (*stack_a)->first->nb;
    add_elem(stack_b, nb);
    remove_elem(stack_a);
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
}
int main(int argc, char **argv)
{
    t_stack  *stack_a;
    t_stack  *stack_b;

    if (argc == 1)
    {
        write(1, "\n", 1);
        return (1);
    }
    fill_stack(&stack_a, argc, argv);
    stack_b = init_empty_stack();
    printlists(&stack_a, &stack_b);
    push_b(&stack_a, &stack_b);
    push_b(&stack_a, &stack_b);
    push_b(&stack_a, &stack_b);
    printlists(&stack_a, &stack_b);
    free_elem(&stack_a);
    free_elem(&stack_b);
    printf("finished.");
    return (0);
}
