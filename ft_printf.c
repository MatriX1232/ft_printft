/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:01:59 by msolinsk          #+#    #+#             */
/*   Updated: 2024/04/08 12:17:23 by msolinsk         ###   ########.fr       */
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
	set = (char *) malloc(sizeof(char) * 13);
	ft_strlcat(set, "cspdiuxX%%", 14);
	while (*str)
	{
		if (*str == '%' && ft_check_in_tab(set, *(str + 1)))
			count++;
		if (*str == '%' && *(str + 1) == '%')
		{
			str++;
			count++;
		}
		str++;
	}
	free(set);
	return (count);
}

int	ft_match(char c, va_list arg)
{
	int	len;

	len = 0;
	// printf("ft_match >> %c\n", c);
	if (c == 'c')
		len += ft_char(va_arg(arg, int));
	else if (c == 's')
		len += ft_str(va_arg(arg, char *));
	else if (c == 'p')
		len += ft_hex(va_arg(arg, unsigned long long), 'x', 1);
	else if (c == 'd')
		ft_putnbr_fd(va_arg(arg, int), 1);
	else if (c == 'i')
		ft_putnbr_fd(va_arg(arg, unsigned int), 1);
	else if (c == 'u')
		ft_putnbr_fd(va_arg(arg, unsigned int), 1);
	else if (c == 'X')
		len += ft_hex(va_arg(arg, unsigned int), 'X', 0);
	else if (c == 'x')
		len += ft_hex(va_arg(arg, unsigned int), 'x', 0);
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
			write(1, str, tmp - str);
			total_len += ft_match(tmp[1], list);
			str = tmp + 2;
			if (*str == '%')
				str++;
			if (tmp[1] != '%')
				n--;
		}
		else
		{
			write(1, str, ft_strlen(str));
			break ;
		}
	}

	va_end(list);
	return (total_len);
}
