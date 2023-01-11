/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:51:37 by frrusso           #+#    #+#             */
/*   Updated: 2023/01/11 17:49:10 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* ************************************************************************** */
/*   key                                                                      */
/* ************************************************************************** */
# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define UP 65362
# define LEFT 65361
# define DOWN 65364
# define RIGHT 65363

/* ************************************************************************** */
/*   window                                                                   */
/* ************************************************************************** */
# define NAME "Cub3D"
# define WIDTH 1600
# define HEIGHT 900
# define W_HALF 800
# define H_HALF 450

/* ************************************************************************** */
/*   include                                                                  */
/* ************************************************************************** */
# include <libft.h>
# include <mlx.h>
# include <stdbool.h>	// bool, true, false
# include <fcntl.h>		// open
# include <unistd.h>	// close, read, write
# include <stdio.h>		// printf, perror
# include <stdlib.h>	// malloc, free, exit
# include <string.h>	// strerror
# include <math.h>

/* ************************************************************************** */
/*   typedef                                                                  */
/* ************************************************************************** */
typedef unsigned char	t_rgb;

/* ************************************************************************** */
/*   struct                                                                   */
/* ************************************************************************** */
typedef struct s_cub3d
{
	void	*mlx;
	void	*win;
	void	*north;
	void	*south;
	void	*west;
	void	*east;
	void	*ceiling;
	void	*floor;
	size_t	width;
	size_t	height;
	size_t	map_width;	//plus grande longueur de le map (nombre de char)
	size_t	map_height; // y (nombre de lignes que gnl va trouver)
	char	**map;		// array 2d
	double	x;			// pos_player
	double	y;			// pos_player
	
}			t_cub3d;

typedef struct s_wall_renderer
{
	double	cube_size;
	double	player_size;
	double	wall_size;
	double	fov;		// field_of_view
	double	v_player_pos;
	double	v_dir_x;	// vecteur de direction depuis le joueur
	double	v_dir_y;
	double	v_camera_plane_x; // doit etre perpendiculaire à dir (??)
	double	v_camera_plane_y; //doit etre perpendiculaire à dir (??)
	double	distance;
}			t_wall_renderer;

typedef unsigned char	t_rgb;

typedef struct s_img
{
	void	*img;
	char	*img_str;
	int		bits;
	int		size_line;
	int		endian;
	t_rgb	r;
	t_rgb	g;
	t_rgb	b;
}			t_img;

typedef struct s_init
{
	size_t	x;
	size_t	spawn;
	bool	wrong;
}			t_init;

/* ************************************************************************** */
/*   map/map_algo.c                                             2 functions   */
/* ************************************************************************** */
void	map_spawn(t_cub3d *cub3d);
void	map_algo(t_cub3d *cub3d);

/* ************************************************************************** */
/*   parsing/initialization_utils.c                             4 functions   */
/* ************************************************************************** */
void	*cardinal_images(t_cub3d *cub3d, char *str, void *cardinal);
t_rgb	floor_and_ceiling_color(char **str);
void	put_pixel_image(int x, int y, t_img s);
void	*floor_and_ceiling(t_cub3d *cub3d, char *str, void *ptr);

/* ************************************************************************** */
/*   parsing/initialization.c                                   5 functions   */
/* ************************************************************************** */
char	*initialization_file(t_cub3d *cub3d, int fd, char *str);
void	initialization_map_size_check(t_cub3d *cub3d, t_init *init);
void	initialization_map_size(t_cub3d *cub3d, int fd, char *str);
void	initialization_map(t_cub3d *cub3d, int fd, char *str);
void	initialization(t_cub3d *cub3d, char *av);

/* ************************************************************************** */
/*   wall_renderer/init_renderer.c                              1 function   */
/* ************************************************************************* */
void	init_var_renderer(t_wall_renderer *wall_renderer);

/* ************************************************************************** */
/*   parsing/parsing.c                                          3 functions   */
/* ************************************************************************** */
bool	iscub(char *av);
void	parsing(int ac, char **av, char **env);
void	initialization_var(t_cub3d *cub3d);

/* ************************************************************************** */
/*   useful/debug.c                                             1 functions   */
/* ************************************************************************** */
void	print_cub3d(t_cub3d *cub3d);

/* ************************************************************************** */
/*   useful/free.c                                              3 functions   */
/* ************************************************************************** */
int		free_return(t_cub3d *cub3d);
void	free_exit(t_cub3d *cub3d, char *err);
void	free_close(t_cub3d *cub3d, char *err, int fd);

/* ************************************************************************** */
/*   useful/useful.c                                            5 functions   */
/* ************************************************************************** */
int		putstr_out(char *str);
int		putstr_err(char *str);
size_t	strlen_endl(const char *s);
bool	char_in_string(char c, char *str);
size_t	string_in_map(char *str1, char *str2, bool strict);

/* ************************************************************************** */
/*   cub3d.c                                                    4 functions   */
/* ************************************************************************** */
int		deal_close(void *mlx);
int		deal_key(int key, t_cub3d *cub3d);
int		deal_loop(t_cub3d *cub3d);
void	cub3d_loop(t_cub3d *cub3d);

/* ************************************************************************** */
/*   main.c                                                     1 functions   */
/* ************************************************************************** */

#endif
