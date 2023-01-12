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

void	debug_minimap_full(t_cub3d *cub3d)
{
	size_t	x;
	size_t	y;

	y = -1;
	while (cub3d->map[++y])
	{
		x = -1;
		while (cub3d->map[y][++x] && cub3d->map[y][x] != '\n')
		{
			if (x == floor(cub3d->x) && y == floor(cub3d->y))
				mlx_put_image_to_window(cub3d->mlx, cub3d->win, cub3d->player,
					x * MINIMAP_SIZE, y * MINIMAP_SIZE);
			else if (char_in_string(cub3d->map[y][x], " 1"))
				mlx_put_image_to_window(cub3d->mlx, cub3d->win, cub3d->walls,
					x * MINIMAP_SIZE, y * MINIMAP_SIZE);
			else if (char_in_string(cub3d->map[y][x], "0NSWE"))
				mlx_put_image_to_window(cub3d->mlx, cub3d->win, cub3d->empty,
					x * MINIMAP_SIZE, y * MINIMAP_SIZE);
		}
		while (x < cub3d->map_width)
			mlx_put_image_to_window(cub3d->mlx, cub3d->win, cub3d->walls, x++ *\
				MINIMAP_SIZE, y * MINIMAP_SIZE);
	}
}

void	debug_minimap_parsing(t_cub3d *cub3d, size_t x, size_t y, int yy)
{
	int		xx;

	xx = floor(cub3d->x) - MINIMAP_LEN_HALF + x;
	if (xx >= 0 && yy >= 0 && (size_t)xx < cub3d->map_width
		&& (size_t)yy < cub3d->map_height
		&& (size_t)xx < strlen_endl(cub3d->map[yy]))
	{
		if (xx == floor(cub3d->x) && yy == floor(cub3d->y))
			mlx_put_image_to_window(cub3d->mlx, cub3d->win, cub3d->player,
				x * MINIMAP_SIZE, y * MINIMAP_SIZE);
		else if (char_in_string(cub3d->map[yy][xx], " 1"))
			mlx_put_image_to_window(cub3d->mlx, cub3d->win, cub3d->walls,
				x * MINIMAP_SIZE, y * MINIMAP_SIZE);
		else if (char_in_string(cub3d->map[yy][xx], "0NSWE"))
			mlx_put_image_to_window(cub3d->mlx, cub3d->win, cub3d->empty,
				x * MINIMAP_SIZE, y * MINIMAP_SIZE);
	}
	else
		mlx_put_image_to_window(cub3d->mlx, cub3d->win, cub3d->walls,
			x * MINIMAP_SIZE, y * MINIMAP_SIZE);
}

void	debug_minimap(t_cub3d *cub3d)
{
	size_t	x;
	size_t	y;
	int		yy;

	y = -1;
	while (++y < MINIMAP_LEN)
	{
		yy = floor(cub3d->y) - MINIMAP_LEN_HALF + y;
		x = -1;
		while (++x < MINIMAP_LEN)
			debug_minimap_parsing(cub3d, x, y, yy);
	}
}
