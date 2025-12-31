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

static void free_split(char **arr)
{
	int i = 0;
	if (!arr)
		return;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}


static void error(t_stack **s,char **arr)
{
	write(2, "Error\n", 6);
	free_split(arr);
	free_stack(s);
	exit(1);
}

void check(char **args, t_stack **a,int j,long *num)
{
   int i = j;
	 if (!is_number(args[i]))
		 error(a,args);
	*num = ft_atoi(args[i]);
	if (*num < INT_MIN || *num > INT_MAX)
		error(a,args);
	if (duplicated(*a, (int)*num))
		error(a,args);

}

void parse_args(int ac, char **av, t_stack **a)
{
	int i;
	char **args;
	int j;
	long num;
	t_stack *node;

	i = 1;
	while (i < ac)	
	{
		j = 0;
		args = ft_split(av[i]);
		if (!args || !args[0])
			error(a,args);
		while (args[j])
		{
			check(args,a,j,&num);
			node = stack_new((int)num);
			if(!node)
				error(a,args);
			stack_add_back(a, node);
			j++;
		}
		free_split(args);
		i++;
	}   
}
