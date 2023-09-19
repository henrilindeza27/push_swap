/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlindeza <hlindeza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:05:06 by hlindeza          #+#    #+#             */
/*   Updated: 2023/09/20 00:01:27 by hlindeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}					t_stack;

t_stack				*ft_lstnew_nv(int content);
void				ft_lstadd_back_nv(t_stack **lst, t_stack *new);
void				ft_lstadd_front_nv(t_stack **lst, t_stack *new);
int					ft_lstsize_nv(t_stack *lst);
t_stack				*ft_lstlast_nv(t_stack *lst);

int					a_is_sorted(t_stack **stack);
void				check_args(int argc, char **argv);
void				put_indexs(t_stack **stack);
void				init_stacks(t_stack **stack, int argc, char **argv);
void				free_stack(t_stack **stack);
void				ft_free(char **str);
int					get_bigger_index(t_stack **stack);
int					more_errors(char **numbrs, int tmp, int i);

int					swap(t_stack **stack);
int					rotate(t_stack **stack);
int					push(t_stack **stack_sender, t_stack **stack_recipient);
int					reverse_rotate(t_stack **stack);

void				sa(t_stack **stack_a);
void				sb(t_stack **stack_b);
void				ss(t_stack **stack_a, t_stack **stack_b);
void				pa(t_stack **stack_a, t_stack **stack_b);
void				pb(t_stack **stack_b, t_stack **stack_a);
void				ra(t_stack **stack_a);
void				rb(t_stack **stack_b);
void				rr(t_stack **stack_a, t_stack **stack_b);
void				rra(t_stack **stack_a);
void				rrb(t_stack **stack_b);
void				rrr(t_stack **stack_a, t_stack **stack_b);

void				sort_3_numbers(t_stack **stack);
void				sort_4_numbers(t_stack **stack_a, t_stack **stack_b);
void				sort_5_numbers(t_stack **stack_a, t_stack **stack_b);
void				radix(t_stack **stack_a, t_stack **stack_b);
void				sort(t_stack **stack_a, t_stack **stack_b);

#endif