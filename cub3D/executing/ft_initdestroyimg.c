/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initdestroyimg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghkim <junghkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 16:44:39 by junghkim          #+#    #+#             */
/*   Updated: 2021/05/23 16:44:39 by junghkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "start_game.h"

int		destroyimg(t_data *a, t_img *img)
{
	mlx_destroy_image(a->win.mlx, img->ptr);
	img->ptr = 0;
	img->addr = 0;
	return (0);
}

void	ft_init_img_3d(t_data *a)
{
	a->img_3d.ptr = mlx_new_image(a->win.mlx, a->win.win_w, a->win.win_h);
	a->img_3d.addr = (int *)mlx_get_data_addr(a->img_3d.ptr,
	&a->img_3d.pixel_bits, &a->img_3d.line_bytes, &a->img_3d.endian);
}
