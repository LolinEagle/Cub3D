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

char	*initialization_file(t_cub3d *cub3d, int fd, char *str)
{
	while (true)
	{
		free(str);
		str = get_next_line(fd);
		if (str == NULL)
			free_close(cub3d, "Empty or no map.\n", fd);
		if (str[0] == '\n')
			continue ;
		else if (ft_strncmp(str, "NO", 2) == 0)
			cub3d->north = cardinal_images(cub3d, str, cub3d->north);
		else if (ft_strncmp(str, "SO", 2) == 0)
			cub3d->south = cardinal_images(cub3d, str, cub3d->south);
		else if (ft_strncmp(str, "WE", 2) == 0)
			cub3d->west = cardinal_images(cub3d, str, cub3d->west);
		else if (ft_strncmp(str, "EA", 2) == 0)
			cub3d->east = cardinal_images(cub3d, str, cub3d->east);
		else if (ft_strncmp(str, "F", 1) == 0)
			cub3d->floor = floor_and_ceiling(cub3d, str, cub3d->floor);
		else if (ft_strncmp(str, "C", 1) == 0)
			cub3d->ceiling = floor_and_ceiling(cub3d, str, cub3d->ceiling);
		else
			break ;
	}
	return (str);
}

void	initialization_map_size_check(t_cub3d *cub3d, t_init *init)
{
	if (init->wrong)
		free_exit(cub3d, "Wrong character in the map.\n");
	if (init->spawn == 0)
		free_exit(cub3d, "No spawn point.\n");
	if (init->spawn > 1)
		free_exit(cub3d, "Too many spawn points.\n");
	cub3d->map = malloc(sizeof(char *) * (cub3d->map_height + 1));
	if (cub3d->map == NULL)
		free_exit(cub3d, "malloc fail\n");
}

void	initialization_map_size(t_cub3d *cub3d, int fd, char *str)
{
	t_init	init;

	init.spawn = 0;
	init.wrong = false;
	while (true)
	{
		if (init.wrong == false || init.spawn <= 1)
		{
			init.x = strlen_endl(str);
			if (cub3d->map_width < init.x)
				cub3d->map_width = init.x;
			cub3d->map_height++;
			init.spawn += string_in_map(str, "NSWE", 0);
			if (string_in_map(str, " 01NSWE\n", 1) == 0)
				init.wrong = true;
		}
		free(str);
		str = get_next_line(fd);
		if (str == NULL)
			break ;
	}
	close(fd);
	initialization_map_size_check(cub3d, &init);
}

void	initialization_map(t_cub3d *cub3d, int fd, char *str)
{
	int	i;

	while (true)
	{
		free(str);
		str = get_next_line(fd);
		if (str == NULL)
			free_close(cub3d, "get_next_line fail\n", fd);
		if (str[0] == '\n' || ft_strncmp(str, "NO", 2) == 0 || ft_strncmp(str, \
			"SO", 2) == 0 || ft_strncmp(str, "WE", 2) == 0 || ft_strncmp(str, \
			"EA", 2) == 0 || ft_strncmp(str, "F", 1) == 0 || ft_strncmp(str, \
			"C", 1) == 0)
			continue ;
		else
			break ;
	}
	cub3d->map[0] = str;
	i = 0;
	while (true)
	{
		cub3d->map[++i] = get_next_line(fd);
		if (cub3d->map[i] == NULL)
			break ;
	}
	close(fd);
}

void	initialization(t_cub3d *cub3d, char *av)
{
	int		fd;
	char	*str;

	initialization_start(cub3d);
	fd = open(av, O_RDONLY);
	if (fd == -1)
		free_exit(cub3d, "Can't open your map or your map doesn't exist.\n");
	str = initialization_file(cub3d, fd, NULL);
	initialization_map_size(cub3d, fd, str);
	fd = open(av, O_RDONLY);
	if (fd == -1)
		free_exit(cub3d, "open fail\n");
	initialization_map(cub3d, fd, NULL);
	if (cub3d->north == NULL || cub3d->south == NULL
		|| cub3d->west == NULL || cub3d->east == NULL
		|| cub3d->floor == NULL || cub3d->ceiling == NULL)
		free_exit(cub3d, "Your file is missing an argument.\n");
	map_algo(cub3d);
}
