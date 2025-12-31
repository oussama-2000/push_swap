#include "push_swap.h"


int is_space(char c)
{
    return (c == 32);
}

size_t ft_count_words(const char *s)
{
    size_t i;
    size_t count;
    int in_word;

    i = 0;
    count = 0;
    in_word = 0;
    while (s[i])
    {
        if (!is_space(s[i]) && in_word == 0)
        {
            in_word = 1;
            count++;
        }
        else if (is_space(s[i]))
            in_word = 0;
        i++;
    }
    return (count);
}

void ft_free_all(char **arr, size_t n)
{
    while (n > 0)
    {
        n--;
        free(arr[n]);
    }
    free(arr);
}

int ft_alloc(char ***res, const char *s)
{
    if (!s)
        return (0);
    *res = malloc((ft_count_words(s) + 1) * sizeof(char *));
    if (!*res)
        return (0);
    return (1);
}

int ft_sub(char **res, const char *s, size_t start, size_t len)
{
    *res = ft_substr(s, start, len);
    if (!*res)
        return (0);
    return (1);
}

char **ft_split(char const *s)
{
    char **res;
    size_t i;
    size_t j;
    size_t start;

    i = 0;
    j = 0;
    if (!ft_alloc(&res, s))
        return (NULL);
    while (s[i])
    {
        while (s[i] && is_space(s[i]))
            i++;
        if (s[i])
        {
            start = i;
            while (s[i] && !is_space(s[i]))
                i++;
            if (!ft_sub(&res[j], s, start, i - start))
                return (ft_free_all(res, j), NULL);
            j++;
        }
    }
    res[j] = NULL;
    return (res);
}
