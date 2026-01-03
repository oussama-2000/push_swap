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

void	ra(t_stack **a,int print)
{
	rotate(a);
	if(print)
		write(1, "ra\n",3);
}

void	rb(t_stack **b,int print)
{
	rotate(b);
	if(print)
		write(1, "rb\n",3);
}

void	rr(t_stack **a,t_stack **b,int print)
{
	rotate(a);
	rotate(b);
	if(print)
		write(1, "rr\n",3);
}
