/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:24:22 by sle-huec          #+#    #+#             */
/*   Updated: 2023/01/19 10:37:32 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	init_draw(t_cub3d *s)
{
	s->line_height = (int)(HEIGHT / s->perp_wall_dist);
	s->draw_start = -s->line_height / 2 + HEIGHT / 2;
	if (s->draw_start < 0)
		s->draw_start = 0;
	s->draw_end = s->line_height / 2 + HEIGHT / 2;
	if (s->draw_end >= HEIGHT)
		s->draw_end = HEIGHT - 1;
}

void set_color(t_cub3d *s, t_img *rgb)
{
	
}

void	draw(t_cub3d *s, int x)
{
	init_draw(s);
	//set_color
	if (s->side = 1)
		
	
}
