/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 15:16:54 by rseelaen          #+#    #+#             */
/*   Updated: 2023/06/06 18:50:08 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdarg.h>

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

// int	ft_putnbr(int n)
// {
// 	int	num;
// 	int	len;

// 	num = 0;
// 	len = 0;
// 	if (n == -2147483648)
// 	{
// 		write(1, "-2", 2);
// 		n = 147483648;
// 		len += 2;
// 	}
// 	if (n < 0)
// 	{
// 		len += write(1, "-", 1);
// 		n *= -1;
// 	}
// 	if (n / 10)
// 	{
// 		len += ft_putnbr((n / 10));
// 	}
// 	num = n % 10 + '0';
// 	len += write (1, &num, 1);
// 	return (len);
// }

int	sign_checker(int len, va_list args, const char *str)
{
	if (*(str + 1) == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (*(str + 1) == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (*(str + 1) == 'p')
		len += ft_putpointer(va_arg(args, unsigned long int), 1);
	else if (*(str + 1) == 'd')
		len += ft_putnbr_base(va_arg(args, int), 10, 0);
	else if (*(str + 1) == 'i')
		len += ft_putnbr_base(va_arg(args, int), 10, 0);
	else if (*(str + 1) == 'u')
		len += ft_putunsigned(va_arg(args, unsigned int));
	else if (*(str + 1) == 'X')
		len += ft_putnbr_base(va_arg(args, int), 16, 1);
	else if (*(str + 1) == 'x')
		len += ft_putnbr_base(va_arg(args, int), 16, 0);
	else if (*(str + 1) == '%')
	{
		write(1, "%", 1);
		len++;
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;

	len = 0;
	if (!str)
		return (0);
	va_start(args, str);
	while (*str != '\0')
	{
		if (*str == '%')
		{
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
