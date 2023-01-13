/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrusso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:18:22 by frrusso           #+#    #+#             */
/*   Updated: 2023/01/11 14:18:25 by frrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	*minimap_image(t_cub3d *cub3d, char *str)
{
	int		wh[1];
	void	*ret;

	wh[0] = MINIMAP_SIZE;
	ret = mlx_xpm_file_to_image(cub3d->mlx, str, &wh[0], &wh[0]);
	if (ret == NULL)
		free_exit(cub3d, "fatal\n");
	return (ret);
}

void	minimap_parsing(t_cub3d *cub3d, size_t x, size_t y, int yy)
{
	int		xx;

	xx = floor(cub3d->x) - MINIMAP_W_LEN_HALF + x;
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

void	minimap(t_cub3d *cub3d)
{
	size_t	x;
	size_t	y;
	int		yy;

	y = 0;
	while (++y < MINIMAP_H_LEN)
	{
		yy = floor(cub3d->y) - MINIMAP_H_LEN_HALF + y;
		x = 0;
		while (++x < MINIMAP_W_LEN)
			minimap_parsing(cub3d, x, y, yy);
	}
}
