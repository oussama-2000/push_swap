/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_man1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 22:48:17 by marvin            #+#    #+#             */
/*   Updated: 2026/01/01 22:48:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_new(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return NULL;
	node->value = value;
	node->rank = -1;
	node->next = NULL;
	node->prev = NULL;
	return node;
}

void	stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*tmp;

	if (!stack || !new)
		return;
	if (!*stack)
	{
		*stack = new;
		return;
	}
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}

void	free_stack(t_stack **s)
{
	t_stack *tmp;
	if(!s || !*s)
		return;
	while(*s)
	{
		tmp = (*s)->next;
		free(*s);
		*s = tmp;
	}
}

int	duplicated(t_stack *stack, int value)
{
	while(stack)
	{
		if (stack->value == value)
			return 1;
		stack = stack->next;
	}
	return 0;
}

int	stack_len(t_stack *stack)
{
	int	len;

	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return len;
}
