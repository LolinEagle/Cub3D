/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:50:16 by sam               #+#    #+#             */
/*   Updated: 2023/01/23 12:52:06 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// header a refaire
#include <cub3D.h>

void	rotation_left(t_cub3d *s)
{
	s->old_dir_x = s->v_dir_x;
	s->v_dir_x = s->v_dir_x * cos(-ROT_SPEED)
		- s->v_dir_y * sin(-ROT_SPEED);
	s->v_dir_y = s->old_dir_x * sin(-ROT_SPEED)
		+ s->v_dir_y * cos(-ROT_SPEED);
	s->old_plane_x = s->v_camera_plane_x;
	s->v_camera_plane_x = s->v_camera_plane_x * cos(-ROT_SPEED)
		- s->v_camera_plane_y * sin(-ROT_SPEED);
	s->v_camera_plane_y = s->old_plane_x * sin(-ROT_SPEED)
		+ s->v_camera_plane_y * cos(-ROT_SPEED);
}

void	rotation_right(t_cub3d *s)
{
	s->old_dir_x = s->v_dir_x;
	s->v_dir_x = s->v_dir_x * cos(ROT_SPEED)
		- s->v_dir_y * sin(ROT_SPEED);
	s->v_dir_y = s->old_dir_x * sin(ROT_SPEED)
		+ s->v_dir_y * cos(ROT_SPEED);
	s->old_plane_x = s->v_camera_plane_x;
	s->v_camera_plane_x = s->v_camera_plane_x * cos(ROT_SPEED)
		- s->v_camera_plane_y * sin(ROT_SPEED);
	s->v_camera_plane_y = s->old_plane_x * sin(ROT_SPEED)
		+ s->v_camera_plane_y * cos(ROT_SPEED);
}
