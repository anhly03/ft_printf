/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printvoid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phly <phly@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:06:25 by phly              #+#    #+#             */
/*   Updated: 2025/08/13 18:08:48 by phly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_intlen_pointer(unsigned long n)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n)
	{
		n /= 16;
		len++;
	}
	return (len);
}

int	ft_putvoid(unsigned long n, char *base)
{
	int		len;
	char	c;

	len = ft_intlen_pointer(n);
	if (n >= 16)
		ft_putvoid(n / 16, base);
	c = base[n % 16];
	write(1, &c, 1);
	return (len);
}

int	ft_printvoid(void *ptr)
{
	unsigned long	addr;
	int				len;
	char			*base;

	addr = (unsigned long)ptr;
	len = ft_intlen_pointer(addr);
	base = "0123456789abcdef";
	if (addr == 0)
	{
		write(1, "0x0", 3);
		return (3);
	}
	else
	{
		write(1, "0x", 2);
		ft_putvoid(addr, base);
		return (len + 2);
	}
}
