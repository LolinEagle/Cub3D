/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:16:34 by sle-huec          #+#    #+#             */
/*   Updated: 2023/01/18 14:18:15 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	cast_ray(t_cub3d *s)
{
	size_t	x;

	x = 0;
	while (x < s->map_width)
	s->ratio_camera_x = 2 * x / (double)s->map_width - 1;
	s->ray_dir_x = s->v_dir_x + s->v_camera_plane_x * s->ratio_camera_x;
	s->ray_dir_y = s->v_dir_y + s->v_camera_plane_y * s->ratio_camera_x;
	x++;
}