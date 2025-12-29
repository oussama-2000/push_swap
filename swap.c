#include "push_swap.h"


static void swap(t_stack **s)
{
    t_stack *first;
    t_stack *second;

    if (!s || !*s)
        return;
    if(!(*s)->next)
        return;

    first = *s;
    second = first->next;

    first->next = second->next;
    if (second->next)
        second->next->prev = first;

    second->next = first;
    second->prev = NULL;
    first->prev = second;

    *s = second;
}


void sa(t_stack **a)
{
    swap(a);
    write(1 ,"sa\n",3);
}

void sb(t_stack **b)
{
    swap(b);
    write(1 ,"sb\n",3);
}

void sss(t_stack **a,t_stack **b)
{
    swap(a);
    swap(b);
    write(1 ,"sss\n",4);
}