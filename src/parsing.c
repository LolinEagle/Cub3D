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
		exit(putstr_err("Error: Environment not found\n"));
	if (ac != 2)
		exit(putstr_out("Usage: ./cub3D <mapfile.cub>\n"));
	if (iscub(av[1]) == false)
		exit(putstr_out("Error: Not a valid .cub file.\n"));
}
