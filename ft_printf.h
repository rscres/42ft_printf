/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 19:15:02 by rseelaen          #+#    #+#             */
/*   Updated: 2023/06/07 17:27:01 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# define HEX_CAPS "0123456789ABCDEF"
# define HEX_LOW "0123456789abcdef"

//ft_printf.c
int		ft_printf(const char *s, ...);
int		ft_putstr(char *s);
int		ft_putchar(char c);

//num_printers.c
int		ft_putunsigned(unsigned int n);
int		ft_putnbr(int n);
int		ft_puthex(unsigned int n, int caps);
int		ft_putpointer(unsigned long int n, int flag);

//printf_bonus.c
int		flag_checker(const char *str);
int		hashtag_handler(const char *str, va_list args, int len);

#endif