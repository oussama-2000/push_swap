#include "push_swap.h"

t_stack *stack_new(int value)
{
    t_stack *node;

    node = malloc(sizeof(t_stack));
    if (!node)
        return NULL;
    node->value = value;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void stack_add_back(t_stack **stack, t_stack *new)
{
    t_stack *tmp;

    if (!stack || !new)
        return;

    if (!*stack)
    {
        *stack = new;
        return;
    }
    tmp = *stack;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new;
    new->prev = tmp;
}
