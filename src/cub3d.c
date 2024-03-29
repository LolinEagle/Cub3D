/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:59:27 by frrusso           #+#    #+#             */
/*   Updated: 2023/01/24 16:05:15 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	deal_close(void *mlx)
{
	mlx_loop_end(mlx);
	return (0);
}

int	deal_key(int key, t_cub3d *cub3d)
{
	if (key == ESC)
		mlx_loop_end(cub3d->mlx);
	if (key == W || key == UP)
		move_front(cub3d);
	if (key == A)
		move_left(cub3d);
	if (key == S || key == DOWN)
		move_back(cub3d);
	if (key == D)
		move_right(cub3d);
	if (key == LEFT)
		rotation_left(cub3d);
	if (key == RIGHT)
		rotation_right(cub3d);
	return (0);
}

int	deal_loop(t_cub3d *cub3d)
{
	if (cub3d->bonus)
	{
		mlx_mouse_get_pos(cub3d->mlx, cub3d->win, \
			&cub3d->mouse_x, &cub3d->mouse_y);
		if (cub3d->mouse_x < WIDTH / 3 && cub3d->mouse_x > 0
			&& cub3d->mouse_y > 0 && cub3d->mouse_y < HEIGHT)
			rotation_left(cub3d);
		if (cub3d->mouse_x > (WIDTH / 3) * 2 && cub3d->mouse_x < WIDTH
			&& cub3d->mouse_y > 0 && cub3d->mouse_y < HEIGHT)
			rotation_right(cub3d);
		put_image_to_image(cub3d, cub3d->ceiling, 0, 0);
		put_image_to_image(cub3d, cub3d->floor, 0, H_HALF);
		cast_ray(cub3d);
		minimap(cub3d);
	}
	else
	{
		put_image_to_image(cub3d, cub3d->ceiling, 0, 0);
		put_image_to_image(cub3d, cub3d->floor, 0, H_HALF);
		cast_ray(cub3d);
	}
	mlx_put_image_to_window(cub3d->mlx, cub3d->win, cub3d->win_buffer, 0, 0);
	return (0);
}

void	cub3d_loop(t_cub3d *cub3d)
{
	mlx_hook(cub3d->win, 17, 0, deal_close, cub3d->mlx);
	mlx_hook(cub3d->win, 2, (1L << 0), deal_key, cub3d);
	mlx_loop_hook(cub3d->mlx, deal_loop, cub3d);
	mlx_loop(cub3d->mlx);
}
