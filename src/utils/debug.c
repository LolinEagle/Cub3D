/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrusso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:17:56 by frrusso           #+#    #+#             */
/*   Updated: 2022/12/20 13:18:00 by frrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	print_cub3d(t_cub3d *cub3d)
{
	int	i;

	printf("---------------------------------------------------------------\n");
	printf("mlx=%p\t\twin=%p\n", cub3d->mlx, cub3d->win);
	printf("width=%i\t\theight=%i\n", cub3d->width, cub3d->height);
	printf("north=%p\t\tsouth=%p\n", cub3d->north, cub3d->south);
	printf("west=%p\t\teast=%p\n", cub3d->west, cub3d->east);
	printf("ceiling=%p\tfloor=%p\n", cub3d->ceiling, cub3d->floor);
	printf("map_width=%i\t\tmap_height=%i", cub3d->map_width, cub3d->map_height);
	printf("\nmap=%p\n", cub3d->map);
	i = 0;
	while (cub3d->map[i])
	{
		printf("map[%i]=%s", i, cub3d->map[i]);
		i++;
	}
	printf("---------------------------------------------------------------\n");
}
