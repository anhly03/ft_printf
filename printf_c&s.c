/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phake.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phly <phly@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:07:03 by phly              #+#    #+#             */
/*   Updated: 2025/07/29 15:07:11 by phly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	char	c;
	char	*s;

	va_start(args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == 'c')
		{
			c = (char)va_arg(args, int);
			i += 2;
			write(1, &c, 1);
			continue ;
		}
		else if (format[i] == '%' && format[i + 1] == 's')
		{
			s = va_arg(args, char *);
			ft_putstr(s);
			i += 2;
			continue ;
		}
		write(1, &format[i++], 1);
	}
	va_end(args);
}

int main()
{
	ft_printf("Char: %c, String: %s\n", 'A', "Hello");
	return 0;
}