/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dot_cub_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <cjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:40:14 by cjullien          #+#    #+#             */
/*   Updated: 2022/02/17 14:40:15 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	reset_map(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (cub->map[i][j] == 'F')
				cub->map[i][j] = '0';
			j++;
		}
		i++;
	}
}

void	parse_dot_cub_2(t_cub *cub)
{
	if (cub->floor[0] < 0 || cub->floor[0] > 255
		|| cub->floor[1] < 0 || cub->floor[1] > 255
		|| cub->floor[2] < 0 || cub->floor[2] > 255)
		ft_stop(EXIT_FAILURE, cub, "Error\nF RGB must be >= 0 || <= 255");
	if (cub->ceiling[0] < 0 || cub->ceiling[0] > 255
		|| cub->ceiling[1] < 0 || cub->ceiling[1] > 255
		|| cub->ceiling[2] < 0 || cub->ceiling[2] > 255)
		ft_stop(EXIT_FAILURE, cub, "Error\nC RGB must be >= 0 || <= 255");
	reset_map(cub);
}
