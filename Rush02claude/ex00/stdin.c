#include "rush02.h"

char *read_stdin_char(void)
{
    char c;
    char *buffer;
    int size = 0;
    int capacity = 100;
    int i = 0;
    
    buffer = malloc(capacity);
    if (!buffer)
        return (NULL);
    
    while (read(0, &c, 1) > 0)
    {
        if (c == '\n')
            break;
        
        if (size >= capacity - 1)
        {
            capacity *= 2;
            char *new_buffer = malloc(capacity);
            if (!new_buffer)
            {
                free(buffer);
                return (NULL);
            }
            while (i < size)
            {
                new_buffer[i] = buffer[i];
                i++;
            }
            free(buffer);
            buffer = new_buffer;
            i = 0;
        }
        
        buffer[size++] = c;
    }
    
    buffer[size] = '\0';
    return (buffer);
}

char *read_from_stdin(void)
{
    return (read_stdin_char());
}

int is_stdin_valid(char *input)
{
    if (!input || !input[0])
        return (0);
    return (is_valid_number(input));
}

void handle_stdin_input(t_dict *dict)
{
    char *input;
    long long number;
    
    input = read_from_stdin();
    if (!input)
    {
        ft_putstr("Error\n");
        return;
    }
    
    if (!is_stdin_valid(input))
    {
        ft_putstr("Error\n");
        free(input);
        return;
    }
    
    number = ft_atoll(input);
    
    if (!convert_number_bonus(number, dict))
        ft_putstr("Dict Error\n");
    else
        ft_putchar('\n');
    
    free(input);
}

int process_stdin_mode(char *dict_file)
{
    char *file_content;
    t_dict *dict;
    
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
    
    handle_stdin_input(dict);
    free_dict(dict);
    return (0);
}