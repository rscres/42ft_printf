/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 13:59:06 by rseelaen          #+#    #+#             */
/*   Updated: 2023/06/07 20:54:17 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flag_checker(const char *str)
{
	if (*(str + 1) == '#')
		return (1);
	return (0);
}

int	hashtag_handler(const char *str, va_list args, int len)
{
	unsigned int	num;

	num = va_arg(args, unsigned int);
	if (num == 0)
	{	
		len += write(1, "0", 1);
		return (len);
	}
	len += write(1, "0x", 2);
	if (*(str + 2) == 'X')
		len += ft_puthex(num, 1);
	else if (*(str + 2) == 'x')
		len += ft_puthex(num, 0);
	return (len);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	len;

	len = 0;
	if (!s)
	{	
		write(1, "(null)", 6);
		len += 6;
	}
	else
	{
		while (*s)
		{
			write(1, s++, 1);
			len++;
		}
	}
	return (len);
}

int	sign_checker(int len, va_list args, const char *str)
{
	if (*(str + 1) == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (*(str + 1) == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (*(str + 1) == 'p')
		len += ft_putpointer(va_arg(args, unsigned long int), 1);
	else if (*(str + 1) == 'd' || *(str + 1) == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (*(str + 1) == 'u')
		len += ft_putunsigned(va_arg(args, unsigned int));
	else if (*(str + 1) == 'X')
		len += ft_puthex(va_arg(args, unsigned int), 1);
	else if (*(str + 1) == 'x')
		len += ft_puthex(va_arg(args, unsigned int), 0);
	else if (*(str + 1) == '%')
		len += write(1, "%", 1);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;

	len = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			if (flag_checker(str))
			{
				len = hashtag_handler(str, args, len);
				str++;
			}
			else
				len = sign_checker(len, args, str);
			str++;
		}
		else
		{
			ft_putchar(*str);
			len++;
		}
		str++;
	}
	va_end(args);
	return (len);
}
