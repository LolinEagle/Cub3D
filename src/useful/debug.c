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
	size_t	i;

	printf("---------------------------------------------------------------\n");
	printf("mlx=%p\t\twin=%p\n", cub3d->mlx, cub3d->win);
	printf("north=%p\t\tsouth=%p\n", cub3d->north, cub3d->south);
	printf("west=%p\t\teast=%p\n", cub3d->west, cub3d->east);
	printf("ceiling=%p\tfloor=%p\n", cub3d->ceiling, cub3d->floor);
	printf("x=%f\t\ty=%f\n", cub3d->x, cub3d->y);
	printf("map_width=%zu\t\t", cub3d->map_width);
	printf("map_height=%zu\n", cub3d->map_height);
	printf("map=%p\n", cub3d->map);
	i = -1;
	while (cub3d->map && cub3d->map[++i])
		printf("map[%zu]=%s", i, cub3d->map[i]);
	printf("---------------------------------------------------------------\n");
}
