/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_arg_three_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 01:03:00 by junghkim          #+#    #+#             */
/*   Updated: 2021/09/30 01:04:38 by junghkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	arg_three_top_min_a(t_stack *a, int max)
{
	if (a->size == 3)
	{
		if (a->top->next->value == max)
		{
			reverse_rotate_stack(a, 1);
			swap_stack(a, 1);
		}
	}
	else
	{
		if (a->top->next->value == max)
		{
			rotate_stack(a, 1);
			swap_stack(a, 1);
			reverse_rotate_stack(a, 1);
		}
	}
}

static void	arg_three_middle_min_a(t_stack *a, int max)
{
	if (a->size == 3)
	{
		if (a->bottom->value == max)
			swap_stack(a, 1);
		else
			rotate_stack(a, 1);
	}
	else
	{
		swap_stack(a, 1);
		if (a->top->next->value == max)
		{
			rotate_stack(a, 1);
			swap_stack(a, 1);
			reverse_rotate_stack(a, 1);
		}
	}
}

static void	arg_three_bottom_min_a(t_stack *a, int max)
{
	if (a->size == 3)
	{
		if (a->top->value == max)
			swap_stack(a, 1);
		reverse_rotate_stack(a, 1);
	}
	else
	{
		if (a->top->value == max)
			swap_stack(a, 1);
		rotate_stack(a, 1);
		swap_stack(a, 1);
		reverse_rotate_stack(a, 1);
		swap_stack(a, 1);
	}
}

void	handle_arg_three_a(int r, t_stack *a)
{
	int	min;
	int	max;

	min = get_min_value(a->top, r);
	max = get_max_value(a->top, r);
	if (a->top->value == min)
		arg_three_top_min_a(a, max);
	else if (a->top->next->value == min)
		arg_three_middle_min_a(a, max);
	else if (a->top->next->next->value == min)
		arg_three_bottom_min_a(a, max);
}
