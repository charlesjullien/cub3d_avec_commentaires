/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <cjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:30:44 by cjullien          #+#    #+#             */
/*   Updated: 2022/02/15 11:34:47 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *s1, size_t n)
{
	char	*dst;

	dst = malloc(sizeof(char) * n + 1);
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, s1, n + 1);
	return (dst);
}
