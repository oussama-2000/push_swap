#include "push_swap.h"

static void push(t_stack **from, t_stack **to)
{
    t_stack *node;

    if (!from || !*from)
        return;

    node = *from;

    // remove node from 'from' stack 
    *from = node->next;

    // add node to top of 'to' stack 
    node->next = *to;
    if (*to)
        (*to)->prev = node;

    node->prev = NULL;
    *to = node;
}


void pa(t_stack **b, t_stack **a)
{
    push(b,a);
    write(1 , "pa\n",3);
}

void pb(t_stack **a, t_stack **b)
{
    push(a,b);
    write(1 , "pb\n",3);
}