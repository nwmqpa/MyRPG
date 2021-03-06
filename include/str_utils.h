/*
** EPITECH PROJECT, 2017
** str_utils.h
** File description:
** str utils
*/

#ifndef STR_UTILS_H_
#define STR_UTILS_H_

void my_putstr(const char *str);
int my_strlen(const char *str);
int my_strcmp(const char *dest, const char *str);
int my_strsize(const char *str);
char *my_strcat(char *dest, char const *str);
char *my_strcpy(char *dest, char *str);
char *my_strdup(const char *str);
char *str_swipe(char *ret, int where, int offset);
char *change_tilde_home(char *str, char *home);
int my_atoi(char const *str);
char *my_itoa(int nbr);
void my_memcpy(char *str1, char const *str2, int len);
int find_next(char const *mem, char c);
char *my_revstr(char *str);
char *str_append(char *str, char c);

#endif /* STR_UTILS_H */
