/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phly <phly@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 23:27:24 by phly              #+#    #+#             */
/*   Updated: 2025/08/13 18:01:17 by phly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	handle_conversation(char spec, va_list arg)
{
	if (spec == 's')
		return (ft_printstr(va_arg(arg, char *)));
	else if (spec == 'c')
		return (ft_printchar((char)va_arg(arg, int)));
	else if (spec == 'p')
		return (ft_printvoid(va_arg(arg, void *)));
	else if (spec == 'd' || spec == 'i')
		return (ft_printnumber(va_arg(arg, int)));
	else if (spec == 'u')
		return (ft_printunsigned(va_arg(arg, unsigned int)));
	else if (spec == 'x' || spec == 'X')
		return (ft_printhex(va_arg(arg, unsigned int)));
	else if (spec == '%')
		return (ft_printpercent());
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		len;
	int		i;
	char	spec;

	va_start(arg, format);
	len = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
			{
				write(1, '%', 1);
				len++;
				break ;
			}
			spec = format[i + 1];
			len += handle_conversation(spec, arg);
			i += 2;
			continue ;
		}
		else
		{
			write(1, &format[i++], 1);
			len++;
		}
	}
	va_end(arg);
	return (len);
}
