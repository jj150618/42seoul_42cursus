/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 10:02:26 by junghkim          #+#    #+#             */
/*   Updated: 2020/10/22 10:55:41 by junghkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *temp;
	t_list *curr;

	curr = *lst;
	while (curr)
	{
		temp = curr->next;
		ft_lstdelone(curr, del);
		curr = temp;
	}
}
