#ifndef RUSH02_H
# define RUSH02_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_dict
{
    long long key;
    char *value;
    struct s_dict *next;
} t_dict;

// utils.c
int ft_strlen(char *str);
char *ft_strdup(char *src);
long long ft_atoll(char *str);
int is_valid_number(char *str);
void ft_putstr(char *str);

// io.c
void ft_putchar(char c);
char *read_file(char *filename);
int get_file_size(char *filename);
char *read_file_content(int fd, int size);
char *trim_spaces(char *str);

// dict.c
t_dict *create_dict_node(long long key, char *value);
t_dict *parse_dictionary(char *content);
void free_dict(t_dict *dict);
char *find_value(t_dict *dict, long long key);
t_dict *add_to_dict(t_dict *dict, t_dict *new_node);

// convert.c
int convert_hundreds(long long num, t_dict *dict, int *first_word);
int convert_number(long long num, t_dict *dict);
int handle_large_numbers(long long *num, t_dict *dict, int *first_word);
int handle_remaining_hundreds(long long num, t_dict *dict, int *first_word);
char *get_power_value(t_dict *dict, long long power);

// convert_bonus.c - Bonus features
int should_add_and(long long num, long long remaining);
int should_add_comma(long long original_num, long long current_power);
int convert_hundreds_bonus(long long num, t_dict *dict, int *first_word, int add_and);
int handle_large_numbers_bonus(long long *num, t_dict *dict, int *first_word, long long original_num);
int convert_number_bonus(long long num, t_dict *dict);

// stdin.c - Standard input bonus
char *read_stdin_char(void);
char *read_from_stdin(void);
int is_stdin_valid(char *input);
void handle_stdin_input(t_dict *dict);
int process_stdin_mode(char *dict_file);

#endif