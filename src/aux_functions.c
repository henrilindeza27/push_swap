/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlindeza <hlindeza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:12:15 by hlindeza          #+#    #+#             */
/*   Updated: 2023/09/19 15:47:59 by hlindeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_free(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		;
	while (i >= 0)
		free(str[i--]);
}

int	a_is_sorted(t_stack **stack)
{
	t_stack	*head;

	head = *stack;
	while (head && head->next)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}

void	init_stacks(t_stack **stack, int argc, char **argv)
{
	t_stack		*new;
	int			i;
	long int	tmp;
	char		**numbrs;

	i = -1;
	if (argc == 2)
		numbrs = ft_split(argv[1], ' ');
	else
	{
		numbrs = argv;
		i++;
	}
	while (numbrs[++i])
	{
		new = ft_lstnew_nv((ft_atoi(numbrs[i])));
		ft_lstadd_back_nv(stack, new);
	}
	put_indexs(stack);
	if (argc == 2)
		ft_free(numbrs);
}

int	get_bigger_index(t_stack **stack)
{
	t_stack	*head;
	int		max_index;

	head = *stack;
	max_index = head->index;
	while (head)
	{
		if (head->index > max_index)
			max_index = head->index;
		head = head->next;
	}
	return (max_index);
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = ft_lstsize_nv(*stack_a);
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_3_numbers(stack_a);
	else if (size == 4)
		sort_4_numbers(stack_a, stack_b);
	else if (size == 5)
		sort_5_numbers(stack_a, stack_b);
	else
		radix(stack_a, stack_b);
}
