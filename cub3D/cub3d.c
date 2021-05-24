/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghkim <junghkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 16:41:28 by junghkim          #+#    #+#             */
/*   Updated: 2021/05/23 21:08:11 by junghkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		cub3d(char *cubname)
{
	int			fd;
	t_data		a;

	ft_start_map(&a.parse);
	fd = open(cubname, O_RDONLY);
	if (fd <= 0)
		return (ft_error(WRONG_FILE));
	cub_extract(&a.parse, fd);
	if (a.parse.error)
	{
		write(1, "there was an error while extracting", 36);
		return (0);
	}
	if (!ft_parse_cub(a.parse.text, &a.parse))
	{
		ft_freetext(a.parse.text);
		free_all_texts(&a.parse);
		return (0);
	}
	start_game(&a);
	return (1);
}

int		main(int argc, char **argv)
{
	if (argc < 2)
		write(1, "You forgot the cub file name", 29);
	else if (argc == 2)
	{
		if (!is_cubfile(argv[1]))
			return (ft_error(WRONG_CUB));
		cub3d(argv[1]);
	}
	else if (argc == 3)
	{
		if (!(ft_strncmp("--save", argv[2], ft_strlen(argv[2]))) &&
				ft_strlen(argv[2]) == 6)
			screenshot(argv[1]);
		else
			write(1, "WRONG", 6);
	}
	else
		write(1, "WRONG", 6);
}
