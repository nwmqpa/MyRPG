/*
** EPITECH PROJECT, 2017
** sources/utils/my_strcat.c
** File description:
** my_strcat
*/

#include <stdlib.h>
#include "utils.h"
#include "str_utils.h"

char *my_strcat(char *str1, char const *str2)
{
	int len1 = my_strlen(str1);
	int len2 = my_strlen(str2);
	char *new = my_calloc(len1 + len2 + 2);

	my_memcpy(new, str1, len1);
	free(str1);
	my_memcpy(new + len1, str2, len2);
	return (new);
}

char *str_append(char *str1, char const c)
{
	int len = str1 ? my_strlen(str1) : 0;
	char *new = my_calloc(len + 3);

	my_memcpy(new, len ? str1 : "", len);
	new[len] = c;
	return (new);
}