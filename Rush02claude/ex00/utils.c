#include "rush02.h"

int ft_strlen(char *str)
{
    int len = 0;
    while (str[len])
        len++;
    return (len);
}

char *ft_strdup(char *src)
{
    char *dup;
    int i = 0;
    int len = ft_strlen(src);
    
    dup = malloc(len + 1);
    if (!dup)
        return (NULL);
    while (i < len)
    {
        dup[i] = src[i];
        i++;
    }
    dup[i] = '\0';
    return (dup);
}

long long ft_atoll(char *str)
{
    long long result = 0;
    int i = 0;
    
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return (result);
}

int is_valid_number(char *str)
{
    int i = 0;
    
    if (!str || !str[0])
        return (0);
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

void ft_putstr(char *str)
{
    while (*str)
        write(1, str++, 1);
}