/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 19:15:02 by rseelaen          #+#    #+#             */
/*   Updated: 2023/06/09 19:17:14 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

//HEX KEYS
# define HEX_CAPS	"0123456789ABCDEF"
# define HEX_LOW	"0123456789abcdef"

//FLAGS
# define HEX_FLAG 	0b1
# define SPACE_FLAG 0b10
# define PLUS_FLAG 	0b100
# define MINUS_FLAG 0b1000
# define ZERO_FLAG 	0b10000
# define DOT_FLAG 	0b100000

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