/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 22:35:56 by marvin            #+#    #+#             */
/*   Updated: 2026/01/01 22:35:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_rotate(t_stack **s)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*new_last;

	if (!s || !*s || !(*s)->next)
		return;

	first = *s;
	last = *s;
	while (last->next)
		last = last->next;

	new_last = last->prev;
	new_last->next = NULL;

	last->prev = NULL;

	last->next = first;
	(*s)->prev = last;
	*s=last;
}

void	rra(t_stack **a,int print)
{
	r_rotate(a);
	if(print)
		write(1, "rra\n",4);
}

void	rrb(t_stack **b,int print)
{
	r_rotate(b);
	if(print)
		write(1, "rrb\n",4);
}

void	rrr(t_stack **a,t_stack **b,int print)
{
	r_rotate(a);
	r_rotate(b);
	if(print)
		write(1, "rrr\n",4);
}
