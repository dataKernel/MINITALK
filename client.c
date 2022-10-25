#include <stdio.h>
#include <unistd.h>
#include <signal.h>

static void    ft_putnbr_base(int *tab, int nbr, char *base)
{
    int     check_base;
    int     indice_tab;
    int     power_nbr;
    int     indice;

    indice_tab = 0;
    indice = 0;
    check_base = 0;
    while(base[check_base])
        check_base++;
    power_nbr = 128;
    while(power_nbr > 0)
    {
        indice = nbr / power_nbr % check_base;
        power_nbr /= check_base;
        tab[indice_tab] = base[indice] - 48;
        indice_tab++;
    }
}

static int      ft_atoi(char *str)
{
    int     result = 0;
    int     i;

    i = 0;
    while(str[i])
    {
        result *= 10;
        result += str[i] - '0';
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

static	void send_char(int pid, char c)
{
	int 	binary_array[8];
	int 	i;
	
	i = 0;
	ft_putnbr_base(binary_array, c, "01");
    while(i < 8)
	{
    	if(binary_array[i] == 0)
        	kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        i++;
        usleep(100);
    }
}

int     main(int argc, char **argv)
{
    int		i;

    i = 0;
    if(argc > 2)
    {
        while(i < ft_strlen(argv[2]))
        {
			send_char(ft_atoi(argv[1]), argv[2][i]);
            i++;
        }
		send_char(ft_atoi(argv[1]), '\0');
    }
    return(0);
}
