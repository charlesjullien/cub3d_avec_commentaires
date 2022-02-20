/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dot_cub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <cjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:07:47 by cjullien          #+#    #+#             */
/*   Updated: 2022/02/16 10:18:14 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	get_colors(t_cub *cub, int *tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (ft_isalpha(cub->line[i]))
		i++;
	while (cub->line[i] == ' ')
		i++;
	while (j < 3)
	{
		tab[j] = ft_atoi(&cub->line[i]);
		while (ft_isdigit(cub->line[i]))
			i++;
		if (cub->line[i] == ',' && j != 2) //peut on avoir aussi des espaces près des virgules ? dans ce cas : while (line[i] == ' ')
			i++;
		else if (j == 2)
		{
			while (cub->line[i] == ' ')
				i++;
			if (cub->line[i] != '\0') // ++ajouter une gestions d'erreur pour les chiffres rgb impossibles genre -764 ou 98154...
				ft_stop(EXIT_FAILURE, cub, "Error\nIssue in C or F RGB infos.");
		}
		j++;
	}
}

void	find_texture(t_cub *cub, char **str)//**str = pointeur sur la bonne chaine dans la struct.
{
	int i;

	i = 0;
	while (ft_isalpha(cub->line[i]))
		i++;
	while (cub->line[i] == ' ')
		i++;
	*str = ft_strdup(&cub->line[i]);// *str car pointeur
	if (i < 3 || i == 0 || !*str)
		ft_stop(EXIT_FAILURE, cub, "Error\nIssue in textures infos");
}

void	get_elements(t_cub *cub)
{
	if (ft_strnstr(cub->line, "NO", 2) && !cub->north)
		find_texture(cub, &cub->north);
	else if (ft_strnstr(cub->line, "SO", 2) && !cub->south)
		find_texture(cub, &cub->south);
	else if (ft_strnstr(cub->line, "WE", 2) && !cub->west)
		find_texture(cub, &cub->west);
	else if (ft_strnstr(cub->line, "EA", 2) && !cub->east)
		find_texture(cub, &cub->east);
	else if (ft_strnstr(cub->line, "F ", 2) && cub->floor[0] == -1)
		get_colors(cub, cub->floor);
	else if (ft_strnstr(cub->line, "C ", 2) && cub->ceiling[0] == -1)
		get_colors(cub, cub->ceiling);
	else
		ft_stop(EXIT_FAILURE, cub, "Error\nElements organized in a wrong way in .cub");
}

void	parse_dot_cub(char *map, t_cub *cub)
{
	int	j;
	int	elements;

	elements = 0;
	j = 0;
	fill_from_dot_cub(cub, map);
	while (elements < 6)
	{
		if (mini_gnl(&cub->dot_cub[j], cub, &j) ==  0 && elements < 6)
			ft_stop(EXIT_FAILURE, cub, "Error\nWrong orga in .cub file");
		if (cub->line)
		{
			get_elements(cub);
			elements++;
		}
	}
	check_map(cub, &cub->dot_cub[j]);
}
