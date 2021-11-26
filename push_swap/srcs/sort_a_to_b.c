/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 01:02:46 by junghkim          #+#    #+#             */
/*   Updated: 2021/09/30 01:03:46 by junghkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	exceptional_cases(int r, t_stack *a, t_stack *b)
{
	if (r <= 3)
	{
		handle_under_three(r, a, b, 1);
		return (0);
	}
	else if (r == 5)
	{
		hanlde_sort_five(5, a, b, 1);
		return (0);
	}
	else
		return (1);
}

static void	push_rotate_a(t_stack *a, t_stack *b, t_value *var)
{
	if (a->top->value > var->piv_big)
	{
		rotate_stack(a, 1);
		var->ra++;
	}
	else
	{
		push_stack(a, b, 2);
		var->pb++;
		if (b->top->value > var->piv_small)
		{
			rotate_stack(b, 2);
			var->rb++;
		}
	}
}

static void	back_to_orig_ra(t_stack *a, t_stack *b, int *cnt, t_value *var)
{
	int	rrr;
	int	rem;

	rrr = var->rb;
	rem = var->ra - rrr;
	if ((*cnt) > 0)
	{
		while (rrr--)
			reverse_rotate_all_stack(a, b, 3);
		while (rem--)
			reverse_rotate_stack(a, 1);
	}
	else
	{
		while (rrr--)
			reverse_rotate_stack(b, 2);
	}
}

static void	back_to_orig_rb(t_stack *a, t_stack *b, int *cnt, t_value *var)
{
	int	rrr;
	int	rem;

	rrr = var->ra;
	rem = var->rb - rrr;
	if ((*cnt) > 0)
	{
		while (rrr--)
			reverse_rotate_all_stack(a, b, 3);
		while (rem--)
			reverse_rotate_stack(b, 2);
	}
	else
	{
		rrr = var->rb;
		while (rrr--)
			reverse_rotate_stack(b, 2);
	}
}

void	a_to_b(int r, t_stack *a, t_stack *b, int *cnt)
{
	int		r_temp;
	t_value	var;

	if (!exceptional_cases(r, a, b))
		return ;
	init_value(&var);
	select_pivot(r, a, &var);
	r_temp = r;
	while (r_temp--)
		push_rotate_a(a, b, &var);
	if (var.ra > var.rb)
		back_to_orig_ra(a, b, cnt, &var);
	else
		back_to_orig_rb(a, b, cnt, &var);
	a_to_b(var.ra, a, b, cnt);
	b_to_a(var.rb, a, b, cnt);
	b_to_a(var.pb - var.rb, a, b, cnt);
}
