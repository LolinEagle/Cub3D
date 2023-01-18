/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_renderer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:36:40 by sle-huec          #+#    #+#             */
/*   Updated: 2023/01/18 18:34:02 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	init_var_renderer(t_cub3d *s)
{
	s->distance = 0;
	s->v_camera_plane_x = 0;
	s->v_camera_plane_y = 0;
	s->v_dir_x = 0;
	s->v_dir_y = 0;
	s->ratio_camera_x = 0;
	s->ray_dir_x = 0;
	s->ray_dir_y = 0;
	s->first_dist_x = 0;
	s->first_dist_y = 0;
	s->step_x = 0;
	s->step_y = 0;
	s->delta_x = 0;
	s->delta_y = 0;
	s->tile_x = 0;
	s->tile_y = 0;
	s->flag_hit_wall = 0;
	s->side = 0;
	s->perp_wall_dist = 0;
	s->draw_start = 0;
	s->draw_end = 0;
	s->line_height = 0;
	get_start_orientation(s);
}

void	get_start_orientation(t_cub3d *s)
{
	int	pos_x;
	int	pos_y;

	pos_x = floor(s->x);
	pos_y = floor(s->y);
	if (s->map[pos_y][pos_x] == NORTH)
		init_orientation_from_player(s, NORTH);
	else if (s->map[pos_y][pos_x] == SOUTH)
		init_orientation_from_player(s, SOUTH);
	else if (s->map[pos_y][pos_x] == EAST)
		init_orientation_from_player(s, EAST);
	else if (s->map[pos_y][pos_x] == WEST)
		init_orientation_from_player(s, WEST);
}

void	init_orientation_from_player(t_cub3d *s, int orientation)
{
	if (orientation == NORTH)
	{
		s->v_dir_y = -1;
		s->v_camera_plane_x = FOV_PLANE_WIDTH;
	}
	if (orientation == SOUTH)
	{
		s->v_dir_y = 1;
		s->v_camera_plane_x = -FOV_PLANE_WIDTH;
	}
	if (orientation == EAST)
	{
		s->v_dir_x = 1;
		s->v_camera_plane_y = FOV_PLANE_WIDTH;
	}
	if (orientation == WEST)
	{
		s->v_dir_x = -1;
		s->v_camera_plane_y = -FOV_PLANE_WIDTH;
	}
}

void	init_first_dist(t_cub3d *s)
{
	if (s->ray_dir_x < 0)
	{
		s->step_x = -1;
		s->first_dist_x = (s->x - s->tile_x) * s->delta_x;
	}
	else
	{
		s->step_x = 1;
		s->first_dist_x = (s->tile_x + 1 - s->x) * s->delta_x;
	}
	if (s->ray_dir_y < 0)
	{
		s->step_y = -1;
		s->first_dist_y = (s->y - s->tile_y) * s->first_dist_y;
	}
	else
	{
		s->step_y = 1;
		s->first_dist_y = (s->tile_y + 1 - s->y) * s->first_dist_y;
	}
}
