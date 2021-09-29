/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 00:46:19 by junghkim          #+#    #+#             */
/*   Updated: 2021/09/30 00:46:22 by junghkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	ft_putendl_fd("Error", 2);
	exit(0);
}

void	init_value(t_value *var)
{
	var->ra = 0;
	var->rb = 0;
	var->pa = 0;
	var->pb = 0;
}

void	select_pivot(int r, t_stack *stack, t_value *var)
{
	long	min;
	long	max;

	min = get_min_value(stack->top, r);
	max = get_max_value(stack->top, r);
	var->piv_big = (min + max) / 2;
	var->piv_small = (min + var->piv_big) / 2;
}

void	push_swap(t_stack *a, t_stack *b)
{
	int	cnt;

	cnt = 0;
	if (a->size == 5)
		handle_arg_five(a, b);
	else
		a_to_b(a->size, a, b, &cnt);
}
