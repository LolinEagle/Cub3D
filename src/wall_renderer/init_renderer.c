/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_renderer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:36:40 by sle-huec          #+#    #+#             */
/*   Updated: 2023/01/16 20:17:28 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	init_var_renderer(t_cub3d *wall_renderer)
{
	wall_renderer->v_dir_x = -1; // modifier ces val en fonction des pts cardinaux
	wall_renderer->v_dir_y = 0;
	wall_renderer->v_camera_plane_y = 0.90;
	wall_renderer->v_camera_plane_x = 0;	
}

// NE PAS OUBLIER D ARRONDIR AVEC FLOOR
#include <stdio.h>
void	init_orientation_from_player(t_cub3d *s)
{
	int pos_x = floor(s->x);
	int pos_y = floor(s->y);

	if (s->map[pos_y][pos_x] == NORTH)
		printf("it is NORTH orientation\n");
	else if(s->map[pos_y][pos_x] == SUD)
		printf("it is SOUTH orientation\n");
	else if(s->map[pos_y][pos_x] ==  EAST)
		printf("it is EAST orientation\n");
	else if(s->map[pos_y][pos_x] == WEST)
		printf("it is WEST orientation\n");
}
