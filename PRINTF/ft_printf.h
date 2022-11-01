/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lancelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 12:41:29 by lancelot          #+#    #+#             */
/*   Updated: 2022/05/04 12:55:54 by lsaint-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdbool.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_choice(char choice, va_list lst);
int		ft_ptr(unsigned long n, bool check_upper, bool ptr);
int		ft_putnbr(int n);
int		ft_putnbr_unsigned(unsigned int n);

#endif
