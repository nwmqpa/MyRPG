/*
** EPITECH PROJECT, 2017
** utils.h
** File description:
** utils header
*/

#ifndef UTILS_H_
#define UTILS_H_

#include <stddef.h>
#include <stdio.h>

#define UNUSED __attribute__((__unused__))

void *my_malloc(size_t size);
char **split_string(char const *str, char c);
void *my_calloc(size_t size);
int my_memcmp(char const *str1, char const *str2);
float get_dtime(float time);
int getline_w_n(char **line, long unsigned int *size, FILE *file);
char *string_from_file(char *path);

#endif /* UTILS_H_ */
