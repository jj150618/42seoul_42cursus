/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horiz_vert_raycomp.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghkim <junghkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 16:44:49 by junghkim          #+#    #+#             */
/*   Updated: 2021/05/23 21:17:05 by junghkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "start_game.h"

void	horiz_vert_raycomp(t_data *a, t_ray *ray,
		double *horz_dist, double *vert_dist)
{
	if (ray->found_hor_wall)
		*horz_dist = distancepoints(a->joe.x, a->joe.y,
		ray->wall_hit_horx, ray->wall_hit_hory);
	else
		*horz_dist = 2147483647;
	if (ray->found_ver_wall)
		*vert_dist = distancepoints(a->joe.x, a->joe.y,
		ray->wall_hit_verx, ray->wall_hit_very);
	else
		*vert_dist = 2147483647;
	if (*horz_dist < *vert_dist)
	{
		ray->wall_hit_x = ray->wall_hit_horx;
		ray->wall_hit_y = ray->wall_hit_hory;
		ray->distance = *horz_dist;
		ray->hit_vertical = 0;
	}
	else
	{
		ray->wall_hit_x = ray->wall_hit_verx;
		ray->wall_hit_y = ray->wall_hit_very;
		ray->distance = *vert_dist;
		ray->hit_vertical = 1;
	}
}
