/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnumber.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phly <phly@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:25:41 by phly              #+#    #+#             */
/*   Updated: 2025/08/13 18:08:17 by phly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_intlen(int nbr)
{
	int	len;

	len = 0;
	if (nbr <= 0)
		len = 1;
	while (nbr)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*s;
	long	nb;
	int		len;

	nb = n;
	len = ft_intlen(n);
	s = malloc((len + 1) * sizeof(char));
	if (!s)
		return (NULL);
	s[len - 1] = '\0';
	if (nb < 0)
	{
		nb = -nb;
		s[0] = '-';
	}
	if (nb == 0)
		s[0] = '0';
	while (nb > 10)
	{
		s[len--] = nb % 10 + '0';
		nb /= 10;
	}
	return (s);
}

int	ft_printnumber(int n)
{
	char	*s;
	int		i;

	s = ft_itoa(n);
	if (!s)
		return (1);
	i = 0;
	while (s[i])
		write(1, &s[i++], 1);
	free (s);
	return (i);
}
