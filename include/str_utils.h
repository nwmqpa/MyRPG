/*
** EPITECH PROJECT, 2017
** str_utils.h
** File description:
** str utils
*/

#ifndef STR_UTILS_H_
#define STR_UTILS_H_

void my_putstr(const char *str);
int my_strcmp(const char *dest, const char *str);
int my_strsize(const char *str);
char *my_strcat(char *dest, char *str);
char *my_strcpy(char *dest, char *str);
char *my_strdup(const char *str);
char *str_swipe(char *ret, int where, int offset);
char *change_tilde_home(char *str, char *home);
int my_atoi(char const *str);
char *my_itoa(int nbr);

#endif /* STR_UTILS_H */
