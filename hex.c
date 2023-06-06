/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 23:44:34 by renato            #+#    #+#             */
/*   Updated: 2023/06/06 14:15:49 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, int caps)
{
	int	len;

	len = 1;
	if (n / 16)
		len += ft_puthex(n / 16, caps);
	if (caps)
		write (1, &HEX_CAPS[n % 16], 1);
	else
		write (1, &HEX_LOW[n % 16], 1);
	return (len);
}

int	ft_putpointer(unsigned long int n, int flag)
{
	int	len;

	len = 1;
	if (n == 0)
	{
		write(1, "(nil)", 5);
		return (len = 5);
	}
	if (flag == 1)
	{
		write(1, "0x", 2);
		len += 2;
		flag = 0;
	}
	if (n / 16)
		len += ft_putpointer(n / 16, flag);
	write (1, &HEX_LOW[n % 16], 1);
	return (len);
}
