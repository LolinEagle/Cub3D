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
	if (cub3d->win)
		mlx_destroy_window(cub3d->mlx, cub3d->win);
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
