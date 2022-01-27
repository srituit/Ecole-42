#include "linked_list.h"

/*void    push_a(List **L, List **L2)
{
    List    *cur;
    List    *cur2;

    cur = *L;
    cur2 = *L2;
    add_elem(&L2, (*L)->x);
}
*/
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

void    add_elem(List **L, int n)
{
    List    *new_list;
    List    *cur;

    new_list = malloc(sizeof(List));
    new_list->next = NULL;
    new_list->x = n;
    if (*L == NULL)
    {
        *L = new_list;
        return;
    }
    cur = *L;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = new_list;
}

int main(int argc, char **argv)
{
    int     i;
    List    *L;
    List    *L2;
    List    *cur;

    i = 1;
    L2 = malloc(sizeof(List));
    L2->next = NULL;
    L = malloc(sizeof(List));
    L->next = NULL;
    while (i < argc)
    {
        add_elem(&L, ft_atoi(argv[i]));
        i++; 
    }
//    push_a(&L, &L2);
    cur = L;
    while (cur != NULL)
    {
        printf("%d\n", cur->x);
        cur = cur->next;
    }
//    printf("%d\n", L->next->x);
//    printf("%d\n", L->next->next->x);
//    printf("%d\n", L->next->next->next->x);   
    return (0);
}