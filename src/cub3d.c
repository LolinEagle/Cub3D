/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:59:27 by frrusso           #+#    #+#             */
/*   Updated: 2023/01/20 16:33:22 by sle-huec         ###   ########.fr       */
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
		move_up(cub3d);
	if (key == A)
		cub3d->x -= 1;
	if (key == S || key == DOWN)
		move_down(cub3d);
	if (key == D)
		cub3d->x += 1;
	if (key == LEFT)
		rotation_left(cub3d);
	if (key == RIGHT)
		rotation_right(cub3d);
	return (0);
}

int	deal_loop(t_cub3d *cub3d)
{
	put_image_to_image(cub3d, cub3d->ceiling, 0, 0);
	put_image_to_image(cub3d, cub3d->floor, 0, H_HALF);
	cast_ray(cub3d);
	minimap(cub3d);
	print_raycasting_data(cub3d);
	mlx_put_image_to_window(cub3d->mlx, cub3d->win, cub3d->win_buffer, 0, 0);
	return (0);
}

void	cub3d_loop(t_cub3d *cub3d)
{
	mlx_hook(cub3d->win, 17, 0, deal_close, cub3d->mlx);
	mlx_key_hook(cub3d->win, deal_key, cub3d);
	mlx_loop_hook(cub3d->mlx, deal_loop, cub3d);
	mlx_loop(cub3d->mlx);
}
