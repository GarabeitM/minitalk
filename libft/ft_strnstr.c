/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarabei <mgarabei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:14:07 by mgarabei          #+#    #+#             */
/*   Updated: 2023/05/31 11:31:19 by mgarabei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

const char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!little[i])
		return (big);
	while (i < len && big[i])
	{
		j = 0;
		while ((i + j < len) && big[i + j] == little[j] && little[j] != '\0')
			j++;
		if (!little[j])
			return (big + i);
		i++;
	}
	return (NULL);
}
