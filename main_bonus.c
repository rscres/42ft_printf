/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:56:59 by rseelaen          #+#    #+#             */
/*   Updated: 2023/06/07 20:45:31 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int len1 = 0;
	int len2 = 0;

	len1 = ft_printf("' %#x '", 10);
	printf("\n");
	len2 = printf("' %#x '", 10);
	printf("\n");
	printf("%d\n%d\n", len1, len2);
}
