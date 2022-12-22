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

void	map_algo(t_cub3d *cub3d)
{
	size_t	i;
	size_t	x;
	size_t	y;

	i = 0;
	while (true)
	{
		if (string_in_map(cub3d->map[i], "NSWE", 0) == 1)
			break ;
		i++;
	}
	y = i;
	i = 0;
	while (true)
	{
		if (char_in_string(cub3d->map[y][i], "NSWE"))
			break ;
		i++;
	}
	x = i;
	if (!x || !y || x == cub3d->map_width - 1 || y == cub3d->map_height - 1)
		free_exit(cub3d, "The map must be closed.\n");
	cub3d->x = x + 0.5;
	cub3d->y = y + 0.5;
}
