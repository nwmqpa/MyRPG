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
void *my_calloc(size_t size);
char *get_home(char *env[]);

#endif /* UTILS_H_ */
