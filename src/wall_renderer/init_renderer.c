/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_renderer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:36:40 by sle-huec          #+#    #+#             */
/*   Updated: 2023/01/18 00:01:15 by sam              ###   ########.fr       */
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
	s->time = 0;
	s->oldTime = 0;
	get_start_orientation(s);
}

// NE PAS OUBLIER D ARRONDIR AVEC FLOOR
#include <stdio.h>
void	get_start_orientation(t_cub3d *s)
{
	int pos_x = floor(s->x);
	int pos_y = floor(s->y);

	if (s->map[pos_y][pos_x] == NORTH)
		init_orientation_from_player(s, NORTH);
	else if(s->map[pos_y][pos_x] == SOUTH)
		printf("it is SOUTH orientation\n");
	else if(s->map[pos_y][pos_x] ==  EAST)
		printf("it is EAST orientation\n");
	else if(s->map[pos_y][pos_x] == WEST)
		printf("it is WEST orientation\n");
}

// faire une fonction avec les 4 valeurs en les passant en param?? 
// il faut additionner le vecteur avec la pos

// here : FOV_PLANE_WIDTH est egale à 1 car v_dir == 1 et pour garantir le 
// fov de 90degres il faut que plane == dir
void init_orientation_from_player(t_cub3d *s, int orientation)
{
	if (orientation == NORTH)
	{
		s->v_dir_y= -1;
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