/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lancelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:33:45 by lancelot          #+#    #+#             */
/*   Updated: 2022/05/02 20:17:04 by lancelot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "libft/libft.h"
#include "ft_printf.h"

static int	size_long(unsigned long n)
{
	int		i;

	i = 0;
	while (n > 0 || n < 0)
	{
		n /= 16;
		i++;
	}
	if (i == 0)
		i = 1;
	return (i);
}

int	ft_ptr(unsigned long n, bool base_upper, bool ptr)
{
	char	*base_16;
	char	str[17];
	int		size_str;
	int		i;

	if (base_upper == false)
		base_16 = "0123456789abcdef";
	else
		base_16 = "0123456789ABCDEF";
	size_str = size_long(n) - 1;
	i = size_str;
	str[i + 1] = '\0';
	while (i >= 0)
	{
		str[i] = base_16[n % 16];
		n /= 16;
		i--;
	}
	if (ptr == true)
		write(1, "0x", 2);
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}
