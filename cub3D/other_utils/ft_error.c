/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghkim <junghkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 16:45:34 by junghkim          #+#    #+#             */
/*   Updated: 2021/05/23 21:07:18 by junghkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_error_pt3(int errornbr)
{
	if (errornbr == NOT_CUB_ERROR)
		write(1, "please use correct cub file", 28);
	if (errornbr == INVALID_FILE)
		write(1, "invalid file", 13);
	return (0);
}

int		ft_error_pt2(int errornbr)
{
	if (errornbr == BADSPRITE)
		write(1, "can't open sprite textures", 27);
	if (errornbr == MULTIFLOOR)
		write(1, "multiple floor colors", 22);
	if (errornbr == BADFLOOR)
		write(1, "invalid floor colors", 21);
	if (errornbr == MULTICEIL)
		write(1, "multiple ceiling colors", 24);
	if (errornbr == BADCEIL)
		write(1, "invalid ceiling colors", 23);
	if (errornbr == INVALIDMAP)
		write(1, "invalid map", 12);
	if (errornbr == INVALIDCHAR)
		write(1, "invalid character in cub text", 30);
	if (errornbr == MISSINGPARAMS)
		write(1, "missing at least one parameter", 31);
	if (errornbr == PARSING_ERROR)
		write(1, "there was an error while parsing", 33);
	return (0);
}

int		ft_error_pt1(int errornbr)
{
	if (errornbr == MULTIRES)
		write(1, "multiple resolutions", 21);
	if (errornbr == BADSCREEN)
		write(1, "invalid screensize!", 20);
	if (errornbr == MULTINO)
		write(1, "multiple north textures", 24);
	if (errornbr == BADNO)
		write(1, "can't open north textures", 26);
	if (errornbr == MULTISO)
		write(1, "multiple south textures", 24);
	if (errornbr == BADSO)
		write(1, "can't open south textures", 26);
	if (errornbr == MULTIWE)
		write(1, "multiple west textures", 23);
	if (errornbr == BADWE)
		write(1, "can't open west textures", 25);
	if (errornbr == MULTIEA)
		write(1, "multiple east textures", 23);
	if (errornbr == BADEA)
		write(1, "can't open east textures", 25);
	if (errornbr == MULTISPRITE)
		write(1, "multiple sprite textures", 25);
	return (0);
}

int		ft_error(int errornbr)
{
	ft_error_pt1(errornbr);
	ft_error_pt2(errornbr);
	ft_error_pt3(errornbr);
	return (0);
}
