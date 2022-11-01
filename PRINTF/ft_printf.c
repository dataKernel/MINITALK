/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lancelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 21:34:52 by lancelot          #+#    #+#             */
/*   Updated: 2022/05/02 20:32:57 by lancelot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "libft/libft.h"
#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list		lst;
	int			i;
	int			count;

	va_start(lst, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += ft_choice(str[i + 1], lst);
			i += 2;
		}
		else if (str[i] != '\0')
		{
			ft_putchar_fd(str[i], 1);
			i++;
			count++;
		}
	}
	return (count);
}
