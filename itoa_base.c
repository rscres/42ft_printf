/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 21:11:37 by rseelaen          #+#    #+#             */
/*   Updated: 2023/06/06 16:04:11 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	int	minus;

	minus = 0;
	if (n < 0)
		minus = 1;
	while (len-- > minus)
	{
		if (n % base < 0)
			str[len] = -(n % base) + '0';
		else
			str[len] = n % base + '0';
		n = n / 10;
	}
	return (str);
}

char	*ft_itoa(int n, int base)
{
	char	*str;
	int		len;
	int		minus;

	minus = 0;
	len = intlen(n);
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
	return (str);
}

int main()
{
	

	return (0);
}