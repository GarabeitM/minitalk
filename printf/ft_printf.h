/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarabei <mgarabei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 20:09:24 by mgarabei          #+#    #+#             */
/*   Updated: 2023/07/19 11:31:14 by mgarabei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stddef.h>

int		ft_char(char c);
int		ft_str(char *args);
int		ft_nbr(int number);
int		ft_unsigned_int(unsigned int u);
int		ft_hex(unsigned int x, char x_case);
int		ft_ptr(size_t pointer);
int		ft_printf(const char *string, ...);

#endif