/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 15:21:51 by rseelaen          #+#    #+#             */
/*   Updated: 2023/06/07 16:05:26 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	unsigned int num = 2147483999;
	int x = 123456;
	void *p = &x;
	int hex = 0xffff7;
	int ft_len = 0;
	int std_len = 0;

	//CHAR TEST******************************
	ft_len = ft_printf("ft_char: %c\n", 'r');
	std_len = printf("std_char: %c\n", 'r');
	printf("ft: %d\nstd: %d\n", ft_len, std_len);

	//CHAR TEST #2******************************
	ft_len = 0;
	std_len = 0;
	ft_len = ft_printf("", "");
	std_len = printf("", "");
	printf("ft: %d\nstd: %d\n", ft_len, std_len);

	//STRING TEST****************************
	ft_len = 0;
	std_len = 0;
	ft_len = ft_printf("ft_string: %s\n","hello");
	std_len = printf("std_string: %s\n","hello");
	printf("ft: %d\nstd: %d\n", ft_len, std_len);

	//STRING TEST #2**************************
	ft_len = 0;
	std_len = 0;
	ft_len = ft_printf("ft_string: %s %s %s %s %s .\n", " - ", "", "4", "", "2 ");
	std_len = printf("std_string: %s %s %s %s %s .\n", " - ", "", "4", "", "2 ");
	printf("ft: %d\nstd: %d\n", ft_len, std_len);

	//STRING TEST #3**************************
	ft_len = 0;
	std_len = 0;
	ft_len = ft_printf("ft_string: NULL %s NULL \n", (char *)NULL);
	std_len = printf("std_string: NULL %s NULL \n", (char *)NULL);
	printf("ft: %d\nstd: %d\n", ft_len, std_len);

	//LOWERCASE HEX TEST**********************
	ft_len = 0;
	std_len = 0;
	ft_len = ft_printf("ft_hex(low): %x\n", num);
	std_len = printf("std_hex(low): %x\n", num);
	printf("ft: %d\nstd: %d\n", ft_len, std_len);

	//UPPERCASE HEX TEST**********************
	ft_len = 0;
	std_len = 0;
	ft_len = ft_printf("ft_hex(caps): %X\n", num);
	std_len = printf("std_hex(caps): %X\n", num);
	printf("ft: %d\nstd: %d\n", ft_len, std_len);

	//INT TEST********************************
	ft_len = 0;
	std_len = 0;
	ft_len = ft_printf("ft_int: %i\n", hex);
	std_len = printf("std_int: %i\n", hex);
	printf("ft: %d\nstd: %d\n", ft_len, std_len);

	//DECIMAL TEST*****************************
	ft_len = 0;
	std_len = 0;
	ft_len = ft_printf("ft_dec: %d\n", x);
	std_len = printf("std_dec: %d\n", x);
	printf("ft: %d\nstd: %d\n", ft_len, std_len);

	//% TEST***********************************
	ft_len = 0;
	std_len = 0;
	ft_len = ft_printf("ft_%%: %%\n");
	std_len = printf("std_%%: %%\n");
	printf("ft: %d\nstd: %d\n", ft_len, std_len);

	//POINTER TEST****************************
	ft_len = 0;
	std_len = 0;
	ft_len = ft_printf("ft_pointer: %p\n", p);
	std_len = printf("std_pointer: %p\n", p);
	printf("ft: %d\nstd: %d\n", ft_len, std_len);

	//POINTER TEST #2****************************
	ft_len = 0;
	std_len = 0;
	ft_len = ft_printf("ft_pointer: %p %p \n", (void *)LONG_MIN, (void *)LONG_MAX);
	std_len = printf("std_pointer: %p %p \n", (void *)LONG_MIN, (void *)LONG_MAX);
	printf("ft: %d\nstd: %d\n", ft_len, std_len);

	//POINTER TEST #3****************************
	ft_len = 0;
	std_len = 0;
	ft_len = ft_printf("ft_pointer: %p %p \n", (void *)INT_MIN, (void *)INT_MAX);
	std_len = printf("std_pointer: %p %p \n", (void *)INT_MIN, (void *)INT_MAX);
	printf("ft: %d\nstd: %d\n", ft_len, std_len);

	//POINTER TEST #4****************************
	ft_len = 0;
	std_len = 0;
	ft_len = ft_printf("ft_pointer: %p %p \n", (void *)ULONG_MAX, (void *)-ULONG_MAX);
	std_len = printf("std_pointer: %p %p \n", (void *)ULONG_MAX, (void *)-ULONG_MAX);
	printf("ft: %d\nstd: %d\n", ft_len, std_len);

	//POINTER TEST #5****************************
	ft_len = 0;
	std_len = 0;
	ft_len = ft_printf("ft_pointer: %p %p \n", 0, 0);
	std_len = printf("std_pointer: %p %p \n", 0, 0);
	printf("ft: %d\nstd: %d\n", ft_len, std_len);

	//NULL TEST************************************
	ft_len = 0;
	std_len = 0;
	printf("ft: ");
	ft_len = ft_printf(0, 0);
	printf("\nstd: ");
	std_len = printf(0, 0);
	printf("\nft: %d\nstd: %d\n", ft_len, std_len);
}
