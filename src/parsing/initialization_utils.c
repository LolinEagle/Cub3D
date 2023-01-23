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

void	initialization_start(t_cub3d *cub3d)
{
	cub3d->mlx = mlx_init();
	if (cub3d->mlx == NULL)
		free_exit(cub3d, "mlx_init\n");
	cub3d->win = mlx_new_window(cub3d->mlx, WIDTH, HEIGHT, NAME);
	if (cub3d->win == NULL)
		free_exit(cub3d, "mlx_new_window\n");
	cub3d->win_buffer = mlx_new_image(cub3d->mlx, WIDTH, HEIGHT);
	if (cub3d->win_buffer == NULL)
		free_exit(cub3d, "mlx_new_image\n");
}

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
	wh[0] = TEXTURE_SIZE;
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

int	floor_and_ceiling_color(char **str)
{
	int		i;
	int		j;
	char	nptr[4];

	while (*str[0] == ' ')
		str[0]++;
	while (*str[0] == '0' && ft_isdigit(*str[1]))
		str[0]++;
	i = 0;
	while (ft_isdigit(str[0][i]))
		i++;
	if (i == 0 || i > 3)
		return (-1);
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
	return (-1);
}

int	floor_and_ceiling_start(char **str, t_img *s)
{
	int		rgb[3];

	str[0]++;
	rgb[0] = floor_and_ceiling_color(str);
	rgb[1] = floor_and_ceiling_color(str);
	rgb[2] = floor_and_ceiling_color(str);
	if (rgb[0] == -1 || rgb[1] == -1 || rgb[2] == -1)
	{
		putstr_out("Can't use colors.\n");
		return (1);
	}
	s->r = rgb[0];
	s->g = rgb[1];
	s->b = rgb[2];
	return (0);
}

void	*floor_and_ceiling(t_cub3d *cub3d, char *str, void *ptr)
{
	int		x;
	int		y;
	int		wh[2];
	t_img	s;

	if (floor_and_ceiling_start(&str, &s))
		return (NULL);
	if (ptr != NULL)
		mlx_destroy_image(cub3d->mlx, ptr);
	wh[0] = WIDTH;
	wh[1] = H_HALF;
	s.img = mlx_new_image(cub3d->mlx, wh[0], wh[1]);
	if (s.img == NULL)
		return (NULL);
	s.img_str = mlx_get_data_addr(s.img, &s.bits, &s.line, &s.endian);
	y = -1;
	while (++y < wh[1])
	{
		x = -1;
		while (++x < wh[0])
			put_pixel_image(x, y, s);
	}
	return (s.img);
}
