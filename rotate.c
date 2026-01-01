/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 22:36:49 by marvin            #+#    #+#             */
/*   Updated: 2026/01/01 22:36:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **s)
{
	t_stack	*first;
	t_stack	*last;

	if (!s || !*s || !(*s)->next)
		return;

	first = *s;
	last = *s;
	while (last->next)
		last = last->next;

	*s = first->next;
	(*s)->prev = NULL;

	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	ra(t_stack **a)
{
	rotate(a);
	write(1, "ra\n",3);
}

void	rb(t_stack **b)
{
	rotate(b);
	write(1, "rb\n",3);
}

void	rr(t_stack **a,t_stack **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n",3);
}
