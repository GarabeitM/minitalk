/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbrs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarabei <mgarabei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:53:05 by mgarabei          #+#    #+#             */
/*   Updated: 2023/07/17 15:05:36 by mgarabei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbr(int number)
{
	int	count;

	count = 0;
	if (number == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (number < 0)
	{
		count = ft_char('-');
		count += ft_nbr(number * -1);
	}
	else
	{
		if (number > 9)
			count += ft_nbr(number / 10);
		count += ft_char(number % 10 + '0');
	}
	return (count);
}

int	ft_unsigned_int(unsigned int u)
{
	int	count;

	count = 0;
	if (u >= 10)
		count += ft_unsigned_int(u / 10);
	count += ft_char(u % 10 + '0');
	return (count);
}

int	ft_ptr(size_t pointer)
{
	int		i;
	int		count;
	char	string[25];
	char	*base_character;

	i = 0;
	count = 0;
	base_character = "0123456789abcdef";
	write(1, "0x", 2);
	count += 2;
	if (pointer == 0)
	{
		count += ft_char('0');
		return (count);
	}
	while (pointer != 0)
	{
		string[i] = base_character[pointer % 16];
		pointer = pointer / 16;
		i++;
	}
	while (i--)
		count += ft_char(string[i]);
	return (count);
}

int	ft_hex(unsigned int x, char x_case)
{
	int		i;
	int		count;
	char	string[25];
	char	*base_character;

	if (x_case == 'X')
		base_character = "0123456789ABCDEF";
	else
		base_character = "0123456789abcdef";
	i = 0;
	count = 0;
	if (x == 0)
	{
		count += ft_char('0');
		return (count);
	}
	while (x != 0)
	{
		string[i] = base_character [x % 16];
		x = x / 16;
		i++;
	}
	while (i--)
		count += ft_char(string[i]);
	return (count);
}
