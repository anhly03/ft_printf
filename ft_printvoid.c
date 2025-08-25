/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printvoid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phly <phly@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:06:25 by phly              #+#    #+#             */
/*   Updated: 2025/08/14 15:13:25 by phly             ###   ########.fr       */
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
	int		temp;

	len = ft_intlen_pointer(n);
	if (n >= 16)
	{
		temp = ft_putvoid(n / 16, base);
		if (temp == -1)
			return (-1);
	}
	c = base[n % 16];
	if (write(1, &c, 1) == -1)
		return (-1);
	return (len);
}

int	ft_printvoid(void *ptr)
{
	unsigned long	addr;
	int				len;
	char			*base;
	int				temp;

	addr = (unsigned long)ptr;
	len = ft_intlen_pointer(addr);
	base = "0123456789abcdef";
	if (!addr)
	{
		if (write(1, "(nil)", 5) == -1)
			return (-1);
		return (5);
	}
	if (write(1, "0x", 2) == -1)
		return (-1);
	temp = ft_putvoid(addr, base);
	if (temp == -1)
		return (-1);
	return (len + 2);
}
