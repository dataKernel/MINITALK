/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choice.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lancelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 12:27:36 by lancelot          #+#    #+#             */
/*   Updated: 2022/05/04 10:08:24 by lancelot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "libft/libft.h"
#include "ft_printf.h"

/*
void	fill(char choice, va_list lst)
{
}
*/

int	ft_choice(char choice, va_list lst)
{
	char	*tmp;

	if (choice == 'c')
	{
		ft_putchar_fd(va_arg(lst, int), 1);
		return (1);
	}	
	else if (choice == 's')
	{
		tmp = va_arg(lst, char *);
		if (!tmp)
		{
			ft_putstr_fd("(null)", 1);
			return (6);
		}
		ft_putstr_fd(tmp, 1);
		return (ft_strlen(tmp));
	}
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
	else
		return (0);
}
