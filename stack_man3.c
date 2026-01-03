/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_man3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamkhou <oamkhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 22:51:30 by marvin            #+#    #+#             */
/*   Updated: 2026/01/03 13:44:33 by oamkhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_first_pos(t_stack *a, int min, int max)
{
	int	pos;

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

int	get_last_pos(t_stack *a, int min, int max)
{
	int	pos;
	int	last_pos;

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
