/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghkim <junghkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 16:44:59 by junghkim          #+#    #+#             */
/*   Updated: 2021/05/23 16:44:59 by junghkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "start_game.h"

double		spawnrotation(char c)
{
	if (c == 'E')
		return (0);
	else if (c == 'S')
		return (M_PI_2);
	else if (c == 'W')
		return (M_PI);
	else
		return (3 * M_PI_2);
}

void		ft_playerinfo(t_map2d *map, t_player *joe, char **strs)
{
	int		i;
	int		j;

	i = 0;
	while (strs[i])
	{
		j = 0;
		while (strs[i][j])
		{
			if (ft_strchr("NSEW", strs[(int)i][(int)j]))
			{
				joe->x = (double)((j + 0.5) * map->tile_size);
				joe->y = (double)((i + 0.5) * map->tile_size);
				joe->rotangle = spawnrotation(strs[i][j]);
			}
			j++;
		}
		i++;
	}
}

double		calculate_tilesize(t_data *a)
{
	int		map_resratio_x;
	int		map_resratio_y;

	map_resratio_x = (int)((a->parse.rx / a->map.map_cols) / 3);
	map_resratio_y = (int)((a->parse.ry / a->map.map_rows) / 3);
	if (map_resratio_x < map_resratio_y)
		return ((double)(map_resratio_x));
	else
		return ((double)(map_resratio_y));
}

int			ft_max_strlen(char **strs)
{
	int		i;
	int		j;
	int		max_len;

	i = 0;
	j = 0;
	max_len = 0;
	while (strs[i])
	{
		j = 0;
		while (strs[i][j])
			j++;
		if (j > max_len)
			max_len = j;
		i++;
	}
	return (max_len);
}

int			ft_count_lines(char **strs)
{
	int i;

	i = 0;
	while (strs[i])
		i++;
	return (i);
}
