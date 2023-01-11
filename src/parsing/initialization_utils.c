/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrusso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:24:02 by frrusso           #+#    #+#             */
/*   Updated: 2022/12/16 18:24:03 by frrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	*cardinal_images(t_cub3d *cub3d, char *str, void *cardinal)
{
	int		wh[1];
	void	*ret;

	str += 2;
	while (*str == ' ')
		str++;
	if (str[ft_strlen(str) - 1] == '\n')
		str[ft_strlen(str) - 1] = '\0';
	if (cardinal != NULL)
		mlx_destroy_image(cub3d->mlx, cardinal);
	wh[0] = 128;
	ret = mlx_xpm_file_to_image(cub3d->mlx, str, &wh[0], &wh[0]);
	if (ret == NULL)
	{
		putstr_out("Can't open \"");
		putstr_out(str);
		putstr_out("\"\n");
		return (NULL);
	}
	return (ret);
}

t_rgb	floor_and_ceiling_color(char **str)
{
	int		i;
	int		j;
	char	nptr[4];

	while (*str[0] == ' ')
		str[0]++;
	while (*str[0] == '0' && ft_isdigit(*str[0] + 1))
		str[0]++;
	i = 0;
	while (ft_isdigit(str[0][i]))
		i++;
	if (i > 3)
		return (0);
	ft_bzero(nptr, 4);
	j = -1;
	while (++j < i)
		nptr[j] = str[0][j];
	str[0] += j;
	if (*str[0] == ',')
		str[0]++;
	i = ft_atoi(nptr);
	if (i <= 255)
		return (i);
	return (0);
}

void	put_pixel_image(int x, int y, t_img s)
{
	s.img_str[(x * 4) + (WIDTH * 4 * y) + 0] = s.b;
	s.img_str[(x * 4) + (WIDTH * 4 * y) + 1] = s.g;
	s.img_str[(x * 4) + (WIDTH * 4 * y) + 2] = s.r;
	s.img_str[(x * 4) + (WIDTH * 4 * y) + 3] = 0;
}

void	*floor_and_ceiling(t_cub3d *cub3d, char *str, void *ptr)
{
	int		x;
	int		y;
	int		wh[2];
	t_img	s;

	if (ptr != NULL)
		mlx_destroy_image(cub3d->mlx, ptr);
	wh[0] = WIDTH;
	wh[1] = H_HALF;
	s.img = mlx_new_image(cub3d->mlx, wh[0], wh[1]);
	if (s.img == NULL)
		return (NULL);
	s.img_str = mlx_get_data_addr(s.img, &s.bits, &s.size_line, &s.endian);
	str++;
	s.r = floor_and_ceiling_color(&str);
	s.g = floor_and_ceiling_color(&str);
	s.b = floor_and_ceiling_color(&str);
	y = -1;
	while (++y < wh[1])
	{
		x = -1;
		while (++x < wh[0])
			put_pixel_image(x, y, s);
	}
	return (s.img);
}
