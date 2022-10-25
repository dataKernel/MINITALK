#include "PRINTF-master/ft_printf.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

struct  s_array
{
    int     tab[8];
    int     index;
};

struct s_array      payload;//struct globale pr update le tab côté server

static void    signal_handler(int signal)
{
	if(signal == SIGUSR1)
	{
    	payload.tab[payload.index] = 0;
    	payload.index++;//focus the array_index pos
	}
	if(signal == SIGUSR2)
	{
    	payload.tab[payload.index] = 1;
    	payload.index++;//focus the array_index pos
	}
}

char    morph_binaryArray_in_char(struct s_array payload)
{
    int     start_power_mul;
    int     result;
    int     i;

    start_power_mul = 128;
    result = 0;
    i = 0;
    while(i < 8)
    {
        if(payload.tab[i] == 1)
            result += start_power_mul;
        start_power_mul /= 2;
        i++;
    }
    return(result);
}

static int      ft_strlen(char *str)
{
    int     i;

	i = 0;
    while(str[i])
        i++;
    return(i);
}

void    ft_append_char(char **ptr, char c)
{
    char    *temp;
    int     size_str;
    int     i;

    i = 0;
    if(!*ptr)
    {
        *ptr = malloc(sizeof(char) * 2);
        (*ptr)[0] = c;
        (*ptr)[1] = '\0';
        return;
    }
    size_str = ft_strlen(*ptr);
    temp = malloc(sizeof(char) * (size_str + 2));
    while(i < size_str)
    {
        temp[i] = (*ptr)[i];
        i++;
    }
    temp[i] = c;
    temp[i + 1] = '\0';
    free(*ptr);
    *ptr = temp;
}

int     main(void)
{
    char    *str;
    int     pid;
    pid = getpid();
    str = NULL;
    printf("ID:: %i\n", pid); //printing pid_s
    //init de l'index de struct
    payload.index = 0;
    //def des signals
    signal(SIGUSR1, signal_handler);
    signal(SIGUSR2, signal_handler);
    while(1)
    {
        if(payload.index == 8)
        {
            ft_append_char(&str, morph_binaryArray_in_char(payload));
			if(morph_binaryArray_in_char(payload) == '\0')
            {
				ft_printf("%s\n", str);
                free(str);
                str = NULL;
            }
            payload.index = 0;
        }
        pause();
    }
    return(0);
}
