#include "push_swap.h"

long ft_atoi(const char *str)
{
    long result = 0;
    int sign = 1;
    int i = 0;

    if (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i])
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return result * sign;
}