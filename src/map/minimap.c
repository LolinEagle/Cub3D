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
