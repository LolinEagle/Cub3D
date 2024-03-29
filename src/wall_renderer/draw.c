/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:03:17 by sle-huec          #+#    #+#             */
/*   Updated: 2023/01/24 17:03:24 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	init_draw(t_cub3d *s)
{
	if (s->perp_wall_dist == 0)
		s->line_height = HEIGHT - 2;
	else
		s->line_height = (int)(HEIGHT / s->perp_wall_dist);
	s->draw_start_all = -s->line_height / 2 + HEIGHT / 2;
	s->draw_start = s->draw_start_all;
	if (s->draw_start < 0)
		s->draw_start = 0;
	s->draw_end_all = s->line_height / 2 + HEIGHT / 2;
	s->draw_end = s->draw_end_all;
	if (s->draw_end >= HEIGHT)
		s->draw_end = HEIGHT - 1;
}

void	draw_ver_line(t_cub3d *s, t_img *dst, t_img src, double wall)
{
	int		h;
	double	wall_size;

	wall_size = (s->draw_end_all - s->draw_start_all) * (1.0 / 63.0);
	h = s->draw_start;
	while (h < s->draw_end)
	{
		dst->img_str[(s->col_x_iterator * 4) + (WIDTH * 4 * h) + 0] = \
		src.img_str[((int)round(wall * 63) * 4) + (TEXTURE_SIZE * 4 * \
		(int)round((h - s->draw_start_all) / wall_size)) + 0];
		dst->img_str[(s->col_x_iterator * 4) + (WIDTH * 4 * h) + 1] = \
		src.img_str[((int)round(wall * 63) * 4) + (TEXTURE_SIZE * 4 * \
		(int)round((h - s->draw_start_all) / wall_size)) + 1];
		dst->img_str[(s->col_x_iterator * 4) + (WIDTH * 4 * h) + 2] = \
		src.img_str[((int)round(wall * 63) * 4) + (TEXTURE_SIZE * 4 * \
		(int)round((h - s->draw_start_all) / wall_size)) + 2];
		h++;
	}
}

void	draw(t_cub3d *s, t_img *img)
{
	t_img	src;
	double	wall_hit_point;

	if (s->side == 1 && s->ray_dir_y < 0)
		src.img_str = mlx_get_data_addr(s->north, \
			&src.bits, &src.line, &src.endian);
	else if (s->side == 1 && s->ray_dir_y > 0)
		src.img_str = mlx_get_data_addr(s->south, \
			&src.bits, &src.line, &src.endian);
	else if (s->side == 0 && s->ray_dir_x < 0)
		src.img_str = mlx_get_data_addr(s->west, \
			&src.bits, &src.line, &src.endian);
	else
		src.img_str = mlx_get_data_addr(s->east, \
			&src.bits, &src.line, &src.endian);
	if (s->side == 0)
		wall_hit_point = s->y + s->perp_wall_dist * s->ray_dir_y;
	else
		wall_hit_point = s->x + s->perp_wall_dist * s->ray_dir_x;
	wall_hit_point -= floor((wall_hit_point));
	draw_ver_line(s, img, src, wall_hit_point);
}
