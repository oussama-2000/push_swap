/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_man2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamkhou <oamkhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 22:49:37 by marvin            #+#    #+#             */
/*   Updated: 2026/01/03 13:43:03 by oamkhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

t_stack	*find_max_rank(t_stack *stack)
{
	t_stack	*max;

	max = stack;
	while (stack)
	{
		if (stack->rank > max->rank)
			max = stack;
		stack = stack->next;
	}
	return (max);
}

t_stack	*find_min_rank(t_stack *stack)
{
	t_stack	*min;

	min = stack;
	while (stack)
	{
		if (stack->rank < min->rank)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

void	stack_ranking(t_stack **stack)
{
	t_stack	*head;
	t_stack	*curent;
	int		rank;

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

int	get_position(t_stack *stack, t_stack *target)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack == target)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (pos);
}
