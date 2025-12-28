
#include "push_swap.h"
void print_stack(t_stack **s)
{
    t_stack *tmp;
    tmp = *s;
    
    while(tmp)
    {
        printf("%d\n",tmp->value);
        tmp = tmp->next;
    }
}

int main(int ac, char **av)
{
    t_stack *a = NULL;
    t_stack *b = NULL;

    if (ac < 2)
        return 0;

    parse_args(ac, av, &a);
    print_stack(&a);
    printf("=====\n");

    pb(&a,&b);
    pb(&a,&b);
    pb(&a,&b);

    rrr(&a,&b);
    pa(&b,&a);
    sa(&a);
    ra(&a);
    sb(&b);
    pa(&b,&a);
    pa(&b,&a);
    ra(&a);
    ra(&a);
    ra(&a);

    
    print_stack(&a);

    free(a);

    return 0;
}
