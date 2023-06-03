/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 15:16:54 by rseelaen          #+#    #+#             */
/*   Updated: 2023/06/02 20:56:54 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdarg.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

void	ft_putnbr(long int n)
{
	long int	x;

	x = 0;
	if (n == -2147483648)
	{
		write(1, "-2", 2);
		n = 147483648;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	if (n / 10)
	{
		ft_putnbr((n / 10));
	}
	x = n % 10 + '0';
	write (1, &x, 1);
}

void	ft_puthex(int n, int caps)
{
	if (n / 16)
	{
		ft_puthex(n / 16, caps);
	}
	if (caps)
		write (1, &HEX_CAPS[n % 16], 1);
	else
		write (1, &HEX_LOW[n % 16], 1);
}

// void	put_address(void *p)
// {
// 	char *str;

// 	str = (char *)p;
// 	while (*str != '\0')
// 	{
// 		ft_putchar(*str);
// 		str++;
// 	}
// }

void printPointerAddress(void* ptr) {
    // Do something with the pointer address
    // Here, we'll simply print it character by character
    char* address = (char*)&ptr;
	ft_puthex((int )address,);
    while (*address != '\0') {
        ft_putchar(*address);
        address++;
    }
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	char	*temp;

	i = 0;
	temp = (char *)str;
	va_start(args, str);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			if (*(str + 1) == 'c')
				ft_putchar(va_arg(args, int));
			else if (*(str + 1) == 's')
				ft_putstr(va_arg(args, char *));
			else if (*(str + 1) == 'p')
				printPointerAddress(va_arg(args, void *));
			else if (*(str + 1) == 'i')
				ft_putnbr(va_arg(args, int));
			else if (*(str + 1) == 'u')
				ft_putnbr(va_arg(args, unsigned int));
			else if (*(str + 1) == 'X')
				ft_puthex(va_arg(args, int), 1);
			else if (*(str + 1) == 'x')
				ft_puthex(va_arg(args, int), 0);
			else if (*(str + 1) == '%')
				write(1, "%", 1);
			str++;
		}
		else
			ft_putchar(*str);
		str++;
	}
	va_end(args);

	return (0);
}
