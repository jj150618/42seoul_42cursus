/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghkim <junghkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 16:45:30 by junghkim          #+#    #+#             */
/*   Updated: 2021/05/24 20:44:18 by junghkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clean_sprites(t_data *a, t_sps *sps)
{
	int		i;

	i = 0;
	while (i < sps->number)
	{
		destroyimg(a, &sps->items[i].imgsp);
		i++;
	}
	free(sps->items);
}

void	*ft_freetext(char **text)
{
	size_t	i;

	i = 0;
	while (text[i])
	{
		free(text[i]);
		i++;
	}
	free(text);
	return (0);
}

void	free_all_strs(char **strs)
{
	while (*strs)
	{
		free(*strs);
		strs++;
	}
}

int		ft_error(int error)
{
	if (error == WRONG_CUB)
		write(1, "please check the file's name", 29);
	if (error == WRONG_FILE)
		write(1, "please check the file", 13);
	if (error == PARSING_ERROR)
		write(1, "An error occurred during parsing", 33);
	return (0);
}
