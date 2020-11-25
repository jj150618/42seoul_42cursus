/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 12:54:19 by yewlee            #+#    #+#             */
/*   Updated: 2020/07/10 23:03:15 by yewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*t1;
	t_list	*t2;

	if (!lst || !del)
		return ;
	t1 = *lst;
	while (t1)
	{
		t2 = t1->next;
		ft_lstdelone(t1, del);
		t1 = t2;
	}
	*lst = NULL;
}
