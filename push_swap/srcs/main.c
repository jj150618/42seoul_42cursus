/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 00:45:47 by junghkim          #+#    #+#             */
/*   Updated: 2021/09/30 00:48:17 by junghkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	t_node	*node;

	node = a->top;
	while (node)
	{
		if (node->next)
		{
			if (node->value > node->next->value)
				return (0);
		}
		if (node->next)
			node = node->next;
		else
			break ;
	}
	if (node->value == a->bottom->value)
		return (1);
	else
		return (0);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	if (argc > 1)
	{
		a = init_stack();
		a->top = make_stack(argc, argv, &a);
		check_duplicate(a->top);
		b = init_stack();
		if (is_sorted(a))
		{
			free_all(a, b);
			return (0);
		}
		push_swap(a, b);
		free_all(a, b);
	}
	return (0);
}
