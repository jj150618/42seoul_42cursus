/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 01:05:39 by junghkim          #+#    #+#             */
/*   Updated: 2021/09/30 01:05:43 by junghkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_stack(t_stack *stack, int flag)
{
	t_node	*temp;
	t_node	*bottom_prev;

	if (stack->size < 2)
		return ;
	temp = stack->bottom;
	bottom_prev = stack->bottom->prev;
	stack->top->prev = temp;
	temp->next = stack->top;
	temp->prev = NULL;
	stack->top = temp;
	stack->bottom = bottom_prev;
	stack->bottom->next = NULL;
	if (flag == 1)
		ft_putendl_fd("rra", 1);
	else if (flag == 2)
		ft_putendl_fd("rrb", 1);
}

void	reverse_rotate_all_stack(t_stack *a, t_stack *b, int flag)
{
	reverse_rotate_stack(a, flag);
	reverse_rotate_stack(b, flag);
	if (flag == 3)
		ft_putendl_fd("rrr", 1);
}
