/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlindeza <hlindeza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:39:06 by hlindeza          #+#    #+#             */
/*   Updated: 2023/09/19 14:20:55 by hlindeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack	*get_min_node(t_stack **stack)
{
	t_stack	*head;
	t_stack	*node_min;
	int		var_control;

	node_min = NULL;
	var_control = 0;
	head = *stack;
	while (head)
	{
		if ((head->index == -1) && (!var_control
				|| head->value < node_min->value))
		{
			node_min = head;
			var_control = 1;
		}
		head = head->next;
	}
	return (node_min);
}

void	put_indexs(t_stack **stack)
{
	t_stack	*head;
	int		index;

	index = 0;
	head = get_min_node(stack);
	while (head)
	{
		head->index = index++;
		head = get_min_node(stack);
	}
}
