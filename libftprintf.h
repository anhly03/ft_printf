/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phly <phly@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 18:07:32 by phly              #+#    #+#             */
/*   Updated: 2025/08/01 01:13:44 by phly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

void	ft_printstr(const char *format, ...);
void	ft_printf(const char *, ...);
void	ft_putchar(char c);
void	ft_putstr(char *s);

#endif
