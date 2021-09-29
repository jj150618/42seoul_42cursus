/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 01:05:25 by junghkim          #+#    #+#             */
/*   Updated: 2021/09/30 01:06:42 by junghkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	from_size_one(t_stack *from, t_stack *to)
{
	if (to->size == 0)
	{
		to->top = from->top;
		to->bottom = to->top;
	}
	else
	{
		to->top->prev = from->top;
		from->top->next = to->top;
		to->top = to->top->prev;
	}
	from->top = NULL;
	from->bottom = NULL;
}

static void	push_pop(t_stack *from, t_stack *to)
{
	if (from->size == 1)
		from_size_one(from, to);
	else
	{
		if (to->size == 0)
		{
			to->top = from->top;
			to->bottom = to->top;
			from->top = from->top->next;
			from->top->prev = NULL;
			to->top->next = NULL;
		}
		else
		{
			to->top->prev = from->top;
			from->top = from->top->next;
			from->top->prev = NULL;
			to->top->prev->next = to->top;
			to->top = to->top->prev;
		}
	}
	to->size++;
	from->size--;
}

void	push_stack(t_stack *from, t_stack *to, int flag)
{
	if (from->size == 0)
		return ;
	push_pop(from, to);
	if (flag == 1)
		ft_putendl_fd("pa", 1);
	else if (flag == 2)
		ft_putendl_fd("pb", 1);
}
