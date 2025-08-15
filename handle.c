/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phly <phly@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 23:27:24 by phly              #+#    #+#             */
/*   Updated: 2025/08/14 15:04:12 by phly             ###   ########.fr       */
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
		return (ft_printhex(va_arg(arg, unsigned int), spec));
	else if (spec == '%')
		return (ft_printpercent());
	return (0);
}

// int	ft_printf(const char *format, ...)
// {
// 	va_list	arg;
// 	int		len;
// 	int		i;
// 	int		temp;

// 	va_start(arg, format);
// 	len = 0;
// 	i = 0;
// 	temp = 0;
// 	while (format[i])
// 	{
// 		if (format[i] == '%' && format[i + 1])
// 		{
// 			temp = handle_conversation(format[i + 1], arg);
// 			if (temp == -1)
// 				return (-1);
// 			len += temp;
// 			i += 2;
// 			continue ;
// 		}
// 		if (write(1, &format[i], 1) == -1)
// 		{
// 			va_end(arg);
// 			return (-1);
// 		}
// 		i++;
// 		len++;
// 	}
// 	va_end(arg);
// 	return (len);
// }

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		len;
	int		i;

	va_start(arg, format);
	len = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			if (handle_conversation(format[i + 1], arg) == -1)
				return (va_end(arg), -1);
			len += handle_conversation(format[i + 1], arg);
			i += 2;
			continue ;
		}
		if (write(1, &format[i], 1) == -1)
			return (va_end(arg), -1);
		i++;
		len++;
	}
	va_end(arg);
	return (len);
}
// int main()
// {
// 	ft_printf("\001\002\007\v\010\f\r\n");
// 	return 0;
// }
