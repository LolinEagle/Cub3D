/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrusso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:51:37 by frrusso           #+#    #+#             */
/*   Updated: 2022/12/08 15:51:48 by frrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define FALSE 0
# define TRUE 1
# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define UP 65362
# define LEFT 65361
# define DOWN 65364
# define RIGHT 65363

# include "../_libft/libft.h"
# include "../_minilibx-linux/mlx.h"
// # include <libft.h>
// # include <mlx.h>
# include <fcntl.h>	// open
# include <unistd.h>// close, read, write
# include <stdio.h>	// printf, perror
# include <stdlib.h>// malloc, free, exit
# include <string.h>// strerror
# include <math.h>

typedef struct s_cub3d
{
	void	*mlx;
	void	*win;
}	t_cub3d;

/* ************************************************************************** */
/*   main.c                                                     0 functions   */
/* ************************************************************************** */

#endif
