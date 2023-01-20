/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:05:55 by sle-huec          #+#    #+#             */
/*   Updated: 2023/01/20 15:44:44 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>


void	rotation_left(t_cub3d *s)
{
	s->old_dir_x = s->v_dir_x;
	s->v_dir_x = s->v_dir_x * cos(-MOVE_SPEED)
		- s->v_dir_y * sin(-MOVE_SPEED);
	s->v_dir_y = s->old_dir_x * sin(-MOVE_SPEED)
		+ s->v_dir_y * cos(-MOVE_SPEED);
	s->old_plane_x = s->v_camera_plane_x;
	s->v_camera_plane_x = s->v_camera_plane_x * cos(-MOVE_SPEED)
		- s->v_camera_plane_y * sin(-MOVE_SPEED);
	s->v_camera_plane_y = s->old_plane_x * sin(-MOVE_SPEED)
		+ s->v_camera_plane_y * cos(-MOVE_SPEED);
}

void	rotation_right(t_cub3d *s)
{
	s->old_dir_x = s->v_dir_x;
	s->v_dir_x = s->v_dir_x * cos(MOVE_SPEED)
		- s->v_dir_y * sin(MOVE_SPEED);
	s->v_dir_y = s->old_dir_x * sin(MOVE_SPEED)
		+ s->v_dir_y * cos(MOVE_SPEED);
	s->old_plane_x = s->v_camera_plane_x;
	s->v_camera_plane_x = s->v_camera_plane_x * cos(MOVE_SPEED)
		- s->v_camera_plane_y * sin(MOVE_SPEED);
	s->v_camera_plane_y = s->old_plane_x * sin(MOVE_SPEED)
		+ s->v_camera_plane_y * cos(MOVE_SPEED);
}
