

#include "checker.h"

void	rotate_stack(t_stack *stack, int flag)
{
	t_node	*temp;
	t_node	*top_next;

	if (stack->size < 2)
		return ;
	temp = stack->top;
	top_next = stack->top->next;
	stack->bottom->next = temp;
	temp->prev = stack->bottom;
	temp->next = NULL;
	stack->bottom = temp;
	stack->top = top_next;
	stack->top->prev = NULL;
	if (flag == 1)
		ft_putendl_fd("ra", 1);
	else if (flag == 2)
		ft_putendl_fd("rb", 1);
}

void	rotate_all_stack(t_stack *a, t_stack *b, int flag)
{
	rotate_stack(a, flag);
	rotate_stack(b, flag);
	if (flag == 3)
		ft_putendl_fd("rr", 1);
}
