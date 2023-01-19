/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:17:56 by frrusso           #+#    #+#             */
/*   Updated: 2023/01/19 17:28:46 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	print_cub3d(t_cub3d *cub3d)
{
	size_t	i;

	printf("---------------------------------------------------------------\n");
	printf("mlx=%p\t\twin=%p\n", cub3d->mlx, cub3d->win);
	printf("north=%p\t\tsouth=%p\n", cub3d->north, cub3d->south);
	printf("west=%p\t\teast=%p\n", cub3d->west, cub3d->east);
	printf("ceiling=%p\tfloor=%p\n", cub3d->ceiling, cub3d->floor);
	printf("x=%f\t\ty=%f\n", cub3d->x, cub3d->y);
	printf("map_width=%zu\t\t", cub3d->map_width);
	printf("map_height=%zu\n", cub3d->map_height);
	printf("map=%p\n", cub3d->map);
	i = -1;
	while (cub3d->map && cub3d->map[++i])
		printf("map[%zu]=%s", i, cub3d->map[i]);
	printf("---------------------------------------------------------------\n");
}

void	print_t_img(t_img *img)
{
	printf("---------------------------------------------------------------\n");
	printf("img=%p\n", img->img);
	printf("img_str=%p\n", img->img_str);
	printf("bits=%i\n", img->bits);
	printf("line=%i\n", img->line);
	printf("endian=%i\n", img->endian);
	printf("---------------------------------------------------------------\n");
}

void print_raycasting_data(t_cub3d *s)
{
	printf("---------------------------------------------------------------\n");
	printf("pos x=%f\n", s->x);
	printf("pos y=%f\n", s->y);
	printf("deltaX=%f\n", s->delta_x);
	printf("deltaY=%f\n", s->delta_y);
	printf("first dist y=%f\n", s->first_dist_y);
	printf("first dist x=%f\n", s->first_dist_x);
	printf("plan x=%f\n", s->v_camera_plane_x);
	printf("plan y=%f\n", s->v_camera_plane_y);
	printf("dir x=%f\n", s->v_dir_x);
	printf("dir y=%f\n", s->v_dir_y);
	printf("per pwall dist=%f\n", s->perp_wall_dist);
	printf("ratio camera=%f\n", s->ratio_camera_x);
	printf("step x=%i\n", s->step_x);
	printf("step y=%i\n", s->step_y);
	printf("tile x=%i\n", s->tile_x);
	printf("tile y=%i\n", s->tile_y);
	printf("flag hit wall=%i\n", s->flag_hit_wall);
	printf("column line iterator x=%d\n", s->col_x_iterator);
	printf("color code=0x%x\n", s->color);
	printf("drawstart=%i\n", s->draw_start);
	printf("drawend=%i\n", s->draw_end);
	printf("line height=%i\n", s->line_height);
	printf("side=%i\n", s->side);
	printf("---------------------------------------------------------------\n");
}