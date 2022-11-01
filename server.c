/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lancelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:31:52 by lancelot          #+#    #+#             */
/*   Updated: 2022/11/01 14:10:39 by lancelot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PRINTF/ft_printf.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

struct	s_array
{
	int		tab[8];
	int		index;
};

struct s_array	g_payload;

static int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static void	signal_handler(int signal)
{
	if (signal == SIGUSR1)
	{
		g_payload.tab[g_payload.index] = 0;
		g_payload.index++;
	}
	if (signal == SIGUSR2)
	{
		g_payload.tab[g_payload.index] = 1;
		g_payload.index++;
	}
}

static void	ft_append_char(char **ptr, char c)
{
	char	*temp;
	int		size_str;
	int		i;

	i = 0;
	if (!*ptr)
	{
		*ptr = malloc(sizeof(char) * 2);
		(*ptr)[0] = c;
		(*ptr)[1] = '\0';
		return ;
	}
	size_str = ft_strlen(*ptr);
	temp = malloc(sizeof(char) * (size_str + 2));
	while (i < size_str)
	{
		temp[i] = (*ptr)[i];
		i++;
	}
	temp[i] = c;
	temp[i + 1] = '\0';
	free(*ptr);
	*ptr = temp;
}

static char	morph_binary_array_in_char(struct s_array g_payload)
{
	int		start_power_mul;
	int		result;
	int		i;

	start_power_mul = 128;
	result = 0;
	i = 0;
	while (i < 8)
	{
		if (g_payload.tab[i] == 1)
			result += start_power_mul;
		start_power_mul /= 2;
		i++;
	}
	return (result);
}

int	main(void)
{
	char	*str;
	int		pid;

	pid = getpid();
	str = NULL;
	printf("ID:: %i\n", pid);
	g_payload.index = 0;
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
	{
		if (g_payload.index == 8)
		{
			ft_append_char(&str, morph_binary_array_in_char(g_payload));
			if (morph_binary_array_in_char(g_payload) == '\0')
			{
				ft_printf("%s\n", str);
				free(str);
				str = NULL;
			}
			g_payload.index = 0;
		}
		pause();
	}
	return (0);
}
