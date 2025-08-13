/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   310725.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phly <phly@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 23:27:24 by phly              #+#    #+#             */
/*   Updated: 2025/07/31 23:27:25 by phly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	handle_conversation(char spec, va_list arg)
{
	if (spec == 's')
		return (ft_printstr(va_arg(arg, char *))); //viet roi
	else if (spec == 'c')
		return (ft_printchar((char)va_arg(arg, int)));//viet roi
	else if (spec == 'p')
		return (ft_printvoid(va_arg(arg, void *))); //viet roi
	else if (spec == 'd' || spec == 'i')
		return (ft_printnumber(va_arg(arg, int))); //viet roi
	else if (spec == 'u')
		return (ft_printunsigned(va_arg(arg, unsigned int))); //viet roi
	else if (spec == 'x' || spec == 'X')
		return (ft_printhex(va_arg(arg, unsigned int)));
	else if (spec == '%')
		return (ft_printpercent()); //viet roi
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		len;
	int		i;
	char	spec;
	char	c;

	va_start(arg, format);
	len = 0;
	i = 0;
	while(format[i])
	{
		if(format[i] == '%' && format[i + 1] == spec)
		{
			handle_conversation(spec, va_list arg);
			len++;
			i++;
			continue ;
		}
		else if
		{

		}
	}
	va_end(arg);
	return (len);
}
