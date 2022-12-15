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

void	parsing(int ac, char **av, char **env)
{
	if (env == NULL)
		exit(putstr_err("Environment not found.\n"));
	if (ac != 2)
		exit(putstr_out("Usage: ./cub3D <mapfile.cub>\n"));
	if (iscub(av[1]) == false)
		exit(putstr_out("Not a valid .cub file.\n"));
}

void	initialization_var(t_cub3d *cub3d)
{
	cub3d->mlx = NULL;
	cub3d->win = NULL;
	cub3d->weight = WEIGHT;
	cub3d->height = HEIGHT;
	cub3d->north = NULL;
	cub3d->south = NULL;
	cub3d->west = NULL;
	cub3d->east = NULL;
	cub3d->ceiling = NULL;
	cub3d->floor = NULL;
	cub3d->map = NULL;
}
