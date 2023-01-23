/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:39:26 by frrusso           #+#    #+#             */
/*   Updated: 2023/01/23 17:15:43 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	put_pixel_image(int x, int y, t_img src)
{
	src.img_str[(x * 4) + (WIDTH * 4 * y)] = src.b;
	src.img_str[(x * 4) + (WIDTH * 4 * y) + 1] = src.g;
	src.img_str[(x * 4) + (WIDTH * 4 * y) + 2] = src.r;
	src.img_str[(x * 4) + (WIDTH * 4 * y) + 3] = 0;
}

int	put_image_pixel(t_cub3d *cub3d, void *img, t_img *dst, t_img *src)
{
	int	height;

	dst->img_str = mlx_get_data_addr(cub3d->win_buffer, \
		&dst->bits, &dst->line, &dst->endian);
	src->img_str = mlx_get_data_addr(img, &src->bits, &src->line, &src->endian);
	if (cub3d->ceiling == img || cub3d->floor == img)
		height = H_HALF;
	else
		height = (src->line / 4);
	return (height);
}

void	put_image_to_image(t_cub3d *cub3d, void *img, int x, int y)
{
	int		ix;
	int		iy;
	int		height;
	t_img	dst;
	t_img	src;

	height = put_image_pixel(cub3d, img, &dst, &src);
	iy = y;
	while ((iy - y) < height)
	{
		ix = x;
		while (ix < (src.line / 4) + x)
		{
			dst.img_str[(ix * 4) + (WIDTH * 4 * iy)] = \
			src.img_str[((ix - x) * 4) + (src.line * (iy - y))];
			dst.img_str[(ix * 4) + (WIDTH * 4 * iy) + 1] = \
			src.img_str[((ix - x) * 4) + (src.line * (iy - y)) + 1];
			dst.img_str[(ix * 4) + (WIDTH * 4 * iy) + 2] = \
			src.img_str[((ix - x) * 4) + (src.line * (iy - y)) + 2];
			ix++;
		}
		iy++;
	}
}
