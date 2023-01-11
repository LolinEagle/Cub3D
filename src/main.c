/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:38:01 by frrusso           #+#    #+#             */
/*   Updated: 2023/01/11 17:48:52 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	main(int ac, char **av, char **env)
{
	t_cub3d	cub3d;
	t_wall_renderer s_wall_renderer;

	parsing(ac, av, env);
	initialization_var(&cub3d);
	initialization(&cub3d, av[1]);
	init_var_renderer(&s_wall_renderer);
	cub3d_loop(&cub3d);
	return (free_return(&cub3d));
}
