#include "libftprintf.h"

void	ft_printstr(const char *format, ...)
{
	va_list	arg;
	int		i;
	int		j;
	char	*s;

	va_start(arg, format);
	i = 0;
	j = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == 's')
		{
			s = va_arg(arg, char *);
			while (s[j])
				write(1, &s[j++], 1);
			i += 2;
			continue ;
		}
		write(1, &format[i++], 1);
	}
	va_end(arg);
}

int	ft_printstr(const char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
		write(1, &s[i++], 1);
	return (i);
}
