/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:17:56 by frrusso           #+#    #+#             */
/*   Updated: 2023/01/11 16:45:23 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	print_cub3d(t_cub3d *cub3d)
{
	size_t	i;

	printf("---------------------------------------------------------------\n");
	printf("mlx=%p\t\twin=%p\n", cub3d->mlx, cub3d->win);
	printf("width=%zu\t\theight=%zu\n", WIDTH, HEIGHT);
	printf("north=%p\t\tsouth=%p\n", cub3d->north, cub3d->south);
	printf("west=%p\t\teast=%p\n", cub3d->west, cub3d->east);
	printf("ceiling=%p\tfloor=%p\n", cub3d->ceiling, cub3d->floor);
	printf("map_width=%zu\t\t", cub3d->map_width);
	printf("map_height=%zu\n", cub3d->map_height);
	printf("map=%p\n", cub3d->map);
	i = 0;
	while (cub3d->map[i])
	{
		printf("map[%zu]=%s", i, cub3d->map[i]);
		i++;
	}
	printf("x=%f\t\t", cub3d->x);
	printf("y=%f\n", cub3d->y);
	printf("---------------------------------------------------------------\n");
}
