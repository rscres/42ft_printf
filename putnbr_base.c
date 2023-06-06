/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:18:22 by rseelaen          #+#    #+#             */
/*   Updated: 2023/06/06 18:48:14 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(int n, int base, int caps)
{
	int		len;
	char	*digits;

	digits = "0123456789abcdef";
	len = 0;
	if (base == 10)
	{
		if (n == -2147483648)
		{
			write(1, "-2", 2);
			n = 147483648;
			len += 2;
		}
		if (n < 0)
		{
			len += write(1, "-", 1);
			n *= -1;
		}
	}
	if (base == 16 && caps == 1)
		digits = "0123456789ABCDEF";
	if (n / base)
		len += ft_putnbr_base((n / base), 16, caps);
	len += write (1, &digits[n % base], 1);
	return (len);
}
