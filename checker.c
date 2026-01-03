/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 23:52:59 by marvin            #+#    #+#             */
/*   Updated: 2026/01/02 23:52:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

void	Error(t_stack **a, t_stack **b, char *line)
{
	write(2, "Error\n", 6);
	free(line);
	free_stack(a);
	free_stack(b);
	exit(1);
}

void	exec_instruction(char *line, t_stack **a, t_stack **b)
{
	if (ft_strcmp(line, "sa\n"))
		sa(a, 0);
	else if (ft_strcmp(line, "sb\n"))
		sb(b, 0);
	else if (ft_strcmp(line, "ss\n"))
		sss(a, b, 0);
	else if (ft_strcmp(line, "pa\n"))
		pa(b, a, 0);
	else if (ft_strcmp(line, "pb\n"))
		pb(a, b, 0);
	else if (ft_strcmp(line, "ra\n"))
		ra(a, 0);
	else if (ft_strcmp(line, "rb\n"))
		rb(b, 0);
	else if (ft_strcmp(line, "rr\n"))
		rr(a, b, 0);
	else if (ft_strcmp(line, "rra\n"))
		rra(a, 0);
	else if (ft_strcmp(line, "rrb\n"))
		rrb(b, 0);
	else if (ft_strcmp(line, "rrr\n"))
		rrr(a, b, 0);
	else
		Error(a, b, line);
}

void	read_instructions(t_stack **a, t_stack **b)
{
	char	*line;

	while ((line = get_next_line(0)))
	{
		exec_instruction(line, a, b);
		free(line);
	}
	if (is_sorted(*a) && stack_len(*b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
int main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return 0;
	parse_args(ac, av, &a);
	read_instructions(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return 0;
}
