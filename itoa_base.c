/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 21:11:37 by rseelaen          #+#    #+#             */
/*   Updated: 2023/06/06 18:42:39 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	intlen(int n, int base)
{	
	int	len;

	len = 0;
	if (n == 0)
	{
		len = 1;
		return (len);
	}
	while (n != 0)
	{
		n = n / base;
		len++;
	}
	return (len);
}

static char	*strwriter(char *str, int len, int n, int base)
{
	int		minus;
	char	*digits;

	digits = "0123456789abcdef";
	minus = 0;
	if (n < 0 && base == 10)
		minus = 1;
	while (len-- > minus)
	{
		if (n % base < 0)
			str[len] = digits[-(n % base)];
		else
			str[len] = digits[n % base];
		n = n / base;
	}
	return (str);
}

static char	*hex_case(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}

char	*ft_itoa_base(unsigned int n, int base, int caps)
{
	char	*str;
	int		len;
	int		minus;

	minus = 0;
	if (base != 16 && base != 10 && base != 8 && base != 2)
		return (0);
	len = intlen(n, base);
	if (n < 0)
		len = len + 1;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	if (n < 0)
		str[0] = '-';
	str[len] = '\0';
	strwriter(str, len, n, base);
	if (caps)
		hex_case(str);
	return (str);
}
