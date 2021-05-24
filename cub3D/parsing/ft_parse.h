/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghkim <junghkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 16:42:52 by junghkim          #+#    #+#             */
/*   Updated: 2021/05/23 16:42:53 by junghkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSE_H
# define FT_PARSE_H

enum	e_errors
{
	WRONG_CUB,
	WRONG_FILE,
	PARSING_ERROR
};

int		check_resolution(char **text, t_parse *parse, int *i, int *count);
int		check_textures(char **text, t_parse *parse, int *i, int *count);
int		check_rgbs(char **text, t_parse *parse, int *i, int *count);
int		check_valid_chars(char **text, int *i);
int		is_map(char *str);
void	*ft_realloctabs(char *str, int tab_nbr);
void	*ft_freetext(char **strs);
void	ft_start_map(t_parse *parse);
int		ft_countchr(char *str, char c);
int		cub_extract(t_parse *parse, int fd);
int		ft_parse_cub(char **text, t_parse *parse);
int		ft_isspace(char c);
int		ft_error(int errornbr);
int		ft_parse_NO(char *str, t_parse *parse);
int		ft_parse_SO(char *str, t_parse *parse);
int		ft_parse_WE(char *str, t_parse *parse);
int		ft_parse_EA(char *str, t_parse *parse);
int		ft_parse_S(char *str, t_parse *parse);
int		check_multiplayer(char *str, t_parse *parse);
int		check_valid_map(char **strs, t_parse *parse);
int		ft_copy_map(char **map_start, t_parse *parse);
int		start_game(t_adata *a);
void	screenshot(char *cubname);
void	ft_free_to_str(char ***strs, int prev);
void	ft_init_textures(t_parse *parse);
void	free_all_texts(t_parse *parse);

#endif
