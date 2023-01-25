/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 22:28:22 by sam               #+#    #+#             */
/*   Updated: 2023/01/25 22:57:26 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	key_press(int key, t_cub3d *s)
{
	if (key == W || key == UP)
		s->key_up = 1;
	if (key == A)
		s->key_left = 1;
	if (key == S || key == DOWN)
		s->key_down = 1;
	if (key == D)
		s->key_right = 1;
	return (0);
}

int	key_release(int key, t_cub3d *s)
{
	if (key == W || key == UP)
		s->key_up = 0;
	if (key == A)
		s->key_left = 0;
	if (key == S || key == DOWN)
		s->key_down = 0;
	if (key == D)
		s->key_right = 0;
	return (0);
}
