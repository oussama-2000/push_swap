#include "push_swap.h"

static int is_number(char *str)
{
    int i = 0;

    if (str[i] == '+' || str[i] == '-')
        i++;
    if (!str[i])
        return 0;
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

static long ft_atoi(const char *str)
{
    long result = 0;
    int sign = 1;
    int i = 0;

    if (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i])
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return result * sign;
}

static int has_duplicate(t_stack *stack, int value)
{
    while (stack)
    {
        if (stack->value == value)
            return 1;
        stack = stack->next;
    }
    return 0;
}

static void free_split(char **arr)
{
    int i = 0;
    if (!arr)
        return;
    while (arr[i])
        free(arr[i++]);
    free(arr);
}
void free_stack(t_stack **s)
{
    t_stack *tmp;
    if(!s || !*s)
        return;

    while(*s)
    {
        tmp = (*s)->next;
        free(*s);
        *s = tmp;
    }
    s = NULL;
}

static void error(t_stack **s)
{
    write(2, "Error\n", 6);
    free_stack(s);
    exit(1);
}

void parse_args(int ac, char **av, t_stack **a)
{
    int i = 1;
    char **args;
    int j;
    long num;

    while (i < ac)
    {
        j = 0;
        args = ft_split(av[i]);
        if (!args || !args[0])
            error(a);
        while (args[j])
        {
            if (!is_number(args[j]))
            {
                free_split(args);
                error(a);
            }
            num = ft_atoi(args[j]);
            if (num < INT_MIN || num > INT_MAX)
            {
                free_split(args);
                error(a);
            }
            if (has_duplicate(*a, (int)num))
            {
                free_split(args);
                error(a);
            }
            stack_add_back(a, stack_new((int)num));
            j++;
        }
        free_split(args);
        i++;
    }
}
