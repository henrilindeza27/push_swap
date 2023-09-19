/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlindeza <hlindeza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 22:08:21 by hlindeza          #+#    #+#             */
/*   Updated: 2023/09/20 00:01:00 by hlindeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*head;
	t_stack	*tmp;

	head = *stack;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(stack);
}

static int	check_dup(int value, char **args, int index)
{
	index++;
	while (args[index])
	{
		if (ft_atoi(args[index]) == value)
			return (0);
		index++;
	}
	return (1);
}

int	ft_isnumber(char *c)
{
	int	i;

	i = 0;
	if (c[0] == '-' || c[0] == '+')
		i++;
	if (c[0] == '\0' || c[0] == ' ')
		return (0);
	if (c[i] == '\0' || c[i] == ' ')
		return (0);
	while (c[i])
	{
		if (!ft_isdigit(c[i]))
			return (0);
		i++;
	}
	return (1);
}

int	more_errors(char **numbrs, int tmp, int i)
{
	if (!(ft_isnumber(numbrs[i])) || (!(check_dup(tmp, numbrs, i))))
		return (0);
}

void	check_args(int argc, char **argv)
{
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
		tmp = ft_atoi(numbrs[i]);
		if (more_errors(numbrs, tmp, i) == 0 || (tmp < -2147483648
				|| tmp > 2147483647))
		{
			ft_printf("Error\n");
			ft_free(numbrs);
			exit(1);
		}
	}
	if (argc == 2)
		ft_free(numbrs);
}
