/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlindeza <hlindeza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:33:14 by hlindeza          #+#    #+#             */
/*   Updated: 2023/09/19 14:14:20 by hlindeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sa(t_stack **stack_a)
{
	if (swap(stack_a))
		ft_printf("sa\n");
	else
		return ;
}

void	sb(t_stack **stack_b)
{
	if (swap(stack_b))
		ft_printf("sb\n");
	else
		return ;
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	if ((ft_lstsize_nv(*stack_a) < 2) || (ft_lstsize_nv(*stack_b) < 2))
		return ;
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	if (push(stack_b, stack_a))
		ft_printf("pa\n");
	else
		return ;
}

void	pb(t_stack **stack_b, t_stack **stack_a)
{
	if (push(stack_a, stack_b))
		ft_printf("pb\n");
	else
		return ;
}
