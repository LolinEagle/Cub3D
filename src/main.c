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
	initialization_var(&cub3d);
	initialization(&cub3d, av[1]);
	ft_cub3d(&cub3d);
	return (free_return(&cub3d));
}
