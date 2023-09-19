/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlindeza <hlindeza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 22:50:26 by hlindeza          #+#    #+#             */
/*   Updated: 2023/09/19 14:14:29 by hlindeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ra(t_stack **stack_a)
{
	if (rotate(stack_a))
		ft_printf("ra\n");
	else
		return ;
}

void	rb(t_stack **stack_b)
{
	if (rotate(stack_b))
		ft_printf("rb\n");
	else
		return ;
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	if ((ft_lstsize_nv(*stack_a) < 2) || (ft_lstsize_nv(*stack_b) < 2))
		return ;
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}

void	rra(t_stack **stack_a)
{
	if (reverse_rotate(stack_a))
		ft_printf("rra\n");
	else
		return ;
}

void	rrb(t_stack **stack_b)
{
	if (reverse_rotate(stack_b))
		ft_printf("rrb\n");
	else
		return ;
}
