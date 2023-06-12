/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 15:16:54 by rseelaen          #+#    #+#             */
/*   Updated: 2023/06/12 15:05:35 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

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
		len += write(1, "(null)", 6);
	else
	{
		while (*s)
			len += write(1, s++, 1);
	}
	return (len);
}

int format_checker(int len, va_list args, const char *str)
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

int is_flag(char c)
{
	if (c == ' ' || c == '#' || c == '+')
		return (1);
	return (0);
}

int flag_setter(unsigned char flags, char c)
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

int is_placeholder(char c)
{
	if (c == 'c' || c == 's' || c == 'i' || c == 'd' || c == 'x' || c == 'X' || c == 'u' || c == 'p')
		return (1);
	return (0);
}

int ft_printf(const char *str, ...)
{
	va_list args;
	int len;
	unsigned char flags;

	if (!str)
		return (-1);
	len = 0;
	flags = 0;
	va_start(args, str);
	while (*str != '\0')
	{
		if (*str == '%' && is_flag(*(str + 1)))
		{
			while (is_flag(*(str + 1)))
			{
				flags = flag_setter(flags, *(str + 1));
				str++;
			}
			if (!is_placeholder(*(str + 1)))
			{
				len += write(1, "%", 1);
				if (flags & HEX_FLAG)
					len += write(1, "#", 1);
				if (flags & PLUS_FLAG)
					len += write(1, "+", 1);
				else if (flags & SPACE_FLAG)
					len += write(1, " ", 1);
				flags = 0;
			}
			else
			{
				if ((flags & HEX_FLAG) && (*(str + 1) == 'x'
						|| *(str + 1) == 'X'))
				{
					len = hashtag_handler(*(str + 1), args, len);
					str++;
				}
				if ((flags & PLUS_FLAG) && (*(str + 1) == 'd'
						|| *(str + 1) == 'i'))
				{
					len = plus_handler(args, len);
					str++;
				}
				else if ((flags & SPACE_FLAG) && (*(str + 1) == 'd'
						|| *(str + 1) == 'i' || *(str + 1) == 's'))
				{
					if (*(str + 1) == 's')
						len += ft_putstr(va_arg(args, char *));
					else if (*(str + 1) == 'd' || *(str + 1) == 'i')
						len = space_handler(args, len);
					str++;
				}
				flags = 0;
			}
		}
		else if (*str == '%' && !is_flag(*(str + 1)))
			len = format_checker(len, args, str++);
		else
			len += ft_putchar(*str);
		str++;
	}
	va_end(args);
	return (len);
}

// int main(void)
// {
// 	int len1 = ft_printf("' %x %d '\n", 100);
// 	int len2 = printf("' %x %d '\n", 100);
// 	printf("len1: %d\nlen2: %d\n", len1, len2);
// }
