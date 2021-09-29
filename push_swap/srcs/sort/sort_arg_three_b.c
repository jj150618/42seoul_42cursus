

#include "push_swap.h"

void	arg_three_top_min_b(t_stack *b, int max)
{
	if (b->size == 3)
	{
		rotate_stack(b, 2);
		if (b->top->next->value == max)
			swap_stack(b, 2);
	}
	else
	{
		swap_stack(b, 2);
		rotate_stack(b, 2);
		swap_stack(b, 2);
		reverse_rotate_stack(b, 2);
		if (b->top->next->value == max)
			swap_stack(b, 2);
	}
}

void	arg_three_middle_min_b(t_stack *b, int max)
{
	if (b->size == 3)
	{
		reverse_rotate_stack(b, 2);
		if (b->top->next->value == max)
			swap_stack(b, 2);
	}
	else
	{
		rotate_stack(b, 2);
		swap_stack(b, 2);
		reverse_rotate_stack(b, 2);
		if (b->top->next->value == max)
			swap_stack(b, 2);
	}
}

void	arg_three_bottom_min_b(t_stack *b, int max)
{
	if (b->top->next->value == max)
		swap_stack(b, 2);
}

void	handle_arg_three_b(int r, t_stack *a, t_stack *b)
{
	int	min;
	int	max;

	min = get_min_value(b->top, r);
	max = get_max_value(b->top, r);
	if (b->top->value == min)
		arg_three_top_min_b(b, max);
	else if (b->top->next->value == min)
		arg_three_middle_min_b(b, max);
	else if (b->top->next->next->value == min)
		arg_three_bottom_min_b(b, max);
	push_stack(b, a, 1);
	push_stack(b, a, 1);
	push_stack(b, a, 1);
}
