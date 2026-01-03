/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 22:32:13 by marvin            #+#    #+#             */
/*   Updated: 2026/01/01 22:32:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_stack **a,t_stack **b)
{
	if (!is_sorted(*a))
	{
		if (stack_len(*a) == 2)
			sa(a,1);
		if (stack_len(*a) == 3)
			sort_three(a);
		if (stack_len(*a) <= 5)
			sort_five(a, b);
		else
		{
			sort_part_1(a,b);
			sort_part_2(a,b);
		}
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return 0;
	parse_args(ac, av, &a);
	stack_ranking(&a);
	ft_sort(&a,&b);
	free_stack(&a);
	free_stack(&b);
	return 0;
}
