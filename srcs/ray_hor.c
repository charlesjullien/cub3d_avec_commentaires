#include "../includes/cub3d.h"

int	out_of_map(t_data *data)
{
	if (data->mx >= data->mapy || data->my >= data->mapx
		|| data->mx < 0 || data->my < 0
		|| (data->mx == 0 && data->rx < 0)
		|| (data->my == 0 && data->ry < 0)
		|| data->my > ft_strlen(data->map[data->mx]))
		return (1);
	return (0);
}

float	draw_rays_hor3d2(t_data *data)
{
	while (data->dof < data->mapx)
	{
		data->mx = (int)(data->rx) / 64;
		data->my = (int)(data->ry) / 64;
		if (out_of_map(data))
			break ;
		if (data->map[data->mx][data->my] == '1')
		{
			data->dof = data->mapx;
			data->hx = data->rx;
			data->hy = data->ry;
			if (data->ra >= PI)		// north color / texture
				data->colorw = 1;
			if (data->ra < PI)		// south color / texture
				data->colorw = 0;
			return (dist(data->posx, data->posy, data->hx, data->hy));
		}
		else
		{
			data->rx += data->xo;
			data->ry += data->yo;
			data->dof += 1;
		}
	}
	return (-1);
}

float	draw_rays_hor3d(t_data *data)
{
	data->dof = 0;
	data->atan = -1 / tan(data->ra);
	if (data->ra > PI)						// looking down (south)
	{
		data->ry = (((int)data->posy / 64) * 64) - 0.0001;
		data->rx = (data->posy - data->ry) * data->atan + data->posx;
		data->yo = -64;
		data->xo = -data->yo * data->atan;
	}
	if (data->ra < PI)						// looking up (north)
	{
		data->ry = (((int)data->posy / 64) * 64) + 64;
		data->rx = (data->posy - data->ry) * data->atan + data->posx;
		data->yo = 64;
		data->xo = -data->yo * data->atan;
	}
	if (data->ra == 0 || data->ra == PI)	// impossible to touch a wall (east || west)
	{
		data->rx = data->posx;
		data->ry = data->posy;
		data->dof = data->mapx;
	}
	return (draw_rays_hor3d2(data));
}
