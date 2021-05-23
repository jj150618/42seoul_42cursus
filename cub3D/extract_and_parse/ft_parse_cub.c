/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_cub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghkim <junghkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 16:41:45 by junghkim          #+#    #+#             */
/*   Updated: 2021/05/23 16:41:47 by junghkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		all_but_map(char **text, t_parse *parse, int *i, int *count)
{
	ft_init_textures(parse);
	while (text[(*i)] && (*count) < 8)
	{
		if (!check_resolution(text, parse, i, count) ||
			!check_textures(text, parse, i, count) ||
			!check_rgbs(text, parse, i, count))
			return (0);
		if (!check_valid_chars(text, i))
			return (ft_error(INVALIDCHAR));
		if (text[(*i)][0] == '\0')
			(*i)++;
	}
	return (1);
}

int		ft_parse_cub(char **text, t_parse *parse)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	if (!all_but_map(text, parse, &i, &count))
		return (0);
	if (!text[i])
		return (ft_error(MISSINGPARAMS));
	while (!is_map(text[i]) && text[i])
		i++;
	if (!text[i])
		return (ft_error(INVALIDMAP));
	if (!check_valid_map(&text[i], parse))
		return (ft_error(INVALIDMAP));
	while (is_map(text[i + 1]) && text[i])
		i++;
	ft_freetext(parse->text);
	return (1);
}
