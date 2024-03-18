/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:42:33 by msolinsk          #+#    #+#             */
/*   Updated: 2024/03/18 15:20:08 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hex_len(int n)
{
	int	len;

	len = 0;
	if (n < 0)
		len++;
	while (n > 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

static int	ft_flag_ret(int *n, char *num)
{
	if (*n == INT_MIN)
	{
		ft_strlcat(num, "-2", 3);
		*n = 147483647;
		return (2);
	}
	else if (*n < 0)
	{
		num[0] = '-';
		*n *= (-1);
		return (1);
	}
	return (0);
}

char	*ft_int_to_hex(int n)
{
	int		i;
	int		flag;
	char	*num;

	i = ft_hex_len(n) - 1;
	num = (char *) malloc(sizeof(char) * (ft_hex_len(n) + 1));
	flag = ft_flag_ret(&n, num);
	num[i--] = '\0';
	while (n > 0)
	{
		num[i--] = "0123456789ABCDEF"[n % 16];
		n = n / 16;
	}
	return (num);
}
