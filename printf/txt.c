/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   txt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarabei <mgarabei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:52:05 by mgarabei          #+#    #+#             */
/*   Updated: 2023/07/17 14:52:42 by mgarabei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_char(char c)
{
	return (write(1, &c, 1));
}

int	ft_str(char *args)
{
	size_t	i;

	i = 0;
	if (!args)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (args[i] != '\0')
	{
		ft_char(args[i]);
		i++;
	}
	return (i);
}
