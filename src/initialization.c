/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrusso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:06:19 by frrusso           #+#    #+#             */
/*   Updated: 2022/12/15 16:06:24 by frrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

char	*initialization_file(t_cub3d *cub3d, int fd, char *str)
{
	while (1)
	{
		free(str);
		str = get_next_line(fd);
		if (str == NULL)
			free_exit(cub3d, "Empty or no map\n");
		if (str[0] == '\n')
			continue ;
		else if (ft_strncmp(str, "NO", 2) == 0)
			printf("NO find\n");
		else if (ft_strncmp(str, "SO", 2) == 0)
			printf("SO find\n");
		else if (ft_strncmp(str, "WE", 2) == 0)
			printf("WE find\n");
		else if (ft_strncmp(str, "EA", 2) == 0)
			printf("EA find\n");
		else if (ft_strncmp(str, "F", 1) == 0)
			printf("F find\n");
		else if (ft_strncmp(str, "C", 1) == 0)
			printf("C find\n");
		else
			break ;
	}
	return (str);
}

void	initialization(t_cub3d *cub3d, char *av)
{
	int		fd;
	char	*str;

	cub3d->mlx = mlx_init();
	if (cub3d->mlx == NULL)
		free_exit(cub3d, "mlx_init\n");
	cub3d->win = mlx_new_window(cub3d->mlx, cub3d->weight, cub3d->height, NAME);
	if (cub3d->win == NULL)
		free_exit(cub3d, "mlx_new_window\n");
	fd = open(av, O_RDONLY);
	if (fd == -1)
		free_exit(cub3d, "Can't open your map or your map doesn't exist.\n");
	str = NULL;
	str = initialization_file(cub3d, fd, str);
	while (1)
	{
		ft_putstr_fd(str, 1);
		free(str);
		str = get_next_line(fd);
		if (str == NULL)
			break ;
	}
}
