/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_renderer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:36:40 by sle-huec          #+#    #+#             */
/*   Updated: 2023/01/16 17:39:57 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	init_var_renderer(t_cub3d *wall_renderer)
{
	wall_renderer->player_size = 32;       // a mettre en define
	wall_renderer->wall_size = 64;       // a mettre en define
	wall_renderer->fov = 90;       // a mettre en define
	wall_renderer->v_dir_x = -1; // modifier ces val en fonction des pts cardinaux
	wall_renderer->v_dir_y = 0;
	wall_renderer->v_camera_plane_y = 0.60; // en foncton du fov?? // tatonnement
	wall_renderer->v_camera_plane_x = 0;	
}

// NE PAS OUBLIER D ARRONDIR AVEC FLOOR
#include <stdio.h>
void	init_orientation_from_player(t_cub3d *s)
{
	if(s->map[s->y][s->x] == "N")
		printf("it is N\n");
	else
		printf("pouet\n");
}

