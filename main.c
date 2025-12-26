#include <stdio.h>
#include "lib_ft/libft.h"

void leaks()
{
    system("leaks a.out");
}
int ft_len(char *str)
{
    if(!str)
        return 0;
    int len = 0;
    while(str[len])
        len++;
    return len;
}

int is_not_nb(char *str_nbr)
{
    if (!(*str_nbr == '+' || *str_nbr == '-' || (*str_nbr >= '0' && *str_nbr <= '9')))
        return (1);
    if ((*str_nbr == '+' || *str_nbr == '-') && !(str_nbr[1] >= '0' && str_nbr[1] <= '9'))
        return (1);
    while (*++str_nbr)
    {
        if (!(*str_nbr >= '0' && *str_nbr <= '9'))
            return (1);
    }
    return (0);
}
/*
int is_not_nb(char *str)
{
    int i = 0;

    if (str[i] == '-' || str[i] == '+')
        i++;
    while (str[i])
    {
        if (!(str[i] >= '0' && str[i] <= '9'))
        {
            return 0;
        }
        i++;
    }
    return 1;
}*/
int main(int ac, char **av)
{
    // atexit(leaks);
    if (ac < 2)
        return 0;

    int j = 1;
    while (ac > j)
    {
        int i = 0;
        char **args = ft_split(av[j]);
        while (args[i])
        {
            if (is_not_nb(av[j]) == 1)
            {
                printf("Error\n");
                return 0;
            }
            else
            {
                printf("%s\n", args[i]);
                free(args[i]);
            }
            i++;
        }
        free(args);
        j++;
    }
}
