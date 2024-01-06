/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarabei <mgarabei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 19:53:49 by mgarabei          #+#    #+#             */
/*   Updated: 2023/09/11 23:23:34 by mgarabei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_flag(char specifier, va_list *args, int *count)
{
	if (specifier == '%')
		*count += ft_char('%');
	else if (specifier == 'c')
		*count += ft_char(va_arg(*args, int));
	else if (specifier == 's')
		*count += ft_str(va_arg(*args, char *));
	else if (specifier == 'd' || specifier == 'i')
		*count += ft_nbr(va_arg(*args, int));
	else if (specifier == 'u')
		*count += ft_unsigned_int(va_arg(*args, unsigned int));
	else if (specifier == 'x')
		*count += ft_hex(va_arg(*args, unsigned int), 'x');
	else if (specifier == 'X')
		*count += ft_hex(va_arg(*args, unsigned int), 'X');
	else if (specifier == 'p')
		*count += ft_ptr(va_arg(*args, size_t));
	return (*count);
}

int	ft_printf(const char *string, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, string);
	while (string[i] != '\0')
	{
		if (string[i] == '%')
		{
			i++;
			ft_flag(string[i], &args, &count);
			i++;
		}
		else
		{
			count += ft_char((char)string[i]);
			i++;
		}
	}
	va_end(args);
	return (count);
}
/*
int	main(void)
{
	int	a,b,c,d,e,f,g,h,i,j;
//no flags:
	a = ft_printf("HI\n");
	b = printf("HI\n");
	printf("mine: %d, built-in: %d\n", a, b);
//charecters:


// %:
	e = ft_printf("this %%\n");
	f = printf("this %%\n");
	printf("mine: %d, built-in: %d\n", e, f);	
//strings:
	c = ft_printf("Hi %s", "there.\n");
	d = printf("Hi %s", "there.\n");
	printf("mine: %d, built-in: %d\n", c, d);
//numbers;
	g = ft_printf("nbrs: %d, %i, %u\n", 450, 22, -4444562);
	h = printf("nbrs: %d, %i, %u\n", 450, 22, -4444562);
	printf("mine: %d, built-in: %d\n", g, h);

	i = ft_printf(NULL);
	j = printf(NULL);
	printf("mine: %d, built-in: %d\n", i, j);
}
*/