/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful.c                                           :+:      :+:    :+:   */
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

size_t	strlen_endl(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
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

size_t	string_in_map(char *str1, char *str2, bool strict)
{
	size_t	i;
	size_t	ret;

	ret = 0;
	i = 0;
	while (str1[i])
	{
		if (char_in_string(str1[i], str2))
			ret++;
		else if (strict)
			return (0);
		i++;
	}
	return (ret);
}
