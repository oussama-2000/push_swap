#ifndef INT_MAX
# define INT_MAX 2147483647
#endif
#ifndef INT_MIN
# define INT_MIN -2147483648
#endif

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H



#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_stack
{
    int value;
    int rank;         
    struct s_stack  *next;
    struct s_stack   *prev;
} t_stack;


char **ft_split(char const *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s);
t_stack *stack_new(int value);
void stack_add_back(t_stack **stack, t_stack *new);
void parse_args(int ac, char **av, t_stack **a);
void sa(t_stack **a);
void sb(t_stack **b);
void sss(t_stack **a,t_stack **b);
void pa(t_stack **b, t_stack **a);
void pb(t_stack **a, t_stack **b);
void ra(t_stack **a);
void rb(t_stack **b);
void rr(t_stack **a,t_stack **b);
void rra(t_stack **a);
void rrb(t_stack **b);
void rrr(t_stack **a,t_stack **b);
void free_stack(t_stack **s);
long ft_atoi(const char *str);
int duplicated(t_stack *stack, int value);


#endif