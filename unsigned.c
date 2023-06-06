/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 23:50:37 by renato            #+#    #+#             */
/*   Updated: 2023/06/06 14:40:51 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int n)
{
	unsigned int	num;
	int				len;

	num = 0;
	len = 0;
	if (n / 10)
	{
		len += ft_putunsigned((n / 10));
	}
	num = n % 10 + '0';
	len += write (1, &num, 1);
	return (len);
}
