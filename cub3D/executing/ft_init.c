/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghkim <junghkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 16:44:31 by junghkim          #+#    #+#             */
/*   Updated: 2021/05/23 18:43:10 by junghkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "start_game.h"

int		ft_init_sprites(t_adata *a)
{
	a->sps.number = ft_countsprites(a->map.maptxt);
	a->sps.items = malloc(sizeof(t_item) * (a->sps.number));
	add_sprites(a->sps.items, a->map.maptxt, a);
	return (0);
}

int		ft_init_texts(t_adata *a)
{
	ft_init_text(a, &a->notext.imgt, a->parse.no_text);
	ft_init_text(a, &a->sotext.imgt, a->parse.so_text);
	ft_init_text(a, &a->wetext.imgt, a->parse.we_text);
	ft_init_text(a, &a->eatext.imgt, a->parse.ea_text);
	return (0);
}

void	ft_init_player(t_adata *a)
{
	ft_playerinfo(&a->map, &a->joe, a->map.maptxt);
	a->joe.radius = a->map.tile_size / 6;
	a->joe.turndir = 0;
	a->joe.walkdir = 0;
	a->joe.movespeed = 0.35;
	a->joe.rotatespeed = 7 * (M_PI / 180);
}

void	ft_init_map(t_adata *a)
{
	a->map.maptxt = a->parse.mapstr;
	a->map.map_rows = ft_count_lines(a->map.maptxt);
	a->map.map_cols = ft_max_strlen(a->map.maptxt);
	a->map.tile_size = calculate_tilesize(a);
	a->map.map_h = a->map.map_rows * a->map.tile_size;
	a->map.map_w = a->map.map_cols * a->map.tile_size;
}

void	ft_init_win(t_adata *a)
{
	int		max_x;
	int		max_y;

	a->win.mlx = mlx_init();
	mlx_get_screen_size(a->win.mlx, &max_x, &max_y);
	if (a->parse.rx > max_x)
		a->parse.rx = max_x;
	if (a->parse.ry > max_y)
		a->parse.ry = max_y;
	a->win.win_w = a->parse.rx;
	a->win.win_h = a->parse.ry;
	a->win.win = mlx_new_window(a->win.mlx, a->win.win_w,
	a->win.win_h, "Hello, Cub3D");
}
