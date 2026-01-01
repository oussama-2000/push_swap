/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 22:46:41 by marvin            #+#    #+#             */
/*   Updated: 2026/01/01 22:46:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack)
{
	t_stack	*big_index;

	big_index = find_max_rank(*stack);
	if (big_index->prev == NULL)
		ra(stack);
	else if (big_index->next != NULL)
		rra(stack);
	if ((*stack)->rank > (*stack)->next->rank)
		sa(stack);
}

void	sort_five(t_stack **a, t_stack **b)
{
	t_stack	*min;
	int	len;

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

void	get_node_to_push(t_stack **a, int min, int max)
{
	int	top_pos;
	int	bot_pos;

	top_pos = get_first_pos(*a, min, max);
	bot_pos = get_last_pos(*a, min, max);
	if (top_pos <= (stack_len(*a) - bot_pos))
	{
		while (top_pos > 0)
		{
			ra(a);
			top_pos--;
		}
	}
	else
	{
		while (bot_pos < stack_len(*a))
		{
			rra(a);
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
		chunk_size = 48;
	current_min = 0;
	while (*a)
	{
		current_max = current_min + chunk_size - 1;
		while (chunk(*a, current_min, current_max))
		{
			get_node_to_push(a, current_min, current_max);
			pb(a, b);
			if ((*b)->rank < (current_min + (chunk_size / 2)))
				rb(b);
		}
		current_min += chunk_size;
	}
}

void	sort_part_2(t_stack **a, t_stack **b)
{
	t_stack	*max_index;
	int	pos;

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
