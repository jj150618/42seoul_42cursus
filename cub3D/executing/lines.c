/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghkim <junghkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 16:44:53 by junghkim          #+#    #+#             */
/*   Updated: 2021/05/24 21:09:31 by junghkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "start_game.h"

int		linesprite(t_item *item,
		t_data *a, int col_id)
{
	double remain_pixels;
	double pixelx;
	double pixely;
	double texx;
	double texy;

	pixelx = a->line_sp.start_x;
	pixely = a->line_sp.start_y;
	texy = 0;
	texx = set_bitmap_sp(item, col_id);
	remain_pixels = a->line_sp.pixels;
	while (remain_pixels > 0)
	{
		if (item->imgsp.addr[(int)texy * (int)item->imgsp.width + (int)texx])
			a->img_3d.addr[((int)pixely * (int)a->win.win_w + (int)pixelx)] =
			item->imgsp.addr[(int)texy * (int)item->imgsp.width + (int)texx];
		pixelx += a->line_sp.deltax;
		pixely += a->line_sp.deltay;
		texy = ((pixely - a->line_sp.start_y) *
		item->imgsp.width) / a->line_sp.pixels;
		--remain_pixels;
	}
	return (0);
}

int		line3d(t_ray *ray, t_data *a, t_text text_wallhit)
{
	double		remain_pixels;
	double		pixelx;
	double		pixely;
	int			texx;
	int			texy;

	pixelx = a->line_3d.start_x;
	pixely = a->line_3d.start_y;
	texy = 0;
	texx = set_bitmap(ray, a);
	remain_pixels = a->line_3d.pixels;
	while (remain_pixels > 0)
	{
		if (texy == text_wallhit.imgt.width)
			texy = text_wallhit.imgt.width - 1;
		a->img_3d.addr[((int)pixely * (int)a->win.win_w + (int)pixelx)] =
		text_wallhit.imgt.addr[(int)texy *
		(int)text_wallhit.imgt.width + (int)texx];
		pixelx += a->line_3d.deltax;
		pixely += a->line_3d.deltay;
		texy = ((pixely - a->line_3d.start_y) *
		text_wallhit.imgt.width) / a->line_3d.pixels;
		--remain_pixels;
	}
	return (0);
}

int		line(t_line line, t_data *a)
{
	double remain_pixels;
	double pixelx;
	double pixely;

	pixelx = line.start_x;
	pixely = line.start_y;
	remain_pixels = line.pixels;
	while (remain_pixels > 0)
	{
		a->img_3d.addr[(int)pixely * (int)a->win.win_w +
		(int)pixelx] = line.color;
		pixelx += line.deltax;
		pixely += line.deltay;
		--remain_pixels;
	}
	return (0);
}
