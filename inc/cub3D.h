/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:51:37 by frrusso           #+#    #+#             */
/*   Updated: 2023/01/23 16:21:46 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* ************************************************************************** */
/*   key                                                                      */
/* ************************************************************************** */
# define ESC 65307
# define Z 122
# define Q 113
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
# define TEXTURE_SIZE 64
# define MINIMAP_SIZE 16
# define MINIMAP_EMPTY "./img/sEmpty.xpm"
# define MINIMAP_WALLS "./img/sWalls.xpm"
# define MINIMAP_PLAYER "./img/sPlayer.xpm"
# define MINIMAP_W_LEN 18
# define MINIMAP_W_LEN_HALF 9
# define MINIMAP_H_LEN 14
# define MINIMAP_H_LEN_HALF 7

/* ************************************************************************** */
/*   position                                                                 */
/* ************************************************************************** */
# define NORTH 78
# define SOUTH 83
# define EAST 69
# define WEST 87

/* ************************************************************************** */
/*   wall renderer                                                            */
/* ************************************************************************** */
# define PLAYER_SIZE 32
# define WALL_SIZE 64
# define FOV_PLANE_WIDTH 0.66
# define MOVE_SPEED 0.1
# define ROT_SPEED 0.05

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
	void	*win_buffer;
	void	*north;
	void	*south;
	void	*west;
	void	*east;
	void	*ceiling;
	void	*floor;
	void	*empty;
	void	*walls;
	void	*player;
	size_t	map_width;
	size_t	map_height;
	char	**map;
	int		mouse_x;
	int		mouse_y;
	double	x;
	double	y;
	double	v_dir_x;
	double	v_dir_y;
	double	old_x;
	double	old_y;
	double	old_dir_x;
	double	old_dir_y;
	double	old_plane_x;
	double	old_plane_y;
	double	v_camera_plane_x;
	double	v_camera_plane_y;
	double	ratio_camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		tile_x;
	int		tile_y;
	int		step_x;
	int		step_y;
	double	first_dist_x;
	double	first_dist_y;
	double	delta_x;
	double	delta_y;
	double	perp_wall_dist;
	int		flag_hit_wall;
	int		side;
	double	distance;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		col_x_iterator;
	t_rgb	color;
}			t_cub3d;

typedef struct s_img
{
	void	*img;
	char	*img_str;
	int		bits;
	int		line;
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
/*   map/minimap.c                                              3 functions   */
/* ************************************************************************** */
void	*minimap_image(t_cub3d *cub3d, char *str);
void	minimap_parsing(t_cub3d *cub3d, size_t x, size_t y, int yy);
void	minimap(t_cub3d *cub3d);

/* ************************************************************************** */
/*   parsing/initialization_utils.c                             5 functions   */
/* ************************************************************************** */
void	initialization_start(t_cub3d *cub3d);
void	*cardinal_images(t_cub3d *cub3d, char *str, void *cardinal);
int		floor_and_ceiling_color(char **str);
int		floor_and_ceiling_start(char **str, t_img *s);
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
/*   parsing/parsing.c                                          3 functions   */
/* ************************************************************************** */
bool	iscub(char *av);
void	parsing(int ac, char **av, char **env);
void	initialization_var(t_cub3d *cub3d);

/* ************************************************************************** */
/*   useful/debug.c                                             3 functions   */
/* ************************************************************************** */
void	print_cub3d(t_cub3d *cub3d);
void	print_t_img(t_img *img);
void	print_raycasting_data(t_cub3d *s);

/* ************************************************************************** */
/*   useful/free.c                                              4 functions   */
/* ************************************************************************** */
void	free_image(t_cub3d *cub3d);
int		free_return(t_cub3d *cub3d);
void	free_exit(t_cub3d *cub3d, char *err);
void	free_close(t_cub3d *cub3d, char *err, int fd);

/* ************************************************************************** */
/*   useful/put_image.c                                         3 functions   */
/* ************************************************************************** */
void	put_pixel_image(int x, int y, t_img s);
int		put_image_pixel(t_cub3d *cub3d, void *img, t_img *dst, t_img *src);
void	put_image_to_image(t_cub3d *cub3d, void *img, int x, int y);

/* ************************************************************************** */
/*   useful/useful.c                                            5 functions   */
/* ************************************************************************** */
int		putstr_out(char *str);
int		putstr_err(char *str);
size_t	strlen_endl(const char *s);
bool	char_in_string(char c, char *str);
size_t	string_in_map(char *str1, char *str2, bool strict);

/* ************************************************************************** */
/*   wall_renderer/init_renderer.c                              5 functions   */
/* ****************************************************************************/
void	init_var_renderer(t_cub3d *s);
void	init_dda_var(t_cub3d *s);
void	get_start_orientation(t_cub3d *s);
void	init_orientation_from_player(t_cub3d *s, int orientation);
void	save_init_state(t_cub3d *s);

/* ************************************************************************** */
/*   wall_renderer/raycasting.c                                 4 functions   */
/* ****************************************************************************/
void	cast_ray(t_cub3d *s);
void	dda(t_cub3d *s);
void	calculate_data(t_cub3d *s);
void	calculate_dist_on_camera(t_cub3d *s);

/* ************************************************************************** */
/*   wall_renderer/draw.c                                       3 functions   */
/* ****************************************************************************/
void	init_draw(t_cub3d *s);
void	draw(t_cub3d *s, t_img *img);

/* ************************************************************************** */
/*   wall_renderer/move.c                                       4 functions   */
/* ****************************************************************************/
void	move_front(t_cub3d *s);
void	move_back(t_cub3d *s);
void	move_right(t_cub3d *s);
void	move_left(t_cub3d *s);

/* ************************************************************************** */
/*   wall_renderer/rotation.c                                   2 functions   */
/* ****************************************************************************/
void	rotation_right(t_cub3d *s);
void	rotation_left(t_cub3d *s);

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
