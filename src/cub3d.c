/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrusso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:59:27 by frrusso           #+#    #+#             */
/*   Updated: 2022/12/12 15:59:29 by frrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	putstr_out(char *str)
{
	if (str == NULL)
		return (0);
	write(1, str, ft_strlen(str));
	return (0);
}

int	putstr_err(char *str)
{
	if (str == NULL)
		return (1);
	write(2, str, ft_strlen(str));
	return (1);
}

int	close_cub3d(void *mlx)
{
	mlx_loop_end(mlx);
	return (0);
}

int	deal_key(int key, t_cub3d *cub3d)
{
	if (key == ESC)
		mlx_loop_end(cub3d->mlx);
	return (0);
}

void	ft_cub3d(t_cub3d *cub3d)
{
	mlx_hook(cub3d->win, 17, 0, close_cub3d, cub3d->mlx);
	mlx_key_hook(cub3d->win, deal_key, cub3d);
	mlx_loop(cub3d->mlx);
	mlx_destroy_window(cub3d->mlx, cub3d->win);
	mlx_destroy_display(cub3d->mlx);
	free(cub3d->mlx);
}
