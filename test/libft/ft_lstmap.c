/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 12:54:59 by yewlee            #+#    #+#             */
/*   Updated: 2020/07/14 16:38:12 by yewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list	*new;
	t_list	*new_cur;
	t_list	*cur;

	if (!lst || !f)
		return (0);
	new = ft_lstnew(f(lst->content));
	if (!new)
		return (0);
	cur = lst->next;
	new_cur = new;
	while (cur)
	{
		new_cur->next = ft_lstnew(f(cur->content));
		if (!new_cur->next)
		{
			ft_lstclear(&new, del);
			return (0);
		}
		cur = cur->next;
		new_cur = new_cur->next;
	}
	return (new);
}
