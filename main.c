
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

t_stack *find_min_rank(t_stack *stack)
{
    t_stack *min= stack;
    while (stack)
    {
        if (stack->rank < min->rank)
            min = stack;
        stack = stack->next;
    }
    return (min);
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
    t_stack *big_index;

    big_index = find_max_rank(*stack);
    if (big_index->prev == NULL)
        ra(stack);
    else if (big_index->next != NULL)
        rra(stack);
    if ((*stack)->rank > (*stack)->next->rank)
        sa(stack); 
}


void sort_five(t_stack **a,t_stack **b)
{
     t_stack *min;

     int len;

    while ((len = stack_len(*a)) > 3)
    {
        min = find_min_rank(*a);

        if(min->prev == NULL)
            pb(a,b);
        else if(min->next == NULL || min->next->next == NULL)
            rra(a);
        else
            ra(a);
    }
    if(!is_sorted(*a))
        sort_three(a);
    while (*b)
    {
        pa(b,a);
    }
}
// void    sort(t_stack **a, t_stack **b)
// {
//     void;
// }
void radix_sort(t_stack **a, t_stack **b)
{
    int i;
    int j;
    int size;
    int max_bits;

    size = stack_len(*a);
    max_bits = 0;
    while ((size - 1) >> max_bits)
        max_bits++;

    i = 0;
    while (i < max_bits)
    {
        j = 0;
        while (j++ < size)
        {
            if (((*a)->rank >> i) & 1)
                ra(a);
            else
                pb(a, b);
        }
        while (*b)
            pa(b, a);
        i++;
    }
}

int main(int ac, char **av)
{
    t_stack *a = NULL;
    t_stack *b = NULL;

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
        if(stack_len(a) <= 5)
        {
            sort_five(&a,&b);
        }
        else
            radix_sort(&a,&b);
    }
    // printf("------a------\n");
    // print_stack(&a);
    // printf("------b------\n");
    // print_stack(&b);

    free_stack(&a);
    free_stack(&b);

    free(a);
    free(b);
    return 0;
}
