#include "../includes/cub3d.h"

int	next_frame(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, data->ml, data->mh);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixels,
			&data->line_length, &data->endian);
	move_player(data);
	draw_rays3d(data);
	draw_map_2d(data, data->map);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

int	hook_pressed(int keycode, t_data *data)
{
	if (keycode == 119)									// code touche w = 119
		data->w = 1;
	if (keycode == 97)									// code touche a = 97
		data->a = 1;
	if (keycode == 115)									// code touche s = 115
		data->s = 1;
	if (keycode == 100)									// code touche d = 100
		data->d = 1;
	if (keycode == 65361)								// code touche <- = 65361
		data->gau = 1;
	if (keycode == 65363)								// code touche -> = 65363
		data->dro = 1;
	return (keycode);
}

int	hook_released(int keycode, t_data *data)
{
	if (keycode == 119)									// code touche w = 119
		data->w = 0;
	if (keycode == 97)									// code touche a = 97
		data->a = 0;
	if (keycode == 115)									// code touche s = 115
		data->s = 0;
	if (keycode == 100)									// code touche d = 100
		data->d = 0;
	if (keycode == 65361)								// code touche <- = 65361
		data->gau = 0;
	if (keycode == 65363)								// code touche -> = 65363
		data->dro = 0;
	if (keycode == 65307)								// code echap = 65307 dans ce cas free tout et exit
	{
		ft_putstr_fd("Goodbye!\n", 0);
		ft_exit(data);
	}
	return (keycode);
}
