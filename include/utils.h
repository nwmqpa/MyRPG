/*
** EPITECH PROJECT, 2017
** utils.h
** File description:
** utils header
*/

#ifndef UTILS_H_
#define UTILS_H_

#include <stddef.h>

void *my_malloc(size_t size);
int my_strlen(const char *str);
char *my_strdup(char const *str);
char *my_strcat(char *src1, char const *src2);
char **split_string(char const *str);
int my_atoi(char const *str);
void *my_calloc(size_t size);
float get_dtime(float time);

#endif /* UTILS_H_ */
