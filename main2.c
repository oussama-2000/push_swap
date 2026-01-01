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
    t_stack *min = stack;
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

void sort_five(t_stack **a, t_stack **b)
{
    t_stack *min;

    int len;

    while ((len = stack_len(*a)) > 3)
    {
        min = find_min_rank(*a);

        if (min->prev == NULL)
            pb(a, b);
        else if (min->next == NULL || min->next->next == NULL)
            rra(a);
        else
            ra(a);
    }
    if (!is_sorted(*a))
        sort_three(a);
    while (*b)
    {
        pa(b, a);
    }
}

// Checks if any element in the chunk range still exists in stack A
int has_chunk_member(t_stack *a, int min, int max)
{
    while (a)
    {
        if (a->rank >= min && a->rank <= max)
            return (1);
        a = a->next;
    }
    return (0);
}

// Distance from the top to the FIRST element in the chunk
int get_first_pos(t_stack *a, int min, int max)
{
    int pos = 0;
    while (a)
    {
        if (a->rank >= min && a->rank <= max)
            return (pos);
        pos++;
        a = a->next;
    }
    return (-1);
}

// Distance from the top to the LAST element in the chunk
int get_last_pos(t_stack *a, int min, int max)
{
    int pos = 0;
    int last_pos = -1;
    while (a)
    {
        if (a->rank >= min && a->rank <= max)
            last_pos = pos;
        pos++;
        a = a->next;
    }
    return (last_pos);
}
int get_position(t_stack *stack, t_stack *target)
{
    int pos;

    pos = 0;
    while (stack)
    {
        if (stack == target)
            return pos;
        pos++;
        stack = stack->next;
    }
    return pos;
}

void sort_part_1(t_stack **a,t_stack **b)
{
    int chunk_size;
    int current_min;
    int current_max;

    if(stack_len(*a) <= 100)
        chunk_size = 19;
    else
        chunk_size = 53;
    current_min = 0;
    while (*a)
    {
        current_max = current_min + chunk_size - 1;
        while (has_chunk_member(*a, current_min, current_max))
        {
            int top_pos = get_first_pos(*a, current_min, current_max);
            int bot_pos = get_last_pos(*a, current_min, current_max);
            if (top_pos <= (stack_len(*a) - bot_pos))
            {
                while (top_pos-- > 0)
                    ra(a);
            }
            else
            {
                while (bot_pos++ < stack_len(*a))
                    rra(a);
            }
            pb(a, b);
            if ((*b)->rank < (current_min + (chunk_size / 2)))
                rb(b);
        }
        current_min += chunk_size;
    }
}
void sort_part_2(t_stack **a,t_stack **b)
{
    t_stack *max_index;
    int pos;

    while (*b)
    {
        max_index = find_max_rank(*b);
        pos = get_position(*b, max_index);
        while (*b != max_index)
        {
            if ((*b)->rank == max_index->rank - 1)
                pa(b, a);
            else if (pos <= stack_len(*b) / 2)
                rb(b);
            else
                rrb(b);
        }
        pa(b, a);
        if (*a && (*a)->next && (*a)->rank > (*a)->next->rank)
            sa(a);
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
        if (stack_len(a) <= 5)
            sort_five(&a, &b);
        else
        {
            sort_part_1(&a,&b);
            sort_part_2(&a,&b);
        }
    }
    free_stack(&a);
    free_stack(&b);
    free(a);
    free(b);
    return 0;
}
