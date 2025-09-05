#include "rush02.h"

int main_bonus(int argc, char **argv)
{
    char *dict_file = "numbers.dict";
    char *number_str;
    char *file_content;
    t_dict *dict;
    long long number;
    
    // Bonus: Handle no arguments (read from stdin)
    if (argc == 1)
    {
        return (process_stdin_mode(dict_file));
    }
    
    if (argc < 2 || argc > 3)
    {
        ft_putstr("Error\n");
        return (1);
    }
    
    if (argc == 3)
    {
        dict_file = argv[1];
        number_str = argv[2];
    }
    else
    {
        number_str = argv[1];
    }
    
    if (!is_valid_number(number_str))
    {
        ft_putstr("Error\n");
        return (1);
    }
    
    number = ft_atoll(number_str);
    
    file_content = read_file(dict_file);
    if (!file_content)
    {
        ft_putstr("Dict Error\n");
        return (1);
    }
    
    dict = parse_dictionary(file_content);
    free(file_content);
    
    if (!dict)
    {
        ft_putstr("Dict Error\n");
        return (1);
    }
    
    // Use bonus conversion with proper syntax
    if (!convert_number_bonus(number, dict))
    {
        ft_putstr("Dict Error\n");
        free_dict(dict);
        return (1);
    }
    
    ft_putchar('\n');
    free_dict(dict);
    return (0);
}

int main(int argc, char **argv)
{
    return (main_bonus(argc, argv));
}