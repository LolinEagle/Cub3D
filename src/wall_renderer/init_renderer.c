/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_renderer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:36:40 by sle-huec          #+#    #+#             */
/*   Updated: 2023/01/11 17:43:44 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	init_var_renderer(t_wall_renderer *wall_renderer)
{
	wall_renderer->player_size = 32;
	wall_renderer->wall_size = 64;
	wall_renderer->fov = 60;
	wall_renderer->v_dir_x = -1; // modifier ces val en fonction des pts cardinaux
	wall_renderer->v_dir_y = 0;
	wall_renderer->v_camera_plane_x = 0;
	wall_renderer->v_camera_plane_y = 0.60; // en foncton du fov?? // tatonnement
	
}