#ifndef LINKED_LIST_H
# define LINKED_LIST_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
typedef struct List
{
    int x;
    struct List *next;
}List;

#endif