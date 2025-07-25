/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phly <phly@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 01:39:49 by phly              #+#    #+#             */
/*   Updated: 2025/07/25 02:08:02 by phly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>
#include <unistd.h>

// void my_print(const char *format, ...)
// {
//     va_list args;
//     va_start(args, format);
//     char *str;
//     int i;

//     i = 0;
//     str = va_arg(args,char *);
//     while (str[i] != '\0')
//     {
//         write(1, &str[i], 1);
//         i++;
//     }
//     va_end(args);
// }

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = malloc(s1_len + s2_len + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, s1_len + 1);
	ft_strlcat(str, s2, s1_len + s2_len +1);
	return (str);
}

void ft_printf(const char *, ...)
{
    va_list args;
    va_start(args, format);
    int num;
    int digit;
    char *reverse;
    int i;

    num = va_arg(args, int);
    if (num == 0)
        write (1, '0', 1);
    if (num < 0)
        {
            num = -num;
            write (1, '-',1);
        }
    if (num >= 10)
    {
        digit = num%10 + '0';
        num = num/10 +'0';
    }
    reverse = ft_strjoin(num, digit);
    i = 0;
    while (*reverse)
        write(1, &reverse[i++], 1);
    va_end(args);
}
