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

int	putstr_fd_return(char *str, int fd, int ret)
{
	if (str == NULL)
		return (ret);
	write(fd, str, ft_strlen(str));
	return (ret);
}

int	iscub(char *av)
{
	int		i;
	int		j;
	char	*cub;

	if (ft_strlen(av) < 4)
		return (FALSE);
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
	return (FALSE);
}

int	ft_close(void *mlx)
{
	mlx_loop_end(mlx);
	return (0);
}

void	free_exit(t_cub3d *cub3d)
{
	mlx_destroy_window(cub3d->mlx, cub3d->win);
	mlx_destroy_display(cub3d->mlx);
	free(cub3d->mlx);
	exit(1);
}

int	main(int ac, char **av, char **env)
{
	t_cub3d	cub3d;

	if (env == NULL)
		return (putstr_fd_return("Error: Environment not found\n", 2, 1));
	if (ac != 2)
		return (putstr_fd_return("Usage : ./cub3D <mapfile.cub>\n", 1, 0));
	if (iscub(av[1]) == FALSE)
		return (putstr_fd_return("Not a valid .cub file.\n", 1, 0));
	cub3d.mlx = mlx_init();
	if (cub3d.mlx == NULL)
		return (putstr_fd_return("Error: mlx_init\n", 2, 1));
	cub3d.win = mlx_new_window(cub3d.mlx, 1600, 900, "Cub3D");
	if (cub3d.mlx == NULL)
		return (putstr_fd_return("Error: mlx_new_window\n", 2, 1));
	mlx_hook(cub3d.win, 17, 0, ft_close, cub3d.mlx);
	mlx_loop(cub3d.mlx);
	free_exit(&cub3d);
	return (0);
}
