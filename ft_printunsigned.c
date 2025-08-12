#include "libftprintf.h"

static int	ft_intlen(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_utoa(unsigned int n)
{
	int		len;
	char	*s;
	int		i;

	len = ft_intlen(n);
	s = malloc((len + 1) * sizeof(char));
	if (!s)
		return (NULL);
	s[len--] = '\0';
	if (n == 0)
		s[0] = '0';
	i = 0;
	while (n)
	{
		s[len--] = (n % 10) + '0';
		n /= 10;
	}
	return (s);
}


int	ft_printunsigned(unsigned int n)
{
	char	*s;
	int		i;

	s = ft_utoa(n);
	if (!s)
		return (-1);
	i = 0;
	while (s[i])
		write(1, &s[i++], 1);
	free (s);
	return (i);
}
