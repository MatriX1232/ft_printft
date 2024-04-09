/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:18:04 by msolinsk          #+#    #+#             */
/*   Updated: 2024/04/09 19:59:16 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <stdint.h>

int	main(void)
{
	char	str[] = "Ola ma kota.";
	int		n = 987654;
	// int		total_len;

	// printf("INT MIN = %d\n", INT_MIN);
	printf("INT MAX =		 %d\n", INT_MAX);
	printf("UNSIGNED INT MAX =	 %u\n", UINT_MAX);
	printf("UNSIGNED INT MIN =	 %u\n", UINT32_MAX);

	ft_printf("Test %%c  | %c\n", '@');
	printf("Test %%c  | %c\n", '@');
	// printf(" | %c\n", '@');

	ft_printf("Test %%s  | %s\n", str);
	printf("Test %%s  | %s\n", str);
	// printf(" | %s\n", str);

	ft_printf("Test %%p  | %p\n", &str);
	printf("Test %%p  | %p\n", &str);
	// printf(" | %p\n", &str);

	ft_printf("Test %%d  | %d\n", n);
	printf("Test %%d  | %d\n", n);
	// printf(" | %d\n", n);

	ft_printf("Test %%i  | %i\n", n);
	printf("Test %%i  | %i\n", n);
	// printf(" | %i\n", n);

	ft_printf("Test %%u  | %u\n", n);
	printf("Test %%u  | %u\n", n);
	// printf(" | %u\n", n);

	ft_printf("Test %%x  | %x\n", n);
	printf("Test %%x  | %x\n", n);
	// printf("  | %x\n", n);

	ft_printf("Test %%X  | %X\n", n);
	printf("Test %%X  | %X\n", n);
	// printf("  | %X\n", n);

	ft_printf("Test  %%\n");
	printf("Test  %%\n");
	// printf("  | %%\n");
	return (0);
}
