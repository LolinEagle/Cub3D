/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:05:55 by sle-huec          #+#    #+#             */
/*   Updated: 2023/01/23 14:39:43 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	move_front(t_cub3d *s)
{
	int	pos_x;
	int	pos_y;

	pos_x = (int)(s->x + s->v_dir_x * MOVE_SPEED);
	pos_y = (int)(s->y + s->v_dir_y * MOVE_SPEED);
	if (s->map[(int)s->y][pos_x] != '1')
		s->x += s->v_dir_x * MOVE_SPEED;
	if (s->map[pos_y][(int)s->x] != '1')
		s->y += s->v_dir_y * MOVE_SPEED;
}

void	move_back(t_cub3d *s)
{
	int	pos_x;
	int	pos_y;

	pos_x = (int)(s->x - s->v_dir_x * MOVE_SPEED);
	pos_y = (int)(s->y - s->v_dir_y * MOVE_SPEED);
	if (s->map[(int)s->y][pos_x] != '1')
		s->x -= s->v_dir_x * MOVE_SPEED;
	if (s->map[pos_y][(int)s->x] != '1')
		s->y -= s->v_dir_y * MOVE_SPEED;
}

void	move_right(t_cub3d *s)
{
	int	pos_x;
	int	pos_y;

	pos_x = (int)(s->x - s->v_dir_y * MOVE_SPEED);
	pos_y = (int)(s->y + s->v_dir_x * MOVE_SPEED);
	if (s->map[(int)s->y][pos_x] != '1')
		s->x -= s->v_dir_y * MOVE_SPEED;
	if (s->map[pos_y][(int)s->x] != '1')
		s->y += s->v_dir_x * MOVE_SPEED;
}

void	move_left(t_cub3d *s)
{
	int	pos_x;
	int	pos_y;

	pos_x = (int)(s->x + s->v_dir_y * MOVE_SPEED);
	pos_y = (int)(s->y - s->v_dir_x * MOVE_SPEED);
	if (s->map[(int)s->y][pos_x] != '1')
		s->x += s->v_dir_y * MOVE_SPEED;
	if (s->map[pos_y][(int)s->x] != '1')
		s->y -= s->v_dir_x * MOVE_SPEED;
}
