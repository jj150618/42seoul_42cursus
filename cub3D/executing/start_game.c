/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghkim <junghkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 16:45:11 by junghkim          #+#    #+#             */
/*   Updated: 2021/05/23 16:45:12 by junghkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "start_game.h"

void	ft_init_all(t_adata *a)
{
	ft_init_win(a);
	ft_init_map(a);
	ft_init_player(a);
	ft_init_texts(a);
	ft_init_rays(a);
	ft_init_sprites(a);
}

int		render_next_frame(t_adata *a)
{
	ft_init_img_3d(a);
	ft_update_player(a);
	update_sprites(a);
	draw_floorrgb(a);
	draw_ceilingrgb(a);
	draw3d(a);
	draw_map(a);
	mlx_put_image_to_window(a->win.mlx, a->win.win, a->img_3d.ptr, 0, 0);
	destroyimg(a, &a->img_3d);
	return (0);
}

int		start_game(t_adata *a)
{
	ft_init_all(a);
	mlx_do_key_autorepeatoff(a->win.mlx);
	mlx_hook(a->win.win, 2, 1L << 0, &butt_pressed, a);
	mlx_hook(a->win.win, 3, 1L << 1, &butt_released, a);
	mlx_hook(a->win.win, 17, 1L << 17, &clicked_cross, a);
	mlx_loop_hook(a->win.mlx, &render_next_frame, a);
	mlx_loop(a->win.mlx);
	return (1);
}
