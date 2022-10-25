#include <stdio.h>
#include <unistd.h>

int     ft_strlen(char *str)
{
    int     index;

    index = 0;
    while(str[index])
        index++;
    return(index);
}

void    ft_reverse_str(char *str, char *tab, int sizeTab)
{
    int     indexStr;
    int     indexTab;

    indexTab = 0;
    indexStr = sizeTab - 1; //(-1 for index pos)
    while(indexTab < sizeTab)
    {
        tab[indexTab] = str[indexStr];
        indexStr--;
        indexTab++;
    }
	tab[sizeTab] = '\0';
}

int     main(void)
{
    char    *str;
    int     sizeTab;

    str = "lancelot\0";
    sizeTab = ft_strlen(str);
    char    tab[sizeTab + 1];
    ft_reverse_str(str, tab, sizeTab);
    //check datas
    printf("%s\n", tab);
    return(0);
}
