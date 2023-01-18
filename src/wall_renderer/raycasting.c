/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:16:34 by sle-huec          #+#    #+#             */
/*   Updated: 2023/01/18 16:46:30 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

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

void	dda(t_cub3d *s)
{
	if (s->first_dist_x < s->first_dist_y)
	{
		s->first_dist_x += s->delta_x;
		s->tile_x += s->step_x;
		// here orientation: side = 0
	}
	else
	{
		s->first_dist_y += s->delta_y;
		s->tile_y += s->step_y;
		//side = 1;
	}
}

// si ca plante rajouter 1e30 ds if else voir tuto
void	cast_ray(t_cub3d *s)
{
	int	x;
	int	pos_tile_x;
	int	pos_tile_y;

	x = 0;
	s->tile_x = s->x;
	s->tile_y = s->y;
	
	while (x < WIDTH)
	{
		s->ratio_camera_x = 2 * x / (double)WIDTH - 1;
		s->ray_dir_x = s->v_dir_x + s->v_camera_plane_x * s->ratio_camera_x;
		s->ray_dir_y = s->v_dir_y + s->v_camera_plane_y * s->ratio_camera_x;
		s->delta_x = fabs(1 / s->ray_dir_x);
		s->delta_y = fabs(1 / s->ray_dir_y);
		init_first_dist(s);
		while (s->flag_hit_wall == 0)
		{
			dda(s);
			if (s->map[s->tile_x][s->tile_y] > 0)
				s->flag_hit_wall = 1;
		}
		x++;
	}
}

// prbleme : OU et COMMENT init tilex et tiley ??
// probleme: exactitude des coordonnés , orientation etc
