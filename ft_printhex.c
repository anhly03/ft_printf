/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phly <phly@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:07:03 by phly              #+#    #+#             */
/*   Updated: 2025/08/14 15:34:28 by phly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_intlen_hex(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

int	ft_puthex(unsigned int n, char *base)
{
	int		len;
	char	c;
	int		temp;

	len = ft_intlen_hex(n);
	if (n >= 16)
	{
		temp = ft_puthex(n / 16, base);
		if (temp == -1)
			return (-1);
	}
	c = base[n % 16];
	if (write (1, &c, 1) == -1)
		return (-1);
	return (len);
}

int	ft_printhex(unsigned int n, char format)
{
	char	*base;
	int		len;
	int		temp;

	len = ft_intlen_hex(n);
	if (format == 'x')
		base = "0123456789abcdef";
	else if (format == 'X')
		base = "0123456789ABCDEF";
	else
		return (0);
	temp = ft_puthex(n, base);
	if (temp == -1)
		return (-1);
	return (len);
}

// int main()
// {
// 	ft_printhex(255, 'X');
// 	return 0;
// }