/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:24:22 by sle-huec          #+#    #+#             */
/*   Updated: 2023/01/23 19:08:49 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	init_draw(t_cub3d *s)
{
	if (s->perp_wall_dist == 0)
		s->line_height = HEIGHT - 2;
	else
		s->line_height = (int)(HEIGHT / s->perp_wall_dist);
	s->draw_start = -s->line_height / 2 + HEIGHT / 2;
	if (s->draw_start < 0)
		s->draw_start = 0;
	s->draw_end = s->line_height / 2 + HEIGHT / 2;
	if (s->draw_end >= HEIGHT)
		s->draw_end = HEIGHT - 1;
}

void	draw_ver_line(t_cub3d *s, t_img *dst, t_img src)
{
	int		h;

	h = s->draw_start;
	while (h < s->draw_end)
	{
		dst->img_str[(s->col_x_iterator * 4) + (WIDTH * 4 * h) + 0] = \
		src.img_str[(0 * 4) + (TEXTURE_SIZE * 4 * 0) + 0];
		dst->img_str[(s->col_x_iterator * 4) + (WIDTH * 4 * h) + 1] = \
		src.img_str[(0 * 4) + (TEXTURE_SIZE * 4 * 0) + 1];
		dst->img_str[(s->col_x_iterator * 4) + (WIDTH * 4 * h) + 2] = \
		src.img_str[(0 * 4) + (TEXTURE_SIZE * 4 * 0) + 2];
		h++;
	}
	(void)src;
}

void	draw(t_cub3d *s, t_img *img)
{
	t_img	src;

	// s->side = 0 (W, E)
	// s->side = 1 (N, S)
	if (s->side == 0)
		src.img_str = mlx_get_data_addr(s->west, \
			&src.bits, &src.line, &src.endian);
	else// if (s->side == 1)
		src.img_str = mlx_get_data_addr(s->north, \
			&src.bits, &src.line, &src.endian);
	draw_ver_line(s, img, src);
}
