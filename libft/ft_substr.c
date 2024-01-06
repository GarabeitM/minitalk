/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarabei <mgarabei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:18:21 by mgarabei          #+#    #+#             */
/*   Updated: 2023/05/31 11:31:31 by mgarabei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len(char const *s, unsigned int start, size_t len)
{
	size_t	l;

	if (start >= ft_strlen(s))
		return (0);
	l = 0;
	while (s[start + l] && l < len)
		l++;
	return (l);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	l;
	char	*sub_string;

	l = ft_len(s, start, len);
	sub_string = malloc((l + 1) * sizeof(char));
	if (!sub_string)
		return (NULL);
	i = 0;
	while (i < l)
	{
		sub_string[i] = s[start + i];
		i++;
	}
	sub_string[i] = '\0';
	return (sub_string);
}
