/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrusso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:44:03 by frrusso           #+#    #+#             */
/*   Updated: 2022/12/14 16:44:04 by frrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	free_return(t_cub3d *cub3d)
{
	int	i;

	if (cub3d->win)
		mlx_destroy_window(cub3d->mlx, cub3d->win);
	if (cub3d->north)
		mlx_destroy_image(cub3d->mlx, cub3d->north);
	if (cub3d->south)
		mlx_destroy_image(cub3d->mlx, cub3d->south);
	if (cub3d->west)
		mlx_destroy_image(cub3d->mlx, cub3d->west);
	if (cub3d->east)
		mlx_destroy_image(cub3d->mlx, cub3d->east);
	if (cub3d->ceiling)
		mlx_destroy_image(cub3d->mlx, cub3d->ceiling);
	if (cub3d->floor)
		mlx_destroy_image(cub3d->mlx, cub3d->floor);
	i = -1;
	while (cub3d->map && cub3d->map[++i])
		free(cub3d->map[i]);
	free(cub3d->map);
	if (cub3d->mlx)
		mlx_destroy_display(cub3d->mlx);
	free(cub3d->mlx);
	return (0);
}

void	free_exit(t_cub3d *cub3d, char *err)
{
	free_return(cub3d);
	putstr_out(err);
	exit(1);
}

void	free_close(t_cub3d *cub3d, char *err, int fd)
{
	close(fd);
	free_exit(cub3d, err);
}
