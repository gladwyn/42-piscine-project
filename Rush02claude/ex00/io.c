#include "rush02.h"

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int get_file_size(char *filename)
{
    int fd;
    char temp;
    int size = 0;
    
    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return (-1);
    
    while (read(fd, &temp, 1) > 0)
        size++;
    close(fd);
    
    return (size);
}

char *read_file_content(int fd, int size)
{
    char *buffer;
    int i = 0;
    
    buffer = malloc(size + 1);
    if (!buffer)
        return (NULL);
    
    while (read(fd, &buffer[i], 1) > 0)
        i++;
    buffer[i] = '\0';
    
    return (buffer);
}

char *read_file(char *filename)
{
    int fd;
    char *buffer;
    int size;
    
    size = get_file_size(filename);
    if (size == -1)
        return (NULL);
    
    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return (NULL);
    
    buffer = read_file_content(fd, size);
    close(fd);
    
    return (buffer);
}

char *trim_spaces(char *str)
{
    char *start = str;
    char *end;
    char *result;
    int len;
    int i = 0;
    
    // Skip leading spaces
    while (*start == ' ' || *start == '\t')
        start++;
    
    // Find end of string
    end = start;
    while (*end)
        end++;
    end--;
    
    // Skip trailing spaces
    while (end > start && (*end == ' ' || *end == '\t' || *end == '\n'))
        end--;
    
    len = end - start + 1;
    result = malloc(len + 1);
    if (!result)
        return (NULL);
    
    while (i < len)
    {
        result[i] = start[i];
        i++;
    }
    result[i] = '\0';
    return (result);
}