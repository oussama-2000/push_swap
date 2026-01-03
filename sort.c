/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamkhou <oamkhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 22:46:41 by marvin            #+#    #+#             */
/*   Updated: 2026/01/03 13:39:34 by oamkhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack)
{
	t_stack	*big_rank;

	big_rank = find_max_rank(*stack);
	if (big_rank->prev == NULL)
		ra(stack, 1);
	else if (big_rank->next != NULL)
		rra(stack, 1);
	if ((*stack)->rank > (*stack)->next->rank)
		sa(stack, 1);
}

void	sort_five(t_stack **a, t_stack **b)
{
	t_stack	*min;
	int		len;

	len = stack_len(*a);
	while (len > 3)
	{
		min = find_min_rank(*a);
		if (min->prev == NULL)
			pb(a, b, 1);
		else if (min->next == NULL || min->next->next == NULL)
			rra(a, 1);
		else
			ra(a, 1);
		if (is_sorted(*a))
			break ;
		len = stack_len(*a);
	}
	if (!is_sorted(*a))
		sort_three(a);
	while (*b)
	{
		pa(b, a, 1);
	}
}

void	get_node_to_push(t_stack **a, int min, int max)
{
	int	top_pos;
	int	bot_pos;

	top_pos = get_first_pos(*a, min, max);
	bot_pos = get_last_pos(*a, min, max);
	if (top_pos < (stack_len(*a) - bot_pos))
	{
		while (top_pos > 0)
		{
			ra(a, 1);
			top_pos--;
		}
	}
	else
	{
		while (bot_pos < stack_len(*a))
		{
			rra(a, 1);
			bot_pos++;
		}
	}
}

void	sort_part_1(t_stack **a, t_stack **b)
{
	int	chunk_size;
	int	current_min;
	int	current_max;

	if (stack_len(*a) <= 100)
		chunk_size = 19;
	else
		chunk_size = 55;
	current_min = 0;
	while (*a)
	{
		current_max = current_min + chunk_size - 1;
		while (chunk(*a, current_min, current_max))
		{
			get_node_to_push(a, current_min, current_max);
			pb(a, b, 1);
			if ((*b)->rank < (current_min + (chunk_size / 2)))
				rb(b, 1);
		}
		current_min += chunk_size;
	}
}

void	sort_part_2(t_stack **a, t_stack **b)
{
	t_stack	*max_index;
	int		pos;

	while (*b)
	{
		max_index = find_max_rank(*b);
		pos = get_position(*b, max_index);
		while (*b != max_index)
		{
			if ((*b)->rank == max_index->rank - 1)
				pa(b, a, 1);
			else if (pos <= stack_len(*b) / 2)
				rb(b, 1);
			else
				rrb(b, 1);
		}
		pa(b, a, 1);
		if (*a && (*a)->next && (*a)->rank > (*a)->next->rank)
			sa(a, 1);
	}
}
