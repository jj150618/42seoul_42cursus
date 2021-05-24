/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_resolution.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghkim <junghkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 16:42:14 by junghkim          #+#    #+#             */
/*   Updated: 2021/05/23 18:10:20 by junghkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_screensize(char *str, t_parse *parse)
{
	int		i;

	i = 1;
	while (ft_isspace(str[i]))
		i++;
	parse->rx = ft_atoi(&str[i]);
	while (ft_isdigit(str[i]))
		i++;
	while (ft_isspace(str[i]))
		i++;
	parse->ry = ft_atoi(&str[i]);
	if (parse->rx <= 0 || parse->ry <= 0)
		return (0);
	return (1);
}

int	check_resolution(char **text, t_parse *parse, int *i, int *count)
{
	if (text[(*i)][0] == 'R')
	{
		if (parse->rx || parse->ry)
			return (ft_error(PARSING_ERROR));
		if (!ft_screensize(text[(*i)], parse))
			return (ft_error(PARSING_ERROR));
		(*count)++;
		(*i)++;
	}
	return (1);
}
