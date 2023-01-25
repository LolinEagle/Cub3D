/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:38:01 by frrusso           #+#    #+#             */
/*   Updated: 2023/01/24 17:06:33 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	main(int ac, char **av, char **env)
{
	t_cub3d	cub3d;

	parsing(ac, av, env);
	initialization_var(&cub3d);
	initialization(&cub3d, av[1]);
	init_var_renderer(&cub3d);
	if (av[0][ft_strlen(av[0]) - 1] == 's')
		cub3d.bonus = true;
	else
		cub3d.bonus = false;
	cub3d_loop(&cub3d);
	return (free_return(&cub3d));
}
