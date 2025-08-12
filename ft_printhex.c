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

	len = ft_intlen_hex(n);
	if (n >= 16)
		ft_puthex(n / 16, base);
	c = base[n % 16];
	write (1, &c, 1);
	return (len);
}

int	ft_printhex(unsigned int n, char format)
{
	char	*base;
	int		len;

	len = ft_intlen_hex(n);
	if (format == 'x')
		base = "0123456789abcdef";
	else if (format == 'X')
		base = "0123456789ABCDEF";
	else
		return (0);
	ft_puthex(n, base);
	return (len);
}

// int main()
// {
// 	ft_printhex(255, 'X');
// 	return 0;
// }

