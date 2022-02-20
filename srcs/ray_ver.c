#include "../includes/cub3d.h"

float	dist(float ax, float ay, float bx, float by)
{
	return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}

float	draw_rays_ver3d2(t_data *data)
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
			if (data->ra >= P2 && data->ra < P3)		// west color / texture
				data->colorw = 2;
			if ((data->ra >= P3 && data->ra <= PI * 2)
				|| (data->ra >= 0.000000 && data->ra < P2))		// east color / texture
				data->colorw = 3;
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

float	draw_rays_ver3d(t_data *data)
{
	data->dof = 0;
	data->ntan = -tan(data->ra);
	if (data->ra > P2 || data->ra < P3)		// looking down (east)
	{
		data->rx = (((int)data->posx / 64) * 64) - 0.0001;
		data->ry = (data->posx - data->rx) * data->ntan + data->posy;
		data->xo = -64;
		data->yo = -data->xo * data->ntan;
	}
	if (data->ra < P2 || data->ra > P3)		// looking down (west)
	{
		data->rx = (((int)data->posx / 64) * 64) + 64;
		data->ry = (data->posx - data->rx) * data->ntan + data->posy;
		data->xo = 64;
		data->yo = -data->xo * data->ntan;
	}
	if (data->ra == P2 || data->ra == P3)	// impossible to touch a wall (south || north)
	{
		data->rx = data->posx;
		data->ry = data->posy;
		data->dof = data->mapx;
	}
	return (draw_rays_ver3d2(data));
}
