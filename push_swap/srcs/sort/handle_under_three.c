

#include "push_swap.h"

void	handle_arg_two(t_stack *a, t_stack *b, int flag)
{
	if (flag == 1)
	{
		if (a->top->value > a->top->next->value)
			swap_stack(a, 1);
	}
	else
	{
		if (b->top->value < b->top->next->value)
			swap_stack(b, 2);
		push_stack(b, a, 1);
		push_stack(b, a, 1);
	}
}

void	handle_under_three(int r, t_stack *a, t_stack *b, int flag)
{
	if (r == 3)
	{
		if (flag == 1)
			handle_arg_three_a(r, a);
		else
			handle_arg_three_b(r, a, b);
	}
	else if (r == 2)
		handle_arg_two(a, b, flag);
	else if (r == 1)
	{
		if (flag == 2)
			push_stack(b, a, 1);
	}
}
