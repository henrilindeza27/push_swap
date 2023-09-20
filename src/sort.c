/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlindeza <hlindeza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 09:49:35 by hlindeza          #+#    #+#             */
/*   Updated: 2023/09/20 10:41:00 by hlindeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_3_numbers(t_stack **stack)
{
	t_stack	*temp;

	temp = ft_lstlast_nv(*stack);
	if (a_is_sorted(stack))
		return ;
	if ((*stack)->index == 0 && temp->index == 1)
	{
		rra(stack);
		sa(stack);
	}
	else if ((*stack)->index == 1 && temp->index == 2)
		sa(stack);
	else if ((*stack)->index == 1 && temp->index == 0)
		rra(stack);
	else if ((*stack)->index == 2 && temp->index == 1)
		ra(stack);
	else if ((*stack)->index == 2 && temp->index == 0)
	{
		sa(stack);
		rra(stack);
	}
}

void	sort_4_numbers(t_stack **stack_a, t_stack **stack_b)
{
	if (a_is_sorted(stack_a))
		return ;
	else if ((*stack_a)->next->index == 3)
		sa(stack_a);
	else if ((*stack_a)->next->next->index == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if ((*stack_a)->next->next->next->index == 3)
		rra(stack_a);
	pb(stack_b, stack_a);
	sort_3_numbers(stack_a);
	pa(stack_a, stack_b);
	ra(stack_a);
}

void	sort_5_numbers(t_stack **stack_a, t_stack **stack_b)
{
	if (a_is_sorted(stack_a))
		return ;
	else if ((*stack_a)->next->index == 4)
		sa(stack_a);
	else if ((*stack_a)->next->next->index == 4)
	{
		ra(stack_a);
		sa(stack_a);
	}
	else if ((*stack_a)->next->next->next->index == 4)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if ((*stack_a)->next->next->next->next->index == 4)
		rra(stack_a);
	pb(stack_b, stack_a);
	sort_4_numbers(stack_a, stack_b);
	pa(stack_a, stack_b);
	ra(stack_a);
}

int	get_bits(t_stack **stack)
{
	int	index_max;
	int	bits;

	index_max = get_bigger_index(stack);
	bits = 0;
	while (index_max >> bits)
		bits++;
	return (bits);
}

void	radix(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	bits;
	int	list_size;

	i = -1;
	bits = get_bits(stack_a);
	list_size = ft_lstsize_nv(*stack_a);
	while (++i < bits)
	{
		list_size = ft_lstsize_nv(*stack_a);
		while (list_size--)
		{
			if ((((*stack_a)->index >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_b, stack_a);
		}
		while (ft_lstsize_nv(*stack_b) != 0)
			pa(stack_a, stack_b);
	}
}
