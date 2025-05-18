/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dt <dt@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:55:11 by dt                #+#    #+#             */
/*   Updated: 2025/03/08 16:55:12 by dt               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
void	format_func(char b, va_list *args);
int		put_char(char c, int a);
void	print_str(char *p);
void	ft_putnbr(long int n, int base_num, char *base_chars, int uns);
void	print_pointer(unsigned long ptr);

#endif