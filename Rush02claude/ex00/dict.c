#include "rush02.h"

t_dict *create_dict_node(long long key, char *value)
{
    t_dict *node = malloc(sizeof(t_dict));
    if (!node)
        return (NULL);
    
    node->key = key;
    node->value = ft_strdup(value);
    node->next = NULL;
    return (node);
}

t_dict *add_to_dict(t_dict *dict, t_dict *new_node)
{
    t_dict *current;
    
    if (!dict)
        return (new_node);
    
    current = dict;
    while (current->next)
        current = current->next;
    current->next = new_node;
    
    return (dict);
}

t_dict *parse_dictionary(char *content)
{
    t_dict *dict = NULL;
    char *line_start = content;
    char *line_end;
    char *colon_pos;
    long long key;
    char *value;
    char *trimmed_value;
    
    while (*line_start)
    {
        // Find end of current line
        line_end = line_start;
        while (*line_end && *line_end != '\n')
            line_end++;
        
        // Skip empty lines
        if (line_end == line_start)
        {
            line_start = line_end + 1;
            continue;
        }
        
        // Find colon
        colon_pos = line_start;
        while (colon_pos < line_end && *colon_pos != ':')
            colon_pos++;
        
        if (colon_pos < line_end)
        {
            *colon_pos = '\0';
            *line_end = '\0';
            
            key = ft_atoll(line_start);
            value = colon_pos + 1;
            trimmed_value = trim_spaces(value);
            
            if (trimmed_value)
            {
                t_dict *new_node = create_dict_node(key, trimmed_value);
                free(trimmed_value);
                dict = add_to_dict(dict, new_node);
            }
        }
        
        line_start = line_end + 1;
    }
    
    return (dict);
}

void free_dict(t_dict *dict)
{
    t_dict *tmp;
    
    while (dict)
    {
        tmp = dict;
        dict = dict->next;
        if (tmp->value)
            free(tmp->value);
        free(tmp);
    }
}

char *find_value(t_dict *dict, long long key)
{
    while (dict)
    {
        if (dict->key == key)
            return (dict->value);
        dict = dict->next;
    }
    return (NULL);
}