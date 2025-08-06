/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   010825.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phly <phly@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 01:15:48 by phly              #+#    #+#             */
/*   Updated: 2025/08/01 01:15:49 by phly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printchar(const char *format, ...)
{
	va_list	arg;
	char	c;
	int		i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == 'c')
		{
			c = (char)va_arg(arg, int);
			write (1, &c, 1);
			i += 2;
			continue ;
		}
		write (1, &format[i++], 1);
		i++;
	}
	va_end(arg);
}

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}
