/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrusso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:38:01 by frrusso           #+#    #+#             */
/*   Updated: 2022/12/08 13:38:03 by frrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	free_exit(t_cub3d *cub3d)
{
	free(cub3d->mlx);
	free(cub3d->win);
	exit(1);
}

int	putstr_fd_return(char *str, int fd)
{
	if (!str)
		return (fd - 1);
	write(fd, str, ft_strlen(str));
	return (fd - 1);
}

int	iscub(char *av)
{
	int		i;
	int		j;
	char	*cub;

	if (ft_strlen(av) < 4)
		return (putstr_fd_return("Not a valid .cub file.\n", 1));
	cub = ".cub";
	i = 0;
	while (av[i])
	{
		if (av[i] == cub[0])
		{
			j = 0;
			while (cub[j] && av[i + j] == cub[j])
				j++;
			if (cub[j] == '\0' && av[i + j] == '\0')
				return (TRUE);
		}
		i++;
	}
	return (putstr_fd_return("Not a valid .cub file.\n", 1));
}

int	main(int ac, char **av, char **env)
{
	t_cub3d	cub3d;

	if (env == NULL)
		return (putstr_fd_return("Environment not found\n", 2));
	if (ac != 2 || iscub(av[1]))
		return (putstr_fd_return("Usage : ./cub3D <mapfile.cub>\n", 1));
	cub3d.mlx = mlx_init();
	if (cub3d.mlx == NULL)
		return (1);
	cub3d.win = mlx_new_window(cub3d.mlx, 1920, 1080, "Cub3D");
	if (cub3d.mlx == NULL)
		free_exit(&cub3d);
	return (0);
}
