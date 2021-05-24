/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghkim <junghkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 16:42:27 by junghkim          #+#    #+#             */
/*   Updated: 2021/05/24 20:47:11 by junghkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_walltextures_horiz(char **text, t_parse *parse,
		int *i, int *count)
{
	if (text[(*i)][0] == 'N' && text[(*i)][1] == 'O')
	{
		if (parse->no_text)
			return (ft_error(PARSING_ERROR));
		if (!ft_parse_no(text[(*i)], parse))
			return (ft_error(PARSING_ERROR));
		(*count)++;
		(*i)++;
	}
	if (text[(*i)][0] == 'S' && text[(*i)][1] == 'O')
	{
		if (parse->so_text)
			return (ft_error(PARSING_ERROR));
		if (!ft_parse_so(text[(*i)], parse))
			return (ft_error(PARSING_ERROR));
		(*count)++;
		(*i)++;
	}
	return (1);
}

int		check_walltextures_vert(char **text, t_parse *parse, int *i, int *count)
{
	if (text[(*i)][0] == 'W' && text[(*i)][1] == 'E')
	{
		if (parse->we_text)
			return (ft_error(PARSING_ERROR));
		if (!ft_parse_we(text[(*i)], parse))
			return (ft_error(PARSING_ERROR));
		(*count)++;
		(*i)++;
	}
	if (text[(*i)][0] == 'E' && text[(*i)][1] == 'A')
	{
		if (parse->ea_text)
			return (ft_error(PARSING_ERROR));
		if (!ft_parse_ea(text[(*i)], parse))
			return (ft_error(PARSING_ERROR));
		(*count)++;
		(*i)++;
	}
	return (1);
}

int		check_spritetextures(char **text, t_parse *parse, int *i, int *count)
{
	if (text[(*i)][0] == 'S' && text[(*i)][1] != 'O')
	{
		if (parse->sprite_text)
			return (ft_error(PARSING_ERROR));
		if (!ft_parse_S(text[(*i)], parse))
			return (ft_error(PARSING_ERROR));
		(*count)++;
		(*i)++;
	}
	return (1);
}

int		check_textures(char **text, t_parse *parse, int *i, int *count)
{
	if (!check_walltextures_horiz(text, parse, i, count))
		return (0);
	if (!check_walltextures_vert(text, parse, i, count))
		return (0);
	if (!check_spritetextures(text, parse, i, count))
		return (0);
	return (1);
}
