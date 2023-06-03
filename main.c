/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 15:21:51 by rseelaen          #+#    #+#             */
/*   Updated: 2023/06/02 19:24:00 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

int	main(void)
{
	unsigned int num = 2147483999;
	int x = 123456;
	void *p = &x;

	ft_printf("here %c %s there %X %x %i %u %% %p\n", 'r', "hello", 1000, 0xffff7, num, num, p);
	printf("here %c %s there %X %x %i %u %% %p\n", 'r', "hello", 1000, 0xffff7, num, num, p);
}
