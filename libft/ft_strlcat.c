/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarabei <mgarabei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:42:05 by mgarabei          #+#    #+#             */
/*   Updated: 2023/05/31 11:31:01 by mgarabei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (size == 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	while (dst[j] && j < size)
		j++;
	while (src[i] && (j + i) < size - 1)
	{
		dst[j + i] = src[i];
		i++;
	}
	if (j < size)
		dst[i + j] = '\0';
	return (j + ft_strlen(src));
}
