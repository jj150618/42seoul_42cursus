

#include "start_game.h"

void	ftinit_rays(t_adata *a)
{
	a->ray.fov = 60 * (M_PI / 180);
	a->ray.fovref_min = 2 * M_PI - (a->ray.fov / 2);
	a->ray.fovref_max = a->ray.fov / 2;
	a->ray.wall_strip_w = 1;
	a->ray.num_rays = a->win.win_w / a->ray.wall_strip_w;
	a->ray.distprojplane = (a->win.win_w / 2) / tan(a->ray.fov / 2);
}
