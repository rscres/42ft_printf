/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:18:22 by rseelaen          #+#    #+#             */
/*   Updated: 2023/06/07 14:54:04 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#define HEX_CAPS "0123456789ABCDEF"
#define HEX_LOW "0123456789abcdef"
#define DEC "0123456789"
#define OCT "01234567"
#define BIN "01"

int	ft_putnbr_base(int n, char *digits)
{
	int	len;
	int	base;

	len = 1;
	base = strlen(digits);
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
			len += 1;
		}
	}
	if (n / base)
		len += ft_putnbr_base((n / base), digits);
	write (1, &digits[n % base], 1);
	len++;
	return (len);
}

int main()
{
	ft_putnbr_base(1000, HEX_CAPS);
	ft_putnbr_base(1000, HEX_LOW);
	ft_putnbr_base(1000, DEC);
}