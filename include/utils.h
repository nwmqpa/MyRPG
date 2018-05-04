/*
** EPITECH PROJECT, 2017
** utils.h
** File description:
** utils header
*/

#ifndef UTILS_H_
#define UTILS_H_

#include <stddef.h>

int my_nblen(int nb);
void *my_malloc(size_t size);
int my_strlen(const char *str);
void *my_calloc(size_t size);
char *my_strdup(const char *);
int my_atoi(char const *str);
float get_dtime(float time);

#endif /* UTILS_H_ */
