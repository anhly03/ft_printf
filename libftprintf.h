/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phly <phly@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 18:07:32 by phly              #+#    #+#             */
/*   Updated: 2025/08/14 15:25:20 by phly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>

int	ft_printchar(int c);
int	ft_printhex(unsigned int n, char format);
int	ft_printnumber(int n);
int	ft_printpercent(void);
int	ft_printstr(const char *s);
int	ft_printunsigned(unsigned int n);
int	ft_printvoid(void *ptr);
int	ft_printf(const char *format, ...);

#endif
