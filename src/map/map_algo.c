/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrusso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:26:43 by frrusso           #+#    #+#             */
/*   Updated: 2022/12/22 15:26:45 by frrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	map_spawn(t_cub3d *cub3d)
{
	size_t	i;
	size_t	y;

	i = 0;
	while (string_in_map(cub3d->map[i], "NSWE", 0) == 0)
		i++;
	y = i;
	i = 0;
	while (char_in_string(cub3d->map[y][i], "NSWE") == false)
		i++;
	cub3d->x = i + 0.5;
	cub3d->y = y + 0.5;
}

void	map_algo(t_cub3d *cub3d)
{
	size_t	x;
	size_t	y;

	y = -1;
	while (cub3d->map[++y])
	{
		x = -1;
		while (cub3d->map[y][++x])
		{
			if (char_in_string(cub3d->map[y][x], "0NSWE"))
			{
				if (x == 0 || y == 0
					|| x == cub3d->map_width - 1 || y == cub3d->map_height - 1
					|| char_in_string(cub3d->map[y][x - 1], "01NSWE") == false
					|| char_in_string(cub3d->map[y][x + 1], "01NSWE") == false
					|| x >= strlen_endl(cub3d->map[y - 1])
					|| char_in_string(cub3d->map[y - 1][x], "01NSWE") == false
					|| x >= strlen_endl(cub3d->map[y + 1])
					|| char_in_string(cub3d->map[y + 1][x], "01NSWE") == false)
					free_exit(cub3d, "Map not closed.\n");
			}
		}
	}
	map_spawn(cub3d);
}
