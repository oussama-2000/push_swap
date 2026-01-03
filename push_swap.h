/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamkhou <oamkhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 22:35:16 by marvin            #+#    #+#             */
/*   Updated: 2026/01/03 13:34:04 by oamkhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	int				rank;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

char	**ft_split(char *s);
char	*ft_substr(char *s, unsigned int start, size_t len);
size_t	ft_strlen(char *str);
char	*ft_strdup(char *s);
t_stack	*stack_new(int value);
void	stack_add_back(t_stack **stack, t_stack *new);
void	parse_args(int ac, char **av, t_stack **a);
void	sa(t_stack **a, int print);
void	sb(t_stack **b, int print);
void	sss(t_stack **a, t_stack **b, int print);
void	pa(t_stack **b, t_stack **a, int print);
void	pb(t_stack **a, t_stack **b, int print);
void	ra(t_stack **a, int print);
void	rb(t_stack **b, int print);
void	rr(t_stack **a, t_stack **b, int print);
void	rra(t_stack **a, int print);
void	rrb(t_stack **b, int print);
void	rrr(t_stack **a, t_stack **b, int print);
void	free_stack(t_stack **s);
long	ft_atoi(char *str);
int		duplicated(t_stack *stack, int value);
int		stack_len(t_stack *stack);
int		is_sorted(t_stack *stack);
t_stack	*find_max_rank(t_stack *stack);
t_stack	*find_min_rank(t_stack *stack);
void	stack_ranking(t_stack **stack);
int		get_position(t_stack *stack, t_stack *target);
void	sort_part_1(t_stack **a, t_stack **b);
void	sort_part_2(t_stack **a, t_stack **b);
void	sort_three(t_stack **stack);
void	sort_five(t_stack **a, t_stack **b);
int		chunk(t_stack *a, int min, int max);
int		get_last_pos(t_stack *a, int min, int max);
int		get_first_pos(t_stack *a, int min, int max);
void	error(t_stack **s, char **arr);
//bonus
int		search(char *str, char c);
char	*get_next_line(int fd);
char	*join(char *s1, char *s2);
char	*extract_line(char *buffer);

#endif