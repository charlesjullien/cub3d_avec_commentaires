#include "../includes/cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = (data->addr + (y * data->line_length + x
				* (data->bits_per_pixels / 8)));
	*(unsigned int *)dst = color;
}

int	mlx_pixel_get(t_mlx *mlx, int x, int y)
{
	char	*color;

	color = mlx->addr + (x * mlx->len + y * (mlx->bpp / 8));
	return (*(unsigned int *)color);
}
