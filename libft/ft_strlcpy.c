/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 12:38:14 by mabuchar          #+#    #+#             */
/*   Updated: 2021/01/12 17:24:13 by mabuchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int destsize)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (!dest || !src)
		return (0);
	if (destsize > 0)
	{
		while (src[i] && i < destsize - 1)
		{
			dest[i] = src[i];
			i++;
		}
	}
	if (destsize > 0)
		dest[i] = '\0';
	j = 0;
	while (src[j])
		j++;
	return (j);
}
