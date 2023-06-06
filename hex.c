/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renato <renato@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 23:44:34 by renato            #+#    #+#             */
/*   Updated: 2023/06/05 23:45:09 by renato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, int caps)
{
	int	len;

	len = 1;
	if (n / 16)
	{
		len += ft_puthex(n / 16, caps);
	}
	if (caps)
		write (1, &HEX_CAPS[n % 16], 1);
	else
		write (1, &HEX_LOW[n % 16], 1);
	return (len);
}