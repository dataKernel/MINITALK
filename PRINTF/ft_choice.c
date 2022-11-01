/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choice.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lancelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 12:27:36 by lancelot          #+#    #+#             */
/*   Updated: 2022/05/04 12:36:02 by lsaint-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "libft/libft.h"
#include "ft_printf.h"

static int	ft_print_str(char *tmp)
{
	if (!tmp)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(tmp, 1);
	return (ft_strlen(tmp));
}

int	ft_choice(char choice, va_list lst)
{
	if (choice == 'c')
	{
		ft_putchar_fd(va_arg(lst, int), 1);
		return (1);
	}	
	else if (choice == 's')
		return (ft_print_str(va_arg(lst, char *)));
	else if (choice == 'i' || choice == 'd')
		return (ft_putnbr(va_arg(lst, int)));
	else if (choice == 'u')
		return (ft_putnbr_unsigned(va_arg(lst, unsigned int)));
	else if (choice == 'p')
		return (ft_ptr(va_arg(lst, unsigned long), false, true) + 2);
	else if (choice == 'x')
		return (ft_ptr(va_arg(lst, unsigned int), false, false));
	else if (choice == 'X')
		return (ft_ptr(va_arg(lst, unsigned int), true, false));
	else if (choice == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	return (0);
}
