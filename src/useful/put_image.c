/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrusso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:39:26 by frrusso           #+#    #+#             */
/*   Updated: 2023/01/16 12:39:34 by frrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	put_pixel_image(int x, int y, t_img src)
{
	src.img_str[(x * 4) + (WIDTH * 4 * y) + 0] = src.b;
	src.img_str[(x * 4) + (WIDTH * 4 * y) + 1] = src.g;
	src.img_str[(x * 4) + (WIDTH * 4 * y) + 2] = src.r;
	src.img_str[(x * 4) + (WIDTH * 4 * y) + 3] = 0;
}

void	put_image_to_image(t_cub3d *cub3d, void *img, int x, int y)
{
	int		ix;
	int		iy;
	t_img	dst;
	t_img	src;

	dst.img = cub3d->win_buffer;
	dst.img_str = mlx_get_data_addr(dst.img, &dst.bits, &dst.line, &dst.endian);
	src.img = img;
	src.img_str = mlx_get_data_addr(src.img, &src.bits, &src.line, &src.endian);
	iy = 0 + y;
	while (src.img_str[src.line * (iy - y) + 4])
	{
		ix = 0 + x;
		while (ix < (src.line / 4) + x)
		{
			dst.b = src.img_str[((ix - x) * 4) + (src.line * (iy - y)) + 0];
			dst.g = src.img_str[((ix - x) * 4) + (src.line * (iy - y)) + 1];
			dst.r = src.img_str[((ix - x) * 4) + (src.line * (iy - y)) + 2];
			put_pixel_image(ix, iy, dst);
			ix++;
		}
		iy++;
	}
}
