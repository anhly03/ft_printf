/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putchar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phly <phly@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:25:41 by phly              #+#    #+#             */
/*   Updated: 2025/08/01 01:43:26 by phly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

// void	ft_printf(const char *format, ...)
// {
// 	va_list	args;
// 	int		i;
// 	char	c;

// 	va_start(args, format);
// 	i = 0;
// 	while (format[i])
// 	{
// 		if (format[i] == '%' && format[i + 1] == 'c')
// 		{
// 			c = va_arg(args, int);
// 			ft_putchar(c);
// 			i += 2;
// 		}
// 		else
// 		{
// 			ft_putchar(format[i]);
// 			i++;
// 		}
// 	}
// 	va_end(args);
// }



char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*str;

	s1_len = 0;
	s2_len = 0;
	if (!s1 || !s2)
		return (NULL);
	while (s1)
		s1_len++;
	while (s2)
		s2_len++;
	str = malloc (s1_len + s2_len + 1);
	if (!str)
		return (NULL);
	
}

void	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	char	*s;

	va_start(args, format);
	s = va_arg(args, char *);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == 's')
		{
			i += 2;
		}
		else
		{
			write(1, &format[i], 1);
			i++;
		}
	}
	va_end(args);
}

int main()
{
	ft_printf("Hello %s!\n", "world");
	return 0;
}