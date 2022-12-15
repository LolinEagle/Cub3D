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

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define UP 65362
# define LEFT 65361
# define DOWN 65364
# define RIGHT 65363
# define NAME "Cub3D"
# define WEIGHT 1600
# define HEIGHT  900

# include <libft.h>
# include <mlx.h>
# include <stdbool.h>	// bool, true, false
# include <fcntl.h>		// open
# include <unistd.h>	// close, read, write
# include <stdio.h>		// printf, perror
# include <stdlib.h>	// malloc, free, exit
# include <string.h>	// strerror
# include <math.h>

typedef struct s_cub3d
{
	void	*mlx;
	void	*win;
	int		weight;
	int		height;
	void	*north;
	void	*south;
	void	*west;
	void	*east;
	void	*ceiling;
	void	*floor;
	char	**map;
}	t_cub3d;

/* ************************************************************************** */
/*   cub3d.c                                                    4 functions   */
/* ************************************************************************** */
int		deal_close(void *mlx);
int		deal_key(int key, t_cub3d *cub3d);
int		deal_loop(t_cub3d *cub3d);
void	ft_cub3d(t_cub3d *cub3d);

/* ************************************************************************** */
/*   free.c                                                     2 functions   */
/* ************************************************************************** */
int		free_return(t_cub3d *cub3d);
void	free_exit(t_cub3d *cub3d, char *err);

/* ************************************************************************** */
/*   initialization.c                                           3 functions   */
/* ************************************************************************** */
int		create_rgb(int r, int g, int b);
char	*initialization_file(t_cub3d *cub3d, int fd, char *str);
void	initialization(t_cub3d *cub3d, char *av);

/* ************************************************************************** */
/*   parsing.c                                                  3 functions   */
/* ************************************************************************** */
bool	iscub(char *av);
void	parsing(int ac, char **av, char **env);
void	initialization_var(t_cub3d *cub3d);

/* ************************************************************************** */
/*   utils.c                                                    3 functions   */
/* ************************************************************************** */
int		putstr_out(char *str);
int		putstr_err(char *str);
bool	char_in_string(char c, char *str);

/* ************************************************************************** */
/*   main.c                                                     1 functions   */
/* ************************************************************************** */

#endif
