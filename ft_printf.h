/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:59:28 by msolinsk          #+#    #+#             */
/*   Updated: 2024/03/18 23:14:14 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>
#include <stdint.h>
#include "libft/libft.h"

int	ft_printf(char *str, ...);
int	ft_char(char c);
int	ft_str(char *str);
int	ft_pointer(unsigned long long p);
int	ft_hex(unsigned long long n, char form, int prefix);

#endif
