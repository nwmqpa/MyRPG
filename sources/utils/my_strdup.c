/*
** EPITECH PROJECT, 2017
** sources/utils/my_strdup.c
** File description:
** My str duplication func
*/

#include "utils.h"
#include "str_utils.h"

char *my_strdup(char const *str)
{
	char *new = my_calloc(my_strlen(str) + 1);

	my_memcpy(new, str, my_strlen(str));
	return (new);
}