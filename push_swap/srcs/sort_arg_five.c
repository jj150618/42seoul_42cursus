/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_arg_five.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 01:02:04 by junghkim          #+#    #+#             */
/*   Updated: 2021/09/30 01:04:18 by junghkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_five_a(int size, t_stack *a, t_stack *b)
{
	int	mid;
	int	push;
	int	rotate;

	push = 0;
	rotate = 0;
	mid = get_mid_value_five(a->top);
	while (size--)
	{
		if (a->top->value < mid)
		{
			push_stack(a, b, 2);
			push++;
		}
		else
		{
			rotate_stack(a, 1);
			rotate++;
		}
		if (push == 2)
			break ;
	}
	while (rotate--)
		reverse_rotate_stack(a, 1);
}

static void	sort_five_b(int size, t_stack *a, t_stack *b)
{
	int	mid;
	int	push;
	int	rotate;

	push = 0;
	rotate = 0;
	mid = get_mid_value_five(b->top);
	while (size--)
	{
		if (b->top->value >= mid)
		{
			push_stack(b, a, 1);
			push++;
		}
		else
		{
			rotate_stack(b, 2);
			rotate++;
		}
		if (push == 3)
			break ;
	}
	while (rotate--)
		reverse_rotate_stack(b, 2);
}

void	hanlde_sort_five(int size, t_stack *a, t_stack *b, int flag)
{
	if (flag == 1)
		sort_five_a(size, a, b);
	else
		sort_five_b(size, a, b);
	handle_arg_three_a(3, a);
	handle_arg_two(a, b, 2);
}

void	handle_arg_five(t_stack *a, t_stack *b)
{
	int	pb;
	int	mid;

	pb = 0;
	mid = get_mid_value_five(a->top);
	while (1)
	{
		if (a->top->value < mid)
		{
			push_stack(a, b, 2);
			pb++;
		}
		else
			rotate_stack(a, 1);
		if (pb == 2)
			break ;
	}
	handle_arg_three_a(3, a);
	handle_arg_two(a, b, 2);
}
