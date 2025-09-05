#include "rush02.h"
char *get_power_value(t_dict *dict, long long power)
{
    return (find_value(dict, power));
}

int should_add_and(long long num, long long remaining)
{
    // Add "and" before tens/units if there were hundreds
    if (num >= 100 && remaining > 0 && remaining < 100)
        return (1);
    return (0);
}

int should_add_comma(long long original_num, long long current_power)
{
    // Add comma after large number groups (except the last group)
    if (original_num >= 1000 && current_power >= 1000)
    {
        long long remaining = original_num % current_power;
        if (remaining > 0)
            return (1);
    }
    return (0);
}

int convert_hundreds_bonus(long long num, t_dict *dict, int *first_word, int add_and)
{
    char *value;
    long long original_num = num;
    
    if (num >= 100)
    {
        value = find_value(dict, num / 100);
        if (!value)
            return (0);
        if (!*first_word)
            ft_putchar(' ');
        ft_putstr(value);
        *first_word = 0;
        
        value = find_value(dict, 100);
        if (!value)
            return (0);
        ft_putchar(' ');
        ft_putstr(value);
        num %= 100;
        
        if (add_and && should_add_and(original_num, num))
        {
            ft_putstr(" and");
        }
    }
    
    if (num >= 20)
    {
        value = find_value(dict, (num / 10) * 10);
        if (!value)
            return (0);
        if (!*first_word)
            ft_putchar(' ');
        ft_putstr(value);
        *first_word = 0;
        
        if (num % 10 > 0)
        {
            ft_putchar('-');
            value = find_value(dict, num % 10);
            if (!value)
                return (0);
            ft_putstr(value);
        }
        return (1);
    }
    else if (num >= 10)
    {
        value = find_value(dict, num);
        if (!value)
            return (0);
        if (!*first_word)
            ft_putchar(' ');
        ft_putstr(value);
        *first_word = 0;
        return (1);
    }
    
    if (num > 0)
    {
        value = find_value(dict, num);
        if (!value)
            return (0);
        if (!*first_word)
            ft_putchar(' ');
        ft_putstr(value);
        *first_word = 0;
    }
    
    return (1);
}

int handle_large_numbers_bonus(long long *num, t_dict *dict, int *first_word, long long original_num)
{
    long long powers[] = {1000000000000000000LL, 1000000000000000LL, 1000000000000LL, 1000000000LL, 1000000LL, 1000LL};
    int i = 0;
    char *value;
    
    while (i < 6)
    {
        if (*num >= powers[i])
        {
            if (!convert_hundreds_bonus(*num / powers[i], dict, first_word, 1))
                return (0);
            
            value = get_power_value(dict, powers[i]);
            if (!value)
                return (0);
            ft_putchar(' ');
            ft_putstr(value);
            
            if (should_add_comma(original_num, powers[i]))
                ft_putchar(',');
            
            *num %= powers[i];
        }
        i++;
    }
    
    return (1);
}

int convert_number_bonus(long long num, t_dict *dict)
{
    int first_word = 1;
    char *value;
    long long original_num = num;
    
    if (num == 0)
    {
        value = find_value(dict, 0);
        if (!value)
            return (0);
        ft_putstr(value);
        return (1);
    }
    
    if (!handle_large_numbers_bonus(&num, dict, &first_word, original_num))
        return (0);
    
    if (num > 0)
    {
        if (!convert_hundreds_bonus(num, dict, &first_word, 1))
            return (0);
    }
    
    return (1);
}