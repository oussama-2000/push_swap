
#include "push_swap.h"
void print_stack(t_stack **s)
{
    t_stack *tmp;
    tmp = *s;

    while (tmp)
    {
        printf("%d\n", tmp->value);
        tmp = tmp->next;
    }
}

int is_sorted(t_stack *stack)
{

    while (stack->next)
    {

        if (stack->value > stack->next->value)
            return 0;
        stack = stack->next;
    }
    return 1;
}

int stack_len(t_stack *stack)
{
    int len;

    len = 0;
    while (stack)
    {
        len++;
        stack = stack->next;
    }
    return len;
}
t_stack *find_max_rank(t_stack *stack)
{
    t_stack *max = stack;
    while (stack)
    {
        if (stack->rank > max->rank)
            max = stack;
        stack = stack->next;
    }
    return (max);
}

void stack_ranking(t_stack **stack)
{
    t_stack *head;
    t_stack *curent;
    int rank;

    head = *stack;
    while (head)
    {
        rank = 0;
        curent = *stack;
        while (curent)
        {
            if (curent->value < head->value)
                rank++;
            curent = curent->next;
        }
        head->rank = rank;
        head = head->next;
    }
}

void sort_three(t_stack **stack)
{
    t_stack *big_index = find_max_rank(*stack);

    if (big_index->prev == NULL)
        ra(stack);
    else if (big_index->next != NULL)
        rra(stack);
    if ((*stack)->rank > (*stack)->next->rank)
        sa(stack); 
}


int main(int ac, char **av)
{
    t_stack *a = NULL;
    // t_stack *b = NULL;

    if (ac < 2)
        return 0;

    parse_args(ac, av, &a);
    stack_ranking(&a);
    if (!is_sorted(a))
    {
        if (stack_len(a) == 2)
            sa(&a);
        if (stack_len(a) == 3)
            sort_three(&a);
    }

    print_stack(&a);


    free(a);

    return 0;
}
