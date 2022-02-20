#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>

# define WIN_H 810
# define WIN_L 1440
# define HOOK_KEY_PRESSED 1L<<0
# define HOOK_KEY_RELEASED 1L<<1
# define PI 3.14159
# define P2 PI / 2
# define P3 3 * (PI / 2)
# define DR 0.0174533
# define TEX_H 64
# define TEX_W 64

typedef struct s_cub	t_cub;
struct			s_cub
{
	char	*north;
	char	*south;
	char	*east;
	char	*west;
	char	sp_dir;
	int		fd;
	int		floor[3];
	int		ceiling[3];
	char	*dot_cub;
	char 	**map;
	char	*line;
	char	*cub_file;
	int		spawnx;
	int		spawny;
	int		height;
	int		width;
};

typedef struct s_mlx	t_mlx;
struct			s_mlx
{
	void		*cub;
	void		*ray;
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bpp;
	int			len;
	int			endian;
	int			x;
	int			y;
	int			right;
	int			left;
	int			move_up;
	int			move_left;
	int			move_right;
	int			move_down;
	int			rot_left;
	int			rot_right;
	int			left_dir;
	int			right_dir;
};

typedef struct s_data t_data;
struct	s_data
{
	t_cub	*cub;
	char	**map;
	int		mapx;
	int		mapy;
	float	div;
	//textures
	int		tex[7][4096];
	char	*no;
	char	*we;
	char	*ea;
	char	*so;
	int		wall_index;
	int		pos_tex;
	float	chl;
	float	ch;
	int		j;
	float	dx;
	float	dy;
	float	di;
	float	li;
	float	ca;
	float	lineh;
	float	loff;
	//minilibx
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixels;
	int		line_length;
	int		endian;
	int		mh;
	int		ml;
	//resolution of map (still don't know if useful)
	int		resx;
	int		resy;
	//position of player
	int		w;
	int		a;
	int		s;
	int		d;
	int		gau;
	int		dro;
	float	posx;
	float	posy;
	float	pa;
	float	pdx;
	float	pdy;
	//raycasting
	float	r;
	int		mx;
	int		my;
	int		mp;
	int		dof;
	float	rx;
	float	ry;
	float	ra;
	float	rpdx;
	float	rpdy;
	int		wxo;
	int		wyo;
	int		iposx;
	int		iposy;
	int		iposx_add_wxo;
	int		iposy_add_wyo;
	int		iposx_sub_wxo;
	int		iposy_sub_wyo;
	float	xo;
	float	yo;
	float	atan;
	float	ntan;
	float	hx;
	float	hy;
	float	distt;
	float	disth;
	float	distv;
	float	colorw;
	float	colorc;
	float	colorf;
};

//parsing////////////////////////////////////////////////////////////
//cub3d.c
void	cub_init(t_cub *cub);
void	ft_stop(int status, t_cub *cub, char *msg);
void	free_all(t_cub *cub, int i);

//parse_dot_cub.c
void	parse_dot_cub(char *map, t_cub *cub);
void	get_elements(t_cub *cub);
void	find_texture(t_cub *cub, char **str);
void	get_colors(t_cub *cub, int *tab);

//parse_dot_cub_2.c
void	parse_dot_cub_2(t_cub *cub);
void	reset_map(t_cub *cub);

//cub3d_utils.c
int		mini_gnl(char *map, t_cub *cub, int *j);
void	fill_from_dot_cub(t_cub *cub, char *map);
void	malloc_dot_cub(t_cub *cub, char *map);
void	display_description(t_cub *cub);// à retirer !!!

//check_map.c
void	find_max(t_cub *cub);
void	check_map(t_cub *cub, char *map);
void	scan_errors(t_cub *cub, char **map);
void	flood_fill_algo(t_cub *cub, int limit, int x, int y);

//execution///////////////////////////////////////////////////////////

//start_game.c
int		ft_exit(t_data *data);
void	start_game(t_cub *cub);

//load_texture.c
void	free_tex(t_data *data, t_mlx *tex, int i);
void	bufferize_texture(t_data *data, t_mlx *tex, int *dst);
void	load_more_texture(t_data *data, t_mlx *tex);
void	init_tex(t_mlx *tex);
void	load_texture(t_data *data);

//hook.c
int		next_frame(t_data *data);
int		hook_pressed(int keycode, t_data *data);
int		hook_released(int keycode, t_data *data);

//move_pos.c
void	pos_wall(t_data *data);
void	move_player2(t_data *data);
void	move_player(t_data *data);

//move_pos_d_a.c
void	move_player_d2(t_data *data);
void	move_player_d(t_data *data);
void	move_player_a2(t_data *data);
void	move_player_a(t_data *data);

//mlx_utils.c
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		mlx_pixel_get(t_mlx *mlx, int x, int y);

//mini_map.c
void	free_strs(char **str);
void	put_player(t_data *data, int x, int y);
void	draw_map_2d2(t_data *data, int x, int y, int color);
void	draw_map_2d(t_data *data, char **map);

//raycasting.c
void	get_dist_ray(t_data *data);
void	init_ra(t_data *data, int i);
void	draw_rays3d(t_data *data);

//ray_hor.c
int		out_of_map(t_data *data);
float	draw_rays_hor3d2(t_data *data);
float	draw_rays_hor3d(t_data *data);

//ray_ver.c
float	dist(float ax, float ay, float bx, float by);
float	draw_rays_ver3d2(t_data *data);
float	draw_rays_ver3d(t_data *data);

//draw.c
void	draw_3d(t_data *data);

#endif