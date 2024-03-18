/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:01:59 by msolinsk          #+#    #+#             */
/*   Updated: 2024/03/18 15:19:12 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_check_in_tab(char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_get_arg_count(char *str)
{
	int		count;
	char	*set;

	count = 0;
	set = (char *) malloc(sizeof(char) * 10);
	ft_strlcat(set, "cspdiuxX%", 10);
	printf("Set: %s\n", set);
	while (*str)
	{
		if (*str == '%' && ft_check_in_tab(set, *(str + 1)))
			count++;
		str++;
	}
	free(set);
	return (count);
}

int	ft_match(char c, va_list arg)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_char(va_arg(arg, int));
	else if (c == 's')
		len += ft_str(va_arg(arg, char *));
	else if (c == 'p')
		len += ft_pointer(va_arg(arg, void *));
	// else if (c == 'd')
	// 	ft_nbr((int)arg);
	// else if (c == 'i')
	// 	ft_base((char *)arg);
	// else if (c == 'u')
	// 	ft_unsigned((unsigned int)arg);
	// else if (c == 'x')
	// 	ft_hexup((int)arg);
	// else if (c == 'X')
	// 	ft_hexdown((int)arg);
	else if (c == '%')
		ft_putchar('%');
	return (len);
}

int	ft_printf(char *str, ...)
{
	int		total_len;
	int		n;
	char	*tmp;
	va_list	list;

	n = ft_get_arg_count(str);
	va_start(list, str);

	printf("Number of args: %d\n", n);

	while (*str)
	{
		if (n > 0)
		{
			tmp = ft_strchr((const char *)str, '%');
			// printf("tmp = %s\n", tmp);
			// printf("pointer delta: %ld\n", str - tmp);
			write(1, str, tmp - str);
			// printf("tmp[1] = %c | %s\n", tmp[1], tmp);
			total_len += ft_match(tmp[1], list);
			str = tmp + 2;
			n--;
		}
		else
		{
			write(1, str, ft_strlen(str));
			break ;
		}
	}

	va_end(list);
	// free(tmp);
	return (total_len);
}
