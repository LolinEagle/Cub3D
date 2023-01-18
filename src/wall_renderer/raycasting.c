/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:16:34 by sle-huec          #+#    #+#             */
/*   Updated: 2023/01/18 19:04:31 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	dda(t_cub3d *s)
{
	if (s->first_dist_x < s->first_dist_y)
	{
		s->first_dist_x += s->delta_x;
		s->tile_x += s->step_x;
		s->side = 0;
	}
	else
	{
		s->first_dist_y += s->delta_y;
		s->tile_y += s->step_y;
		s->side = 1;
	}
}

void	calculate_data(t_cub3d *s, int x)
{
	s->ratio_camera_x = 2 * x / (double)WIDTH - 1;
	s->ray_dir_x = s->v_dir_x + s->v_camera_plane_x * s->ratio_camera_x;
	s->ray_dir_y = s->v_dir_y + s->v_camera_plane_y * s->ratio_camera_x;
	s->delta_x = fabs(1 / s->ray_dir_x);
	s->delta_y = fabs(1 / s->ray_dir_y);
}

void	calculate_dist_on_camera(t_cub3d *s)
{
	if (s->side == 0)
		s->perp_wall_dist = (s->first_dist_x - s->delta_x);
	else
		s->perp_wall_dist = (s->first_dist_y - s->delta_y);
}

// si ca plante rajouter 1e30 ds if else voir tuto
void	cast_ray(t_cub3d *s)
{
	int	x;
	int	pos_tile_x;
	int	pos_tile_y;

	x = 0;
	pos_tile_x = floor(s->tile_x);
	pos_tile_y = floor(s->tile_y);
	s->tile_x = s->x;
	s->tile_y = s->y;
	while (x < WIDTH)
	{
		calculate_data(s, x);
		init_first_dist(s);
		while (s->flag_hit_wall == 0)
		{
			dda(s);
			if (s->map[pos_tile_x][pos_tile_y] > 0)
				s->flag_hit_wall = 1;
		}
		calculate_dist_on_camera(s);
		draw(s, x);
		x++;
	}
}

// prbleme : OU et COMMENT init tilex et tiley ??
// probleme: exactitude des coordonnés , orientation etc
// problem : erreur ds les types step : int et non double, à corriger?
// manque condition pour une boucle (while (!done))