/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:28:52 by mabuchar          #+#    #+#             */
/*   Updated: 2021/01/19 17:02:05 by mabuchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_word_count(const char *str, char charset)
{
	int		i;
	int		count;

	i = 1;
	count = 0;
	if (str[0] != charset)
	{
		i++;
		count++;
	}
	if (str[0] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (str[i - 1] == charset && str[i] != charset)
			count++;
		i++;
	}
	return (count);
}

char	**ft_malloc(char const *str, char c)
{
	char	**tab;
	int		len;

	if (!str)
		return (NULL);
	len = ft_word_count(str, c);
	tab = malloc(sizeof(char *) * (len + 1));
	if (tab == NULL)
		return (NULL);
	return (tab);
}

int	ft_next_word(const char *str, int i, char charset)
{
	int		count;

	count = 0;
	while (str[i] == charset && str[i] != '\0')
		i++;
	while (str[i] != charset && str[i] != '\0')
	{
		i++;
		count++;
	}
	return (count);
}

char	**ft_free(char **tab, int i)
{
	int	j;

	j = 0;
	while (j < i && tab[j] != 0)
		free(tab[j++]);
	free(tab);
	return (0);
}

char	**ft_split(char const *str, char c)
{
	int		i;
	int		j;
	int		s;
	char	**tab;

	s = -1;
	i = 0;
	tab = ft_malloc(str, c);
	if (!tab || !str)
		return (NULL);
	while (++s < ft_word_count(str, c))
	{
		j = 0;
		tab[s] = malloc(sizeof(char) * ft_next_word(str, i, c) + 1);
		if (!tab[s])
			return (ft_free(tab, i));
		while (str[i] == c && str[i])
			i++;
		while (str[i] != c && str[i])
			tab[s][j++] = str[i++];
		tab[s][j] = '\0';
	}
	tab[s] = 0;
	return (tab);
}
