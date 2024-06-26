/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:19:36 by msolinsk          #+#    #+#             */
/*   Updated: 2024/04/11 15:37:35 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_uint(unsigned int n, int *len)
{
	if (n >= 10)
		ft_uint(n / 10, len);
	*len += ft_char(n % 10 + '0');
}
