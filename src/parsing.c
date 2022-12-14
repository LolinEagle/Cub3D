/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrusso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:02:57 by frrusso           #+#    #+#             */
/*   Updated: 2022/12/12 16:02:59 by frrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

bool	iscub(char *av)
{
	int		i;
	int		j;
	char	*cub;

	i = ft_strlen(av);
	if (i < 4)
		return (false);
	cub = ".cub";
	i -= 4;
	j = 0;
	while (cub[j] && av[i + j] == cub[j])
		j++;
	if (cub[j] == '\0')
		return (true);
	return (false);
}

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	parsing(int ac, char **av, char **env)
{
	int		fd;

	if (env == NULL)
		exit(putstr_err("Environment not found.\n"));
	if (ac != 2)
		exit(putstr_out("Usage: ./cub3D <mapfile.cub>\n"));
	if (iscub(av[1]) == false)
		exit(putstr_out("Not a valid .cub file.\n"));
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		exit(putstr_out("Error\nYour map doesn't exist\n"));
}

void	init(t_cub3d *cub3d, char *av)
{
	cub3d->weight = WEIGHT;
	cub3d->height = HEIGHT;
	cub3d->north = NULL;
	cub3d->south = NULL;
	cub3d->west = NULL;
	cub3d->east = NULL;
	cub3d->ceiling = NULL;
	cub3d->floor = NULL;
	cub3d->mlx = mlx_init();
	if (cub3d->mlx == NULL)
		free_exit(cub3d);
	cub3d->win = mlx_new_window(cub3d->mlx, cub3d->weight, cub3d->height, NAME);
	if (cub3d->win == NULL)
		free_exit(cub3d);
	(void)av;
}
