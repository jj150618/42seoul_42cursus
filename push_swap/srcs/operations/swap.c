/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 01:06:11 by junghkim          #+#    #+#             */
/*   Updated: 2021/09/30 01:06:15 by junghkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_stack *stack, int flag)
{
	t_node	*temp;
	t_node	*top_next;

	if (stack->size < 2)
		return ;
	top_next = stack->top->next;
	temp = stack->top;
	if (stack->size > 2)
		top_next->next->prev = stack->top;
	temp->next = top_next->next;
	stack->top = top_next;
	stack->top->prev = NULL;
	stack->top->next = temp;
	temp->prev = stack->top;
	if (stack->size == 2)
		stack->bottom = stack->top->next;
	if (flag == 1)
		ft_putendl_fd("sa", 1);
	else if (flag == 2)
		ft_putendl_fd("sb", 1);
}

void	swap_all_stack(t_stack *a, t_stack *b, int flag)
{
	swap_stack(a, flag);
	swap_stack(b, flag);
	if (flag == 3)
		ft_putendl_fd("ss", 1);
}
