/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:02:57 by frrusso           #+#    #+#             */
/*   Updated: 2023/01/19 11:08:31 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

bool	iscub(char *av)
{
	int		i;
	int		j;
	char	*cub;

	if (ft_strlen(av) < 4)
		return (false);
	cub = ".cub";
	i = -1;
	while (av[++i])
	{
		j = 0;
		while (cub[j] && av[i + j] == cub[j])
			j++;
		if (cub[j] == '\0' && av[i + j] == '\0')
			return (true);
		if (cub[j] == '\0')
			break ;
	}
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
	cub3d->win_buffer = NULL;
	cub3d->north = NULL;
	cub3d->south = NULL;
	cub3d->west = NULL;
	cub3d->east = NULL;
	cub3d->ceiling = NULL;
	cub3d->floor = NULL;
	cub3d->empty = NULL;
	cub3d->walls = NULL;
	cub3d->player = NULL;
	cub3d->map_width = 0;
	cub3d->map_height = 0;
	cub3d->map = NULL;
	cub3d->x = 0;
	cub3d->y = 0;
}
