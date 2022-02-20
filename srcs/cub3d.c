/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <cjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:00:52 by cjullien          #+#    #+#             */
/*   Updated: 2022/02/16 10:03:26 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_all(t_cub *cub, int i)
{
	if (cub)
	{
		if (cub->north)
			free(cub->north);
		if (cub->west)
			free(cub->west);
		if (cub->south)
			free(cub->south);
		if (cub->east)
			free(cub->east);
		if (cub->map)
		{
			while (cub->map[i])
				free(cub->map[i++]);
			free(cub->map);
		}
		if (cub->line)
			free(cub->line);
		if (cub->cub_file)
			free(cub->cub_file);
		if (cub->dot_cub)
			free(cub->dot_cub);
	}
}

void	ft_stop(int status, t_cub *cub, char *msg)
{
	free_all(cub, 0);
	if (status)
	{
		write(2, msg, ft_strlen(msg));
		write(2, "\n", 1);
	}
	else
		write(1, msg, ft_strlen(msg));
	exit(status);
}

void	cub_init(t_cub *cub)
{
	cub->north = NULL;
	cub->south = NULL;
	cub->east = NULL;
	cub->west = NULL;
	cub->fd = 0;
	cub->floor[0] = -1;
	cub->ceiling[0] = -1;
	cub->line = NULL;
	cub->cub_file = NULL;
	cub->map = NULL;
	cub->dot_cub = NULL;
	cub->width = 0;
	cub->sp_dir = '!';
}

int	main(int argc, char **argv)
{
	t_cub	cub;

	if (argc != 2)
		ft_stop(EXIT_FAILURE, NULL, "Error\nInvalid number of arguments");
	cub_init(&cub);
	parse_dot_cub(argv[1], &cub);
	parse_dot_cub_2(&cub);
	//display_description(&cub);
	start_game(&cub);
	return (0);
}
