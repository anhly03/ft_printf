/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phly <phly@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 01:39:49 by phly              #+#    #+#             */
/*   Updated: 2025/08/01 01:43:19 by phly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_intlen(int nb)
{
	int	len;

	len = (nb <= 0);
	while (nb)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	nb;

	nb = n;
	len = ft_intlen(n);
	str = malloc ((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (nb == 0)
		str[0] = '0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb)
	{
		str[len--] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}

void	ft_printf(const char *format, ...)
{
	va_list	args;
	int		n;
	char	*s;
	int		i;
	int		j;

	va_start(args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && (format[i + 1] == 'd' || format[i + 1] == 'i'))
		{
			n = va_arg(args, int);
			s = ft_itoa(n);
			if (!s)
				return ;
			j = 0;
			while (s[j])
				write(1, &s[j++], 1);
			free (s);
			i += 2;
			continue ;
		}
		write(1, &format[i], 1);
		i++;
	}
	va_end(args);
}
int main(void)
{
	ft_printf("So A = %d va B = %d!\n", 42, -123);
	return (0);
}
