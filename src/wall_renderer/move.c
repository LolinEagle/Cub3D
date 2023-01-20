/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:05:55 by sle-huec          #+#    #+#             */
/*   Updated: 2023/01/20 16:31:56 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	move_up(t_cub3d *s)
{
	int	pos_x;
	int	pos_y;
	int	dir_x;
	int	dir_y;

	pos_x = floor(s->x);
	pos_y = floor(s->y);
	dir_x = floor(s->v_dir_x);
	dir_y = floor(s->v_dir_y);
	if (s->map[(int)(pos_x + dir_x)][pos_y] != '1')
		s->x += s->v_dir_x * MOVE_SPEED;
	if (s->map[pos_x][(int)(pos_y + dir_y)] != '1')
		s->y += s->v_dir_y * MOVE_SPEED;
}

void	move_down(t_cub3d *s)
{
	int	pos_x;
	int	pos_y;
	int	dir_x;
	int	dir_y;

	pos_x = floor(s->x);
	pos_y = floor(s->y);
	dir_x = floor(s->v_dir_x);
	dir_y = floor(s->v_dir_y);
	if (s->map[pos_y][(int)(pos_x + dir_x)] != '1')
		s->x -= s->v_dir_x * MOVE_SPEED;
	if (s->map[(int)(pos_y + dir_y)][pos_x] != '1')
		s->y -= s->v_dir_y * MOVE_SPEED;
}

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
