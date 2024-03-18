/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:24:35 by msolinsk          #+#    #+#             */
/*   Updated: 2024/03/18 15:24:00 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_pointer(void *p)
{
	char	*num;
	uintptr_t
	num = ft_int_to_hex(&p);
	return (ft_strlen(num));
}
