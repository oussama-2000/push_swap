/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_man3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 22:51:30 by marvin            #+#    #+#             */
/*   Updated: 2026/01/01 22:51:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Distance from the top to the FIRST element in the chunk
int	get_first_pos(t_stack *a, int min, int max)
{
	int pos;
	
	pos = 0;
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
int	get_last_pos(t_stack *a, int min, int max)
{
	int pos;
	int last_pos;

	pos = 0;
	last_pos = -1;
	while (a)
	{
		if (a->rank >= min && a->rank <= max)
			last_pos = pos;
		pos++;
		a = a->next;
	}
	return (last_pos);
}

// Checks if any element in the chunk range still exists in stack A
int	chunk(t_stack *a, int min, int max)
{
	while (a)
	{
		if (a->rank >= min && a->rank <= max)
			return (1);
		a = a->next;
	}
	return (0);
}
