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

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	*cardinal_images(t_cub3d *cub3d, char *str, void *cardinal)
{
	int		i;
	int		wh[1];
	void	*ret;

	str += 2;
	while (*str == ' ')
		str++;
	i = 0;
	while (str[i] && str[i] != ' ')
		i++;
	if (str[i])
		return (NULL);
	str[i - 1] = '\0';
	if (cardinal != NULL)
		mlx_destroy_image(cub3d->mlx, cardinal);
	wh[0] = 128;
	ret = mlx_xpm_file_to_image(cub3d->mlx, str, wh, wh);
	if (ret == NULL)
	{
		putstr_out("Can't open \"");
		putstr_out(str);
		putstr_out("\"\n");
		return (NULL);
	}
	return (ret);
}

int	floor_and_ceiling_color(char *str)
{
	int		i;
	int		j;
	char	nptr[4];

	i = 0;
	while (ft_isdigit(str[i]) && i <= 3)
		i++;
	if (i > 3)
		return (0);
	ft_bzero(nptr, 4);
	j = 0;
	while (j < i)
	{
		nptr[j] = *str + j;
		j++;
	}
	return (0);
}

void	*floor_and_ceiling(t_cub3d *cub3d, char *str, void *ptr)
{
	int		rgb[3];
	void	*ret;

	str++;
	while (*str == ' ')
		str++;
	rgb[0] = floor_and_ceiling_color(str);
	rgb[1] = floor_and_ceiling_color(str);
	rgb[2] = floor_and_ceiling_color(str);
	if (ptr != NULL)
		mlx_destroy_image(cub3d->mlx, ptr);
	ret = NULL;
	return (ret);
}
