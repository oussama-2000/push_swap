/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 22:52:37 by marvin            #+#    #+#             */
/*   Updated: 2026/01/01 22:52:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **s)
{
	t_stack	*first;
	t_stack	*second;

	if (!s || !*s)
		return;
	if(!(*s)->next)
		return;

	first = *s;
	second = first->next;

	first->next = second->next;
	if (second->next)
		second->next->prev = first;

	second->next = first;
	second->prev = NULL;
	first->prev = second;

	*s = second;
}

void	sa(t_stack **a,int print)
{
	swap(a);
	if(print)
		write(1 ,"sa\n",3);
}

void	sb(t_stack **b,int print)
{
	swap(b);
	if(print)
		write(1 ,"sb\n",3);
}

void	sss(t_stack **a,t_stack **b,int print)
{
	swap(a);
	swap(b);
	if(print)
		write(1 ,"sss\n",4);
}
