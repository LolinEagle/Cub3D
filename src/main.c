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

int	main(int ac, char **av, char **env)
{
	t_cub3d	cub3d;

	parsing(ac, av, env);
	cub3d.mlx = mlx_init();
	if (cub3d.mlx == NULL)
		return (putstr_err("Error: mlx_init\n"));
	cub3d.win = mlx_new_window(cub3d.mlx, 1600, 900, "Cub3D");
	if (cub3d.win == NULL)
	{
		mlx_destroy_display(cub3d.mlx);
		free(cub3d.mlx);
		return (putstr_err("Error: mlx_new_window\n"));
	}
	ft_cub3d(&cub3d);
	return (0);
}
