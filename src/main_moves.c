/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlindeza <hlindeza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:13:05 by hlindeza          #+#    #+#             */
/*   Updated: 2023/09/19 15:49:13 by hlindeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	swap(t_stack **stack)
{
	t_stack	*head;
	t_stack	*next;
	int		tmp_value;
	int		tmp_index;

	if (ft_lstsize_nv(*stack) > 1)
	{
		head = *stack;
		next = head->next;
		tmp_value = head->value;
		tmp_index = head->index;
		head->value = next->value;
		head->index = next->index;
		next->value = tmp_value;
		next->index = tmp_index;
		return (1);
	}
	return (0);
}

int	rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*last;

	if (ft_lstsize_nv(*stack) > 2)
	{
		head = *stack;
		last = ft_lstlast_nv(head);
		*stack = head->next;
		last->next = head;
		head->next = NULL;
		return (1);
	}
	return (0);
}

int	push(t_stack **stack_sender, t_stack **stack_recipient)
{
	t_stack	*head_tmp;

	if (*stack_sender)
	{
		head_tmp = *stack_sender;
		*stack_sender = (*stack_sender)->next;
		head_tmp->next = *stack_recipient;
		*stack_recipient = head_tmp;
		return (1);
	}
	return (0);
}

int	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*second_last;

	if (ft_lstsize_nv(*stack) > 2)
	{
		last = ft_lstlast_nv(*stack);
		second_last = *stack;
		while (second_last->next != last)
			second_last = second_last->next;
		second_last->next = NULL;
		last->next = *stack;
		*stack = last;
		return (1);
	}
	return (0);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	if ((ft_lstsize_nv(*stack_a) < 2) || (ft_lstsize_nv(*stack_b) < 2))
		return ;
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("rrr\n");
}
