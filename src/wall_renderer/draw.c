/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:24:22 by sle-huec          #+#    #+#             */
/*   Updated: 2023/01/19 18:46:07 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>
#include <stdio.h>

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

void draw_ver_line(t_cub3d *s, t_img *img)
{
	int h;
	
	h = s->draw_start;
	while (h < s->draw_end)
	{
		put_pixel_image(s->col_x_iterator, h, *img);
		h++;
	}
}

void	draw(t_cub3d *s, t_img *img)
{
	int	div;

	init_draw(s);
	div = 1 + s->side;
	img->r = 184 / div;
	img->g = 64 / div;
	img->b = 11 / div;
	draw_ver_line(s, img);
}
