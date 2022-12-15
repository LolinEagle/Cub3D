/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrusso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:26:59 by frrusso           #+#    #+#             */
/*   Updated: 2022/12/14 12:27:01 by frrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	putstr_out(char *str)
{
	if (str == NULL)
		return (0);
	write(1, str, ft_strlen(str));
	return (0);
}

int	putstr_err(char *str)
{
	if (str == NULL)
		return (1);
	write(2, "Error\n", 6);
	write(2, str, ft_strlen(str));
	return (1);
}

bool	char_in_string(char c, char *str)
{
	if (c == '\0' || str == NULL)
		return (false);
	while (*str)
	{
		if (c == *str)
			return (true);
		str++;
	}
	return (false);
}
