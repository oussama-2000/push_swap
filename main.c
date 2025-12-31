
#include "push_swap.h"

void print_stack(t_stack **s)
{
	t_stack *tmp;
	tmp = *s;

	while (tmp)
	{
		printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
}

int is_sorted(t_stack *stack)
{

	while (stack->next)
	{

		if (stack->value > stack->next->value)
			return 0;
		stack = stack->next;
	}
	return 1;
}

int stack_len(t_stack *stack)
{
	int len;

	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return len;
}
t_stack *find_max_rank(t_stack *stack)
{
	t_stack *max = stack;
	while (stack)
	{
		if (stack->rank > max->rank)
			max = stack;
		stack = stack->next;
	}
	return (max);
}

t_stack *find_min_rank(t_stack *stack)
{
	t_stack *min = stack;
	while (stack)
	{
		if (stack->rank < min->rank)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

void stack_ranking(t_stack **stack)
{
	t_stack *head;
	t_stack *curent;
	int rank;

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

void sort_three(t_stack **stack)
{
	t_stack *big_index;

	big_index = find_max_rank(*stack);
	if (big_index->prev == NULL)
		ra(stack);
	else if (big_index->next != NULL)
		rra(stack);
	if ((*stack)->rank > (*stack)->next->rank)
		sa(stack);
}

void sort_five(t_stack **a, t_stack **b)
{
	t_stack *min;

	int len;

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
// this function returns the position of next belongs to the current chunk
int get_position(t_stack *a, int min, int max)
{
	int pos;

	pos = 0;
	while (a)
	{
		if (a->rank >= min && a->rank <= max)
			return pos;
		pos++;
		a = a->next;
	}
	return -1;
}
// search about the node that hase the biger rank
int get_max_pos(t_stack *b)
{
	int max;
	int pos;
	int i;

	max = b->rank;
	pos = 0;
	i = 0;
	while (b)
	{
		if (b->rank > max)
		{
			max = b->rank;
			pos = i;
		}
		b = b->next;
		i++;
	}
	return pos;
}
// move the big node to the top
void bring_max_to_top(t_stack **b)
{
	int pos;
	int len;

	len = stack_len(*b);
	pos = get_max_pos(*b);

	if (pos <= len / 2)
	{
		while (pos-- > 0)
			rb(b);
	}
	else
	{
		while (pos < len)
		{
			rrb(b);
			pos++;
		}
	}
}
int is_max(t_stack *b)
{
	int max = b->rank;
	while (b)
	{
		if (b->rank > max)
			return 0;
		b = b->next;
	}
	return 1;
}

void chunks_sort(t_stack **a, t_stack **b)
{
	int len;
	int chunk_size;
	int current_min;
	int current_max;
	int pushed;
	int pos;
	int len_a;

	len = stack_len(*a);
	if (len <= 100)
		chunk_size = 20;
	else
		chunk_size = 51;
	current_min = 0;
	current_max = chunk_size - 1;
	while (*a)
	{
		pushed = 0;
		len_a = stack_len(*a);
		while (*a && pushed < chunk_size)
		{
			if ((*a)->rank >= current_min && (*a)->rank <= current_max)
			{
				pb(a, b);
				if ((*b)->rank < current_min + (chunk_size / 2))
					rb(b);
				pushed++;
				len_a--;
			}
			else
			{
				pos = get_position(*a, current_min, current_max);
				if (pos <= len_a / 2)
					ra(a);
				else
					rra(a);
			}
		}
		current_min += chunk_size;
		current_max += chunk_size;
	}
	while (*b)
	{
		bring_max_to_top(b);
		pa(b, a);
	}

}

int main(int ac, char **av)
{
	t_stack *a = NULL;
	t_stack *b = NULL;

	if (ac < 2)
		return 0;

	parse_args(ac, av, &a);
	stack_ranking(&a);
	if (!is_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a);
		if (stack_len(a) == 3)
			sort_three(&a);
		if (stack_len(a) <= 5)
		{
			sort_five(&a, &b);
		}
		else
			chunks_sort(&a, &b);
	}
	// printf("------a------\n");
	// print_stack(&a);
	// printf("------b------\n");
	// print_stack(&b);

	free_stack(&a);
	free_stack(&b);
	free(a);
	free(b);
	return 0;
}
