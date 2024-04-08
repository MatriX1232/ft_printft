/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:18:04 by msolinsk          #+#    #+#             */
/*   Updated: 2024/04/08 12:17:57 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char	str[] = "Ola ma kota.";
	int	n = 987654;

	ft_printf("Test %%c  | %c", '@');
	printf(" | %c\n", '@');

	ft_printf("Test %%s  | %s", str);
	printf(" | %s\n", str);

	ft_printf("Test %%p  | %p", &str);
	printf(" | %p\n", &str);

	ft_printf("Test %%d  | %d", n);
	printf(" | %d\n", n);

	ft_printf("Test %%u | %u", n);
	printf(" | %u\n", n);

	ft_printf("Test %%x | %x", n);
	printf(" | %x\n", n);

	ft_printf("Test %%X | %X", n);
	printf(" | %X\n", n);

	ft_printf("Test %%");
	printf(" | %%\n");
	return (0);
}
