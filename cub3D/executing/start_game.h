/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghkim <junghkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 16:45:16 by junghkim          #+#    #+#             */
/*   Updated: 2021/05/24 20:43:11 by junghkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef START_GAME_H
# define START_GAME_H

# include "cub3d.h"

# define LEFT_ARROW 123
# define RIGHT_ARROW 124
# define ESC_KEY 53
# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2

double			calculate_tilesize(t_data *a);
int				ft_max_strlen(char **strs);
int				ft_count_lines(char **strs);
void			ft_playerinfo(t_map2d *map, t_player *joe, char **strs);
void			ft_update_player(t_data *a);
int				butt_pressed(int keycode, t_data *a);
int				butt_released(int keycode, t_data *a);
int				clicked_cross(int keycode, t_data *a);
void			ft_init_rays(t_data *a);
int				draw3d(t_data *a);
int				line(t_line line, t_data *a);
double			normalrad(double movestep);
int				draw3dline(double ray_angle, t_ray *ray,
				t_data *a, int col_id);
int				update_sprites(t_data *a);
int				ft_countsprites(char **strs);
double			distancepoints(double x1, double y1, double x2, double y2);
int				add_sprites(t_item *items, char **strs, t_data *a);

void			ft_init_all(t_data *a);
int				ft_init_texts(t_data *a);
int				ft_init_text(t_data *a, t_img *imgt, char *textpath);
void			ft_init_win(t_data *a);
void			ft_init_map(t_data *a);
void			ft_init_player(t_data *a);
int				ft_init_sprites(t_data *a);
void			ft_init_img_3d(t_data *a);
int				ft_init_line(t_data *a);

int				destroyimg(t_data *a, t_img *img);
int				ft_prepare_3d_line(double ray_angle,
				t_ray *ray, t_data *a, int col_id);
int				line3d(t_ray *ray, t_data *a, t_text text_wallhit);
int				ft_prepare_sprite_line(t_item *item, t_data *a,
				int col_id);
int				linesprite(t_item *item,
				t_data *a, int col_id);
int				bitmap_offset(t_ray *ray, t_data *a);
int				bitmap_offset_sp(t_item *item, int col_id);
int				bitmap_offset_floor(t_data *a, double *x, double *y);
int				has_wall(double x, double y, t_data *a);
int				is_sprite_stripe(t_item *item, int col_id);

int				vertical_interstep(t_data *a, t_ray *ray,
				double *nexttouch_verx, double *nexttouch_very);
int				horizontal_interstep(t_data *a, t_ray *ray,
				double *nexttouch_horx, double *nexttouch_hory);
int				drawsps(t_ray *ray, t_data *a, int col_id);
int				vertical_cast_facingleft(t_data *a, t_ray *ray,
				double *nexttouch_verx, double *nexttouch_very);
int				vertical_cast_facingright(t_data *a, t_ray *ray,
				double *nexttouch_verx, double *nexttouch_very);
int				horizontal_cast_facingup(t_data *a, t_ray *ray,
				double *nexttouch_horx, double *nexttouch_hory);
int				horizontal_cast_facingdown(t_data *a, t_ray *ray,
				double *nexttouch_horx, double *nexttouch_hory);
void			horiz_vert_raycomp(t_data *a, t_ray *ray,
				double *horz_dist, double *vert_dist);

int				create_trgb(int t, int r, int g, int b);
int				draw_floorrgb(t_data *a);
int				draw_ceilingrgb(t_data *a);
int				find_text_wallhit(double ray_angle, t_ray *ray, t_data *a);
void			clean_sprites(t_data *a, t_sps *sps);

#endif
