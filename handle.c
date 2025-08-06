/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   310725.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phly <phly@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 23:27:24 by phly              #+#    #+#             */
/*   Updated: 2025/07/31 23:27:25 by phly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	handle_conversation(char spec, va_list arg)
{
	if (spec == 's')
		return (ft_printstr(va_arg(arg, char *)));
	else if (spec == 'c')
		return (ft_printchar((char)va_arg(arg, int)));
	else if (spec == 'p')
		return (ft_printhex(va_arg(arg, void *)));
	else if (spec == 'd' || spec == 'i')
		return (ft_printnumber(va_arg(arg, int)));
	else if (spec == 'u')
		return (ft_printunsigned(va_arg(arg, unsigned int)));
	else if (spec == 'x')
		return (ft_printlow(va_arg(arg, unsigned int)));
	else if (spec == 'X')
		return (ft_print_upp(va_arg(arg, unsigned int)));
	else if (spec == '%')
		return (ft_printpercent());
	return (0);
}
