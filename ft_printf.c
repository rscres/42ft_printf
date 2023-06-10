/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 15:16:54 by rseelaen          #+#    #+#             */
/*   Updated: 2023/06/09 21:18:04 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

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
	if (*(str + 2) == 'X')
	{
		len += write(1, "0X", 2);
		len += ft_puthex(num, 1);
	}
	else if (*(str + 2) == 'x')
	{
		len += write(1, "0x", 2);
		len += ft_puthex(num, 0);
	}
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

int	is_flag(char c)
{
	if (c == ' ' || c == '#' || c == '+')
		return (1);
	return (0);
}

int	flag_setter(int flags, char c)
{
	if (c == '#')
		flags |= HEX_FLAG;
	else if (c == '+')
	{
		flags |= PLUS_FLAG;
		flags &= ~(SPACE_FLAG);
	}
	else if (c == ' ' && (flags & PLUS_FLAG) == 0)
		flags |= SPACE_FLAG;
	return (flags);
}

int	is_placeholder(char c)
{
	if (c == 'c' || c == 's' || c == 'i' || c == 'd' || c == 'x'
		|| c == 'X' || c == 'u' || c == 'p')
		return (1);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list			args;
	int				len;
	unsigned int	flags;
	char			*temp;

	if (!str)
		return (-1);
	len = 0;
	flags = 0;
	va_start(args, str);
	while (*str != '\0')
	{
		if (*str == '%' && is_flag(*(str + 1)))
		{
			temp = str;
			while (is_flag(*(str + 1)))
			{
				flags = flag_setter(flags, *(str + 1));
				str++;
			}
			if (!is_placeholder(*(str + 1)))
			{
				write (1, "%", 1);
				if (flags & HEX_FLAG)
					write (1, "#", 1);
				if (flags & PLUS_FLAG)
					write (1, "+", 1);
				else if (flags & SPACE_FLAG)
					write (1, " ", 1);
			}
			else
			{

			}
		}
		else if (*str == '%' && !is_flag(*(str + 1)))
		{
			sign_checker(len, args, str);
			str++;
		}
		else
			len += ft_putchar(*str);
		str++;
	}
	va_end(args);
	return (len);
}

int main(void)
{
	ft_printf("' %+++ ###y'\n", 2);
}
