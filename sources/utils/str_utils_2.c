/*
** EPITECH PROJECT, 2017
** str_utils_2.c
** File description:
** str utils functions
*/

#include "str_utils.h"
#include "utils.h"

int my_strlen(const char *str)
{
	int i = -1;

	while (str[++i]);
	return (i);
}

char *str_swipe(char *str, int where, int offset)
{
	int i = where;

	while (str[i + offset] != '\0') {
		str[i] = str[i + offset];
		i++;
	}
	str[i] = 0;
	return (str);
}

